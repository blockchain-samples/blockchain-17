#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

#define DATABASE_NAME    "blockchain.db"
#define BLOCKCHAIN       "Blockchain"
#define BLOCKCHAIN_HASH  "Hash"
#define BLOCKCHAIN_BLOCK "Block"

class DataBase {
private:
  sqlite3 *db;
  bool openDataBase();

public:
  void connectToDataBase();
  void insertToBlockchain(std::string hash, std::string block);
  void closeDataBase();
  void printBlockchain();
};


#endif // DATABASE_H
