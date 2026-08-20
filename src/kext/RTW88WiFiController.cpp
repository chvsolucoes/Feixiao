#include "RTW88WiFiController.hpp"

#include <IOKit/IOLib.h>

#define super IO80211Controller

OSDefineMetaClassAndStructors(
    RTW88WiFiController,
    IO80211Controller
)

bool RTW88WiFiController::init(OSDictionary *dictionary)
{
    IOLog("rtw88-native: RTW88WiFiController::init\n");

    if (!super::init(dictionary))
        return false;

    return true;
}

void RTW88WiFiController::free()
{
    IOLog("rtw88-native: RTW88WiFiController::free\n");
    super::free();
}

bool RTW88WiFiController::start(IOService *provider)
{
    IOLog("rtw88-native: RTW88WiFiController::start\n");

    if (!super::start(provider)) {
        IOLog("rtw88-native: IO80211Controller::start failed\n");
        return false;
    }

    setProperty("RTW88NativeWiFiFoundation", kOSBooleanTrue);
    setProperty("IOUserVisibleName", "Realtek RTL8821CE Wi-Fi");
    setProperty("Vendor", "Realtek");
    setProperty("Model", "RTL8821CE");

    IOLog("rtw88-native: IO80211 foundation initialized\n");
    return true;
}

void RTW88WiFiController::stop(IOService *provider)
{
    IOLog("rtw88-native: RTW88WiFiController::stop\n");
    super::stop(provider);
}

IOReturn RTW88WiFiController::enable(
    IONetworkInterface *interface
)
{
    IOLog("rtw88-native: Wi-Fi enable requested\n");
    return kIOReturnSuccess;
}

IOReturn RTW88WiFiController::disable(
    IONetworkInterface *interface
)
{
    IOLog("rtw88-native: Wi-Fi disable requested\n");
    return kIOReturnSuccess;
}

IOReturn RTW88WiFiController::getHardwareAddress(
    IOEthernetAddress *address
)
{
    if (!address)
        return kIOReturnBadArgument;

    bzero(address->bytes, sizeof(address->bytes));
    return kIOReturnSuccess;
}

IONetworkInterface *
RTW88WiFiController::createInterface()
{
    IOLog("rtw88-native: createInterface requested\n");
    return nullptr;
}

SInt32 RTW88WiFiController::apple80211Request(
    unsigned int request_type,
    int request_number,
    IO80211Interface *interface,
    void *data
)
{
    IOLog(
        "rtw88-native: apple80211Request type=%u request=%d\n",
        request_type,
        request_number
    );

    return kIOReturnUnsupported;
}

SInt32 RTW88WiFiController::stopDMA()
{
    return kIOReturnSuccess;
}

UInt32 RTW88WiFiController::hardwareOutputQueueDepth(
    IO80211Interface *interface
)
{
    return 256;
}

SInt32 RTW88WiFiController::performCountryCodeOperation(
    IO80211Interface *interface,
    IO80211CountryCodeOp operation
)
{
    return kIOReturnSuccess;
}

SInt32 RTW88WiFiController::enableFeature(
    IO80211FeatureCode feature,
    void *data
)
{
    return kIOReturnSuccess;
}
