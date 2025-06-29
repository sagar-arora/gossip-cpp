#pragma once


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace sagararora {
namespace gossip {

class Node {
  public:
    std::string host;
    std::int32_t port;

    Node(std::string host, int32_t port): host(host), port(port) {}
};

class GossipConfig {    
    
  public:
    int64_t interval;
    std::string host;
    int32_t port;
    std::vector<Node> nodes;

    GossipConfig() {
      
    }

    GossipConfig(int64_t interval, std::string host, int32_t port, std::vector<Node> nodes);

    static std::shared_ptr<GossipConfig> loadConfigFromJson(const std::string& filePath);
};
} // namespace gossip
} // namespace sagararora
