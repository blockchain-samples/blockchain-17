#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "sha.h"

class Block {
public:
  std::string data;
  std::string hash;
  std::string prevHash;
  time_t timestamp;
  unsigned long long int nonce;
public:
  Block(std::string d, std::string ph);
  std::string getHash();
  void debug();
};

Block GenesisBlock();

#endif // BLOCK_H
