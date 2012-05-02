
#ifndef __FACTORY_ICE_
#define __FACTORY_ICE_

module Factory
{
    sequence<string> TStringArray;

    interface Device
    {
        string status();
        void   release();
    };

    interface DeviceFactory
    {
        idempotent TStringArray interfaces();
        Device * query( string interfaceName );
    };
};



#endif



