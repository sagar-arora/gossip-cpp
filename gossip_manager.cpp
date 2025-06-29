
#include <string>
#include "gossip_config.h"
#include <iostream>
#include "gossip_manager.h"
#include "sender.h"
#include <memory>

namespace sagararora {
    namespace gossip {
    
    GossipManager::GossipManager(std::string cfg) {
        std::cout << "Initialized GossipManager";
        this->cfg = GossipConfig::loadConfigFromJson(cfg);
        this->sender = std::make_unique<GossipSender>(this->cfg);
    }

    GossipManager::GossipManager(std::unique_ptr<GossipSender> sender) {
        this->sender = std::move(sender);
    }

    void GossipManager::start() {
        this->sender->start();
    }
}
}
