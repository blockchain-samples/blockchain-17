#include <iostream>
#include "blockchain.h"

int main(int argc, char *argv[])
{
  Blockchain bc;
  if(argc == 2 && (std::string)argv[1] == "printblockchain")
  {
    bc.printBlockchain();
  } else if(argc == 3 && (std::string)argv[1] == "addblock")
  {
    bc.addBlock(argv[2]);
  }
  else
  {
    printf("Usage:\n");
    printf("  addblock \"BLOCK_DATA\" - add a block to the blockchain\n");
    printf("  printblockchain - print all the blocks of the blockchain\n");
  }

  return 0;
}
