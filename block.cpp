#include "block.h"
#include "proofofwork.h"

Block::Block(std::string d, std::string ph)
  : data(d), prevHash(ph)
{
  time(&timestamp);
  ProofOfWork pow(this);
  std::tie(hash, nonce) = pow.Run();
}

std::string Block::getHash()
{
  return hash;
}

void Block::debug()
{
  printf("Data: %s\n", data.c_str());
  printf("Hash: %s\n", hash.c_str());
  printf("Previous Hash: %s\n", prevHash.c_str());
  printf("Timestamp: %ld\n", timestamp);
  printf("Nonce: %llu\n\n", nonce);
}

Block GenesisBlock()
{
  return Block("Genesis","");
}
