#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "block.h"
#include "database.h"
#include "utils.h"

class Blockchain {
private:
  DataBase bc;
public:
  Blockchain();
  ~Blockchain();
  void addBlock(std::string);
  void printBlockchain();
};

#endif // BLOCKCHAIN_H
