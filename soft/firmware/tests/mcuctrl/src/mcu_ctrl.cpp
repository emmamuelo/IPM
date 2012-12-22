
#include "mcu_ctrl.h"
#include <sstream>
#include <boost/regex.hpp>

McuCtrl::McuCtrl()
: UsbIo()
{

}

McuCtrl::~McuCtrl()
{

}

bool McuCtrl::inputs( unsigned long * data, int len )
{
    std::string stri = "st\r\n";
    int cntWr = write( stri );
    int cntRd = read( stri );
    // Here it should be output parser.
    return true;
}

bool McuCtrl::setOutputs( unsigned long * data, int len )
{
    std::ostringstream out;
    out << "out ";
    for ( int i=0; i<len; i++ )
    {
        out << data[i];
        if ( i < (len-1) )
            out << " ";
    }
    out << "\r\n";
    int cntWr = write( out.str() );
    std::string stri;
    stri.resize( 64 );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::powerOffReset()
{
	std::string stri = "pwrrst\r\n";
	int cntWr = write( stri );
	int cntRd = read( stri );
	return ( cntRd >= cntWr );
}

bool McuCtrl::powerConfig( int onFirst, int onRegular, int off )
{
    std::ostringstream out;
    out << "powercfg " << onFirst << " " << onRegular << " " << off << "\r\n";
    std::string stri = out.str();
    int cntWr = write( stri );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::powerEn( bool en )
{
    std::ostringstream out;
    out << "pwren ";
    out << ( en ) ? "1" : "0";
    out << "\r\n";
    std::string stri = out.str();
    int cntWr = write( stri );
    int cntRd = read( stri );
    return ( ( cntWr > 0) && ( cntRd >= cntWr ) );
}

bool McuCtrl::motoConfig( bool en, int val )
{
    std::ostringstream out;
    out << "motocfg ";
    out << (en) ? '1' : '0';
    out << " ";
    out << val;
    out << "\r\n";
    std::string stri = out.str();
    int cntWr = write( stri );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::motoSet( bool moto1, bool moto2, bool moto3, bool moto4 )
{
    std::ostringstream out;
    out << "motoset ";
    out << ( moto1 ? '1' : '0' );
    out << ( moto2 ? '1' : '0' );
    out << ( moto3 ? '1' : '0' );
    out << ( moto4 ? '1' : '0' );
    out << "\r\n";
    std::string stri = out.str();
    int cntWr = write( stri );
    int cntRd = read( stri );
    return ( ( cntWr >= 0 ) && ( cntRd >= cntWr ) );
}

bool McuCtrl::motoReset()
{
    std::ostringstream out;
    out << "motorst\r\n";
    std::string stri = out.str();
    int cntWr = write( stri );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::moto( int & val )
{
    std::ostringstream out;
    out << "motorst\r\n";
    std::string stri = out.str();
    int cntWr = write( stri );
    int cntRd = read( stri );
    bool res = ( ( cntWr > 0 ) && ( cntRd >= cntWr ) );
    if ( !res )
        return false;

    boost::regex patt( "\\{ {0,}\\d+" );
    boost::sregex_iterator it( stri.begin(), stri.end(), patt );
    boost::sregex_iterator end;
    for ( ; it!=end; ++it )
    {
        //std::cout << it->str() << "\n";
        std::string ss = it->str().substr( 1 );
        std::istringstream in( ss );
        in >> val;
        return true;
    }
    return false;
}

bool McuCtrl::led( bool en )
{
    std::ostringstream out;
    out << "led ";
    out << (en) ? '1' : '0';
    out << "\r\n";
    std::string stri = out.str();
    int cntWr = write( stri );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::adcConfig( bool en )
{
    std::ostringstream out;
    out << "adccfg ";
    out << (en) ? '1' : '0';
    out << "\r\n";
    std::string stri = out.str();
    int cntWr = write( stri );
    int cntRd = read( stri );
    return ( cntRd >= cntWr );
}

bool McuCtrl::adc( int & battery, int & solar )
{
    std::ostringstream out;
    out << "adc\r\n";
    std::string text = out.str();
    int cntWr = write( text );
    int cntRd = read( text );
    bool res = ( ( cntWr > 0 ) && ( cntRd >= cntWr ) );
    battery = -1;
    solar   = -1;
    if ( !res )
        return false;
    // Get values from result string. Values are between "{" and "}".
    {
        boost::regex patt( "\\{ {0,}\\d+" );
        boost::sregex_iterator it( text.begin(), text.end(), patt );
        boost::sregex_iterator end;
        for ( ; it!=end; ++it )
        {
            //std::cout << it->str() << "\n";
            std::string stri = it->str().substr( 1 );
            std::istringstream in( stri );
            in >> battery;
        }
    }
    {
        boost::regex patt( "\\d+ {0,}\\}" );
        boost::sregex_iterator it( text.begin(), text.end(), patt );
        boost::sregex_iterator end;
        for ( ; it!=end; ++it )
        {
            //std::cout << it->str() << "\n";
            std::string stri = it->str();
            std::istringstream in( stri );
            in >> solar;
        }
    }
    //std::cout << "battery: " << battery   << "\n";
    //std::cout << "solar:   " << solar << "\n";

    return res;
}







