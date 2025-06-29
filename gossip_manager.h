#pragma once

#include <string>
#include "gossip_config.h"
#include <memory>
#include "sender.h"
#include "receiver.h"

namespace sagararora {
namespace gossip {

class GossipManager {
    private:
        std::shared_ptr<GossipConfig> cfg;
        std::unique_ptr<Sender> sender;
        std::unique_ptr<Receiver> receiver;
    public:
        GossipManager(std::string cfg);
        GossipManager(std::unique_ptr<GossipSender> sender);

        void start();
};
}
}