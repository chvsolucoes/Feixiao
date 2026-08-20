#pragma once

#include <IOKit/80211/IO80211Controller.h>
#include <IOKit/80211/IO80211Interface.h>

class RTW88WiFiController : public IO80211Controller
{
    OSDeclareDefaultStructors(RTW88WiFiController)

public:
    bool init(OSDictionary *dictionary = nullptr) override;
    void free() override;

    bool start(IOService *provider) override;
    void stop(IOService *provider) override;

    IOReturn enable(IONetworkInterface *interface) override;
    IOReturn disable(IONetworkInterface *interface) override;

    IOReturn getHardwareAddress(IOEthernetAddress *address) override;
    IONetworkInterface *createInterface() override;

    SInt32 apple80211Request(
        unsigned int request_type,
        int request_number,
        IO80211Interface *interface,
        void *data
    ) override;

    SInt32 stopDMA() override;

    UInt32 hardwareOutputQueueDepth(
        IO80211Interface *interface
    ) override;

    SInt32 performCountryCodeOperation(
        IO80211Interface *interface,
        IO80211CountryCodeOp operation
    ) override;

    SInt32 enableFeature(
        IO80211FeatureCode feature,
        void *data
    ) override;
};
