#include "blockchain.h"

Blockchain::Blockchain()
{
  Block b = GenesisBlock();
  b.serialize();
  blocks.push_back(b);
}

void Blockchain::addBlock(std::string data)
{
  Block b = {data,blocks[blocks.size()-1].hash};
  b.serialize();
  blocks.push_back(b);
}

void Blockchain::printChain()
{
  for(auto it = blocks.begin(); it != blocks.end(); ++it)
    it->debug();
}
