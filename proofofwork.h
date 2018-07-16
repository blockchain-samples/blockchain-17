#ifndef PROOFOFWORK_H
#define PROOFOFWORK_H

#include "block.h"
#include <iostream>

class ProofOfWork {
private:
  Block *pblock;
  std::string target;
public:
  ProofOfWork(Block *pb);
  std::pair<std::string,unsigned long long int> Run();
};

#endif // PROOFOFWORK_H
