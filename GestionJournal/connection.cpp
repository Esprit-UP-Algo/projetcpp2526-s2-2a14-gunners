#include "connection.h"

Connection::Connection() {}

bool Connection::createconnect() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("gunners"); // Data Source Name
  db.setUserName("gunners");     // User
  db.setPassword("gunners8");    // Password

  return db.open();
}
