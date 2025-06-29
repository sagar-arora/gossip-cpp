#pragma once
#include <memory>
#include "gossip_config.h"

namespace sagararora
{
namespace gossip {

class Receiver {
public:
  virtual void start() = 0;
  virtual void receive(unsigned char* bytes) = 0;
  virtual ~Receiver() {}
};

class GossipReceiver: public Receiver {
private:
std::shared_ptr<GossipConfig> cfg;
public:
  GossipReceiver(std::shared_ptr<GossipConfig> cfg);
  void start() override;
  void receive(unsigned char* bytes) override;
};
}
} // namespace name

