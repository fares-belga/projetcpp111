#include "connection.h"
#include <QSqlDatabase>
Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetCpp");
db.setUserName("ghofrane");//inserer nom de l'utilisateur
db.setPassword("123456");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
   return test;
}
void Connection::closeconnection()
 { db.close();}
