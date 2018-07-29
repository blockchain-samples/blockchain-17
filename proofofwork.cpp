#include "proofofwork.h"

ProofOfWork::ProofOfWork(Block *pb)
  : pblock(pb)
{
  target = "0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
}

std::pair<std::string,int64> ProofOfWork::run()
{
  printf("Mining the block: \"%s\"\n", pblock->data.c_str());

  int64 nonce {0};
  std::string buff {pblock->data + pblock->prevHash + std::to_string(pblock->timestamp)};
  std::string hash {sha256(buff + std::to_string(nonce))};
  while(!std::lexicographical_compare(hash.begin(), hash.end(), target.begin(), target.end()))
  {
    nonce++;
    hash = sha256(buff + std::to_string(nonce));
    printf("%s\r",hash.c_str());
  }
  printf("\n");

  return std::pair{hash,nonce};
}

bool ProofOfWork::validate()
{
  std::string buff {pblock->data + pblock->prevHash + std::to_string(pblock->timestamp)
    + std::to_string(pblock->nonce)};
  return sha256(buff) == pblock->hash;
}
