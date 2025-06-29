
#include "sender.h"
#include "iostream"
#include <memory>

namespace sagararora {
namespace gossip {

GossipSender::GossipSender(std::shared_ptr<GossipConfig> cfg): cfg(cfg) {}

void GossipSender::start()  {
    std::cout << "Starting the sender";
}

void GossipSender::send(unsigned char* message)  {
    // Implement your message sending logic here.
    if (message) {
        std::cout << "GossipSender: Sending message: " << message << std::endl;
    } else {
        std::cout << "GossipSender: Attempted to send a null message." << std::endl;
    }
}
}
}