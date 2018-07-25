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

  Block(const std::string&, const std::string&, const std::string&, const time_t&, const int64&);
  Block(const std::string&, const std::string&);
  std::string serialize() const;
  void debug();
};

Block GenesisBlock();
Block deserialize(const std::string&);

#endif // BLOCK_H
