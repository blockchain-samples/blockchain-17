#include <iostream>
#include "blockchain.h"

int main()
{
  Blockchain bc;
  bc.addBlock("Send 1 BTC to Richard");
  bc.addBlock("Send 2 BTC to Ivan");
  bc.addBlock("Send 0.5 BTC to Pavel");
  bc.printChain();

  return 0;
}
