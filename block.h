#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "sha.h"

struct Block {
  std::string data;
  std::string hash;
  std::string prevHash;
  time_t timestamp;
  int64 nonce;

  Block(std::string, std::string, std::string, time_t, int64);
  Block(std::string, std::string);
  std::string serialize();
  void debug();
};

Block GenesisBlock();
Block deserialize(std::string);

#endif // BLOCK_H
