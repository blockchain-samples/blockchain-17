#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "block.h"

class Blockchain {
private:
  std::vector<Block> blocks;
public:
  Blockchain();
  void addBlock(std::string);
  void printChain();
};

#endif // BLOCKCHAIN_H
