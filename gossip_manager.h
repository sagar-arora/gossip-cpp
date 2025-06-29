#pragma once

#include <string>
#include "gossip_config.h"
#include <memory>
#include "sender.h"

namespace sagararora {
namespace gossip {

class GossipManager {
    private:
        std::shared_ptr<GossipConfig> cfg;
        std::unique_ptr<Sender> sender;
    public:
        GossipManager(std::string cfg);
        GossipManager(std::unique_ptr<GossipSender> sender);

        void start();
};
}
}