#include "blockchain.h"

Blockchain::Blockchain()
{
  if(!exists(DATABASE_NAME))
  {
    bc.connectToDataBase();
    Block b = GenesisBlock();
    bc.insertToBlockchain("5","2");
  }
  else
    bc.connectToDataBase();
}

Blockchain::~Blockchain()
{
  bc.closeDataBase();
}

void Blockchain::addBlock(std::string data)
{
  //Block b = {data,blocks[blocks.size()-1].hash};
  bc.insertToBlockchain("1","3");
}

void Blockchain::printBlockchain()
{
  bc.printBlockchain();
  std::cout << bc.getBlock("5") << std::endl;
}
