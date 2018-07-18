#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include "sha.h"

struct Block {
  std::string data;
  std::string hash;
  std::string prevHash;
  time_t timestamp;
  int64 nonce;

  Block(std::string d, std::string ph);
  void serialize();
  void debug();
};

Block GenesisBlock();

#endif // BLOCK_H
