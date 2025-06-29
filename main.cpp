#include <iostream>
#include "gossip_manager.h"
#include <memory>

int main() {
    std::cout << "main" << std::endl;
    const auto mgr = std::make_unique<sagararora::gossip::GossipManager>("/Users/sagararora/projects/gossip_cpp/cfg.json");
    mgr->start();
}