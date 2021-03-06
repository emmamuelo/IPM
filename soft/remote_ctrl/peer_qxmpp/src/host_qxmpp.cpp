
#include "host_qxmpp.h"

#include "QXmppLogger.h"
#include "QXmppPasswordChecker.h"
#include "QXmppServer.h"

#include <iostream>
#include <sstream>
#include <boost/bind.hpp>
#include <boost/bind/placeholders.hpp>

#include <boost/property_tree/ini_parser.hpp>
//#include <boost/property_tree/xml_parser.hpp>
//#include <boost/property_tree/json_parser.hpp>
//#include <boost/property_tree/info_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>


class HostQxmpp::PD: public QObject, public QXmppPasswordChecker
{
public:
    PD( QObject * parent = 0 )
        : QObject( parent )
    {}
    ~PD()
    {}
    QXmppPasswordReply::Error getPassword( const QXmppPasswordRequest & request, QString & password );
    bool hasGetPassword() const;

    bool parseConfig( const std::string & fileName );

    QXmppServer server;
    QXmppLogger logger;
    QString     domain;
    QHash<QString, QString> clientList;
};

QXmppPasswordReply::Error HostQxmpp::PD::getPassword( const QXmppPasswordRequest & request, QString & password )
{
    QHash<QString, QString>::const_iterator it = clientList.find( request.username() );
    if ( it == clientList.end() )
        return QXmppPasswordReply::AuthorizationError;
    password = it.value();
    return QXmppPasswordReply::NoError;
}

bool HostQxmpp::PD::hasGetPassword() const
{
    return true;
}

bool HostQxmpp::PD::parseConfig( const std::string & fileName )
{
    clientList.clear();
    boost::property_tree::ptree config;
    try
    {
        boost::property_tree::read_ini( fileName, config );

        //const boost::property_tree::ptree & sect = config.get_child( "main" );
        for ( boost::property_tree::ptree::iterator i=config.begin(); i!=config.end(); i++ )
        {
            std::string key = i->first;
            boost::property_tree::ptree sect = config.get_child( key );

            bool host = sect.get<bool>( "host", false );
            if ( host )
                domain = QString::fromStdString( sect.get<std::string>( "domain", "qxmpp" ) );
            else
            {
                QString login    = QString::fromStdString( sect.get<std::string>( "login", "login" ) );
                QString password = QString::fromStdString( sect.get<std::string>( "password", "password" ) );
                clientList[ login ] = password;
            }
        }
    }
    catch ( boost::property_tree::ini_parser_error & error )
    {
        std::cout << error.message() << ": " << error.filename() << ", line "
            << error.line() << std::endl;
        return false;
    }
    return true;
}

HostQxmpp::HostQxmpp()
{
    pd = new PD();
}

HostQxmpp::~HostQxmpp()
{
    pd->deleteLater();
}

bool HostQxmpp::listen( const std::string & configFile )
{
    if ( !pd->parseConfig( configFile ) )
        return false;
    pd->server.setDomain( pd->domain );
    pd->logger.setLoggingType( QXmppLogger::StdoutLogging );
    pd->server.setLogger( &(pd->logger) );
    pd->server.setPasswordChecker( pd );
    pd->server.listenForClients();
    pd->server.listenForServers();
    return true;
}







