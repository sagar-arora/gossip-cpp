#include "gossip_config.h" // Include your own header first for self-containment check

#include <cstdint>   // For std::int32_t, std::int64_t
#include <fstream>   // For std::ifstream
#include <iostream>  // For std::cerr
#include <memory>    // For std::make_unique
#include <stdexcept> // For std::runtime_error
#include <json/json.h>

namespace sagararora {
namespace gossip {


GossipConfig::GossipConfig(std::int64_t interval,
                           std::string host,
                           std::int32_t port,
                           std::vector<Node> nodes):
      interval(interval),
      host(std::move(host)),
      port(port),
      nodes(std::move(nodes))
{
    std::cout << "GossipConfig initialized for host: " << this->host << ":" << this->port << std::endl;
}

std::shared_ptr<GossipConfig> GossipConfig::loadConfigFromJson(const std::string& filePath) {
    std::ifstream config_file(filePath);

    if (!config_file.is_open()) {
        std::cerr << "Error: Could not open config file: " << filePath << std::endl;
        throw std::runtime_error("Failed to open config file: " + filePath);
    }

    Json::Value json_data;
    Json::CharReaderBuilder readerBuilder;
    std::string errs;

    bool parsingSuccessful = Json::parseFromStream(readerBuilder, config_file, &json_data, &errs);

    config_file.close();

    if (!parsingSuccessful) {
        std::cerr << "Error parsing JSON from " << filePath << ": " << errs << std::endl;
        throw std::runtime_error("JSON parse error: " + errs);
    }

    try {
        std::int64_t interval = json_data["interval"].asInt64();
        std::string host = json_data["host"].asString();
        std::int32_t port = json_data["port"].asInt();

        std::vector<Node> nodes;
        if (json_data.isMember("nodes") && json_data["nodes"].isArray()) {
            for (const auto& node_json : json_data["nodes"]) {
                if (node_json.isMember("host") && node_json.isMember("port")) {
                    Node node(node_json["host"].asString(), node_json["port"].asInt());
                    nodes.push_back(node);
                } else {
                    std::cerr << "Warning: Invalid node format in config file." << std::endl;
                }
            }
        }

        return std::make_shared<GossipConfig>(interval, host, port, nodes);

    } catch (const std::exception& e) { // Catch any other standard exceptions
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        throw;
    }
}

} // namespace gossip
} // namespace sagararora