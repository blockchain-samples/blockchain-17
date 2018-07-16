#include "proofofwork.h"

ProofOfWork::ProofOfWork(Block *pb)
  : pblock(pb)
{
  target = "000081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08";
}

std::pair<std::string,unsigned long long int> ProofOfWork::Run()
{
  printf("Mining the block: \"%s\"\n", pblock->data.c_str());

  unsigned long long int nonce = 0;
  std::string buff = pblock->data + pblock->prevHash + std::to_string(pblock->timestamp);
  std::string hash = sha256(buff);
  while(!std::lexicographical_compare(hash.begin(), hash.end(), target.begin(), target.end()))
  {
    printf("\r");
    nonce++;
    hash = sha256(buff + std::to_string(nonce));
    printf("%s",hash.c_str());
  }
  printf("\n");

  return std::make_pair(hash,nonce);
}
