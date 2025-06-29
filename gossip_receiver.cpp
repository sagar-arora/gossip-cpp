#include "receiver.h"
#include "gossip_config.h"
#include <iostream>

namespace sagararora
{
namespace gossip {
GossipReceiver::GossipReceiver(std::shared_ptr<GossipConfig> cfg): cfg(cfg) {}

void GossipReceiver::start() {
    std::cout << "starting receiver" << std::endl;
}

void GossipReceiver::receive(unsigned char* bytes) {   
}
}
} // namespace xw
