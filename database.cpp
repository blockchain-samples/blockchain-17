#include "database.h"

DataBase::DataBase()
{
  err_msg = 0;
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    NotUsed = 0;
    for(int i = 0; i < argc; i++)
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    printf("\n");

    return 0;
}

void DataBase::connectToDataBase()
{
  if(openDataBase())
  {
    std::stringstream ss;
    ss << "CREATE TABLE IF NOT EXISTS " << BLOCKCHAIN << "("
       << BLOCKCHAIN_HASH  << " TEXT, "
       << BLOCKCHAIN_BLOCK << " TEXT);";

    int rc = sqlite3_exec(db, ss.str().c_str(), 0, 0, &err_msg);

    if(rc != SQLITE_OK)
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

std::string DataBase::getBlock(std::string hash)
{
  sqlite3_stmt    *stmt;

  std::stringstream ss;
  ss << "SELECT * FROM Blockchain WHERE "
     << BLOCKCHAIN_HASH << " LIKE '" << hash << "'";

  int rc = sqlite3_prepare_v2(db, ss.str().c_str(), -1, &stmt, 0);
  if(rc != SQLITE_OK)
  {
      std::cout << "Can't select data: " << sqlite3_errmsg(db) << std::endl;
      sqlite3_close(db);
  }

  if(sqlite3_step(stmt) == SQLITE_ROW)
  {
    std::string result = (const char*)sqlite3_column_text(stmt, 1);
    sqlite3_finalize(stmt);
    return result;
  }

  return std::string();
}

void DataBase::insertToBlockchain(std::string hash, std::string block)
{
  std::stringstream ss;
  ss << "INSERT INTO " << BLOCKCHAIN << " VALUES('"
     << hash  << "', '"
     << block << "');";

  int rc = sqlite3_exec(db, ss.str().c_str(), 0, 0, &err_msg);

  if(rc != SQLITE_OK)
  {
      fprintf(stderr, "SQL error: %s\n", err_msg);
      sqlite3_free(err_msg);
      sqlite3_close(db);
  }
}

void DataBase::printBlockchain()
{
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
