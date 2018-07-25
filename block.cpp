#include "proofofwork.h"

Block::Block(const std::string& d,  const std::string& h, const std::string& ph, const time_t& ts, const int64& n)
  : data(d), hash(h), prevHash(ph), timestamp(ts), nonce(n) {}

Block::Block(const std::string& d, const std::string& ph)
  : data(d), prevHash(ph)
{
  time(&timestamp);
  ProofOfWork pow(this);
  std::tie(hash, nonce) = pow.run();
}

std::string Block::serialize() const
{
  std::stringstream ss;
  ss << data      << ","
     << hash      << ","
     << prevHash  << ","
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
  return Block("Genesis",std::string());
}

Block deserialize(const std::string& block)
{
  std::stringstream ss(block);
  std::string item;
  std::vector<std::string> v;
  while(std::getline(ss, item, ','))
    v.push_back(item);

  return Block(v[0],v[1],v[2],std::stoll(v[3], 0, 10),std::stoll(v[4], 0, 10));
}
