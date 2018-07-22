#include "blockchain.h"

Blockchain::Blockchain()
{
  if(!exists(DATABASE_NAME))
  {
    bc.connectToDataBase();
    Block b = GenesisBlock();
    bc.insertToBlockchain(b.hash,b.serialize());
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
  Block b = {data,bc.getHashLastBlock()};
  bc.insertToBlockchain(b.hash,b.serialize());
}

void Blockchain::printBlockchain()
{
  bc.printBlockchain();
}
