#include "proofofwork.h"

Block::Block(std::string d, std::string ph)
  : data(d), prevHash(ph)
{
  time(&timestamp);
  ProofOfWork pow(this);
  std::tie(hash, nonce) = pow.run();
}

std::string Block::serialize()
{
  std::stringstream ss;
  ss << hash      << ","
     << prevHash  << ","
     << data      << ","
     << timestamp << ","
     << nonce     << "\n";
  return ss.str();
}

void Block::debug()
{
  printf("Data: %s\n", data.c_str());
  printf("Hash: %s\n", hash.c_str());
  printf("Previous Hash: %s\n", prevHash.c_str());
  printf("Timestamp: %ld\n", timestamp);
  printf("Nonce: %llu\n", nonce);
  ProofOfWork pow(this);
  printf("Validate: %d\n\n", pow.validate());
}

Block GenesisBlock()
{
  return Block("Genesis","");
}
