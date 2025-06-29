#pragma once
#include "gossip_config.h"
#include <memory>

namespace sagararora {
namespace gossip {


class Sender {
public:
  virtual void send(unsigned char* message) = 0;
  virtual void start() = 0;
  virtual ~Sender() {}
};

class GossipSender: public Sender {
private:
  std::shared_ptr<GossipConfig> cfg;
public:
  GossipSender(std::shared_ptr<GossipConfig> cfg);
  void send(unsigned char* message) override;
  void start() override;
};

}
}