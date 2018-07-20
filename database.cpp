#include "database.h"

int callback(void *NotUsed, int argc, char **argv, char **azColName) {

    NotUsed = 0;
    for (int i = 0; i < argc; i++)
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

    printf("\n");

    return 0;
}


void DataBase::connectToDataBase()
{
  if(openDataBase())
  {
    char *err_msg = 0;
    std::stringstream ss;
    ss << "CREATE TABLE IF NOT EXISTS " << BLOCKCHAIN << "("
       << BLOCKCHAIN_HASH  << " TEXT, "
       << BLOCKCHAIN_BLOCK << " TEXT);";
    std::cout << ss.str().c_str() << std::endl;

    int rc = sqlite3_exec(db, ss.str().c_str(), 0, 0, &err_msg);

    if(rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
  }
}

bool DataBase::openDataBase()
{
  int rc = sqlite3_open(DATABASE_NAME, &db);

  if(rc != SQLITE_OK)
  {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return false;
  }
  return true;
}

void DataBase::insertToBlockchain(std::string hash, std::string block)
{
  char *err_msg = 0;
  std::stringstream ss;
  ss << "INSERT INTO " << BLOCKCHAIN << " VALUES('"
     << hash  << "', '"
     << block << "');";
  std::cout << ss.str().c_str() << std::endl;

  int rc = sqlite3_exec(db, ss.str().c_str(), 0, 0, &err_msg);

  if(rc != SQLITE_OK )
  {
      fprintf(stderr, "SQL error: %s\n", err_msg);
      sqlite3_free(err_msg);
      sqlite3_close(db);
  }
}

void DataBase::printBlockchain()
{
  char *err_msg = 0;
  std::stringstream ss;
  ss << "SELECT * FROM " << BLOCKCHAIN;

  int rc = sqlite3_exec(db, ss.str().c_str(), callback, 0, &err_msg);

  if (rc != SQLITE_OK ) {
    fprintf(stderr, "Failed to select data\n");
    fprintf(stderr, "SQL error: %s\n", err_msg);

    sqlite3_free(err_msg);
    sqlite3_close(db);
  }
}

void DataBase::closeDataBase()
{
    sqlite3_close(db);
}
