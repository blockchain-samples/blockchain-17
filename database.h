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
#define SQL ss.str().c_str()

class DataBase {
private:
  sqlite3 *db;
  char *err_msg {0};

  bool openDataBase();

public:
  DataBase();
  std::string getBlock(const std::string&);
  std::string getHashLastBlock();
  void connectToDataBase();
  void insertToBlockchain(const std::string& hash, const std::string& block);
  void closeDataBase();
};


#endif // DATABASE_H
