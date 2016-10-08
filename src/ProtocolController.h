#ifndef PROTOCOL_CONTROLLER
#define PROTOCOL_CONTROLLER

#include <Arduino.h>
#include <CGPInterface.h>

class ProtocolController : public CGPInterface {
    private:
        Stream* frontComm;
        Stream* backComm;

    public:
        ProtocolController(Stream* frontComm, Stream* backComm);

        bool sendMessage(Message* msg, int identity);
        bool sendSynAndWaitForAck(Stream* stream);
        Stream* waitForSynAndSendAck();

        Stream* getFrontComm();
        Stream* getBackComm();
};

#endif
