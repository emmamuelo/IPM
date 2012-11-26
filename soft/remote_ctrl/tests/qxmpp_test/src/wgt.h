
#ifndef __WGT_H_
#define __WGT_H_

#include <QtGui>
#include "ui_wgt.h"
#include "peer_qxmpp.h"

struct lua_State;

class Wgt: public QWidget
{
    Q_OBJECT
public:
   Wgt( QWidget * parent = 0 );
   ~Wgt();
   
   void init( lua_State * L );
   int  print( lua_State * L );

   void log( const std::string & stri );
signals:
    void sigLog( const QString & stri );
private slots:
    void connectHost();
    void registerClient();
    void send();
    void sendFile();
    void status();
    void clear();
    void slotLog( const QString & stri );
public:
    // Message and event handlers...
    void messageHandler( const std::string & client, const std::string & stri );
    void logHandler( const std::string & stri );
    QIODevice * inFileHandler( const std::string & fileName );
    void accFileHandler( const std::string & fileName, QIODevice * device );
private:
    Ui_Wgt ui;
    PeerQxmpp * xmpp;
public:
    static const std::string WGT_ID;
};


#endif




