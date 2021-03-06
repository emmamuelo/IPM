// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice-E is licensed to you under the terms described in the
// ICEE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice-E version 1.3.0
// Generated from file `manipulator.ice'

#ifndef __manipulator_h__
#define __manipulator_h__

#include <IceE/ProxyF.h>
#include <IceE/ObjectF.h>
#include <IceE/Exception.h>
#include <IceE/ScopedArray.h>
#include <IceE/Proxy.h>
#include <IceE/Object.h>
#ifndef ICEE_PURE_CLIENT
#  include <IceE/Incoming.h>
#endif
#include <IceE/Outgoing.h>
#include <C:/projects/ipm/soft/project/remote/common/factory.h>
#include <IceE/UndefSysMacros.h>

#ifndef ICEE_IGNORE_VERSION
#   if ICEE_INT_VERSION / 100 != 103
#       error IceE version mismatch!
#   endif
#   if ICEE_INT_VERSION % 100 < 0
#       error IceE patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace Device
{

class Manipulator;

}

}

namespace Device
{

class Manipulator;
bool operator==(const Manipulator&, const Manipulator&);
bool operator<(const Manipulator&, const Manipulator&);

}

namespace IceInternal
{

::Ice::Object* upCast(::Device::Manipulator*);
::IceProxy::Ice::Object* upCast(::IceProxy::Device::Manipulator*);

}

namespace Device
{

typedef ::IceInternal::Handle< ::Device::Manipulator> ManipulatorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Device::Manipulator> ManipulatorPrx;

void __read(::IceInternal::BasicStream*, ManipulatorPrx&);
void __patch__ManipulatorPtr(void*, ::Ice::ObjectPtr&);

}

namespace Device
{

}

namespace Device
{

class Manipulator : virtual public ::Factory::Device
{
public:

    typedef ManipulatorPrx ProxyType;
    typedef ManipulatorPtr PointerType;
    

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

#ifndef ICEE_PURE_CLIENT
    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
};

}

namespace IceProxy
{

namespace Device
{

class Manipulator : virtual public ::IceProxy::Factory::Device
{
public:
    
    ::IceInternal::ProxyHandle<Manipulator> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<Manipulator> ice_secure(bool __secure) const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
#ifdef ICEE_HAS_ROUTER
    ::IceInternal::ProxyHandle<Manipulator> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
#endif // ICEE_HAS_ROUTER
    
#ifdef ICEE_HAS_LOCATOR
    ::IceInternal::ProxyHandle<Manipulator> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<Manipulator> ice_adapterId(const std::string& __id) const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
#endif // ICEE_HAS_LOCATOR
    
    ::IceInternal::ProxyHandle<Manipulator> ice_twoway() const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<Manipulator> ice_oneway() const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<Manipulator> ice_batchOneway() const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<Manipulator> ice_datagram() const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<Manipulator> ice_batchDatagram() const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<Manipulator> ice_timeout(int __timeout) const
    {
        return dynamic_cast<Manipulator*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    static const ::std::string& ice_staticId();
    
private:
    
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

#endif
