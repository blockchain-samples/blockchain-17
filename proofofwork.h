#ifndef PROOFOFWORK_H
#define PROOFOFWORK_H

typedef unsigned long long int int64;

#include "block.h"
#include <iostream>

class ProofOfWork {
private:
  Block *pblock;
  std::string target;
public:
  ProofOfWork(Block *pb);
  std::pair<std::string,int64> run();
  bool validate();
};

#endif // PROOFOFWORK_H
