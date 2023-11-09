#include "produits.h"
#include <QtDebug>
#include <QSqlQuery>
#include<QObject>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include<QString>
#include <QSqlQueryModel>
#include<QDate>
#include<QDateTime>
using namespace std;



produits::produits()
{
  REFERENCE_PRODUIT=0;
   PRIX=0;
   DATE_PRODUIT="";
   QUANTITE=0;
    NOM="";
}

produits::produits(int reference_produit , float prix, QString date_produit , int quantite , QString nom)

{
  this->REFERENCE_PRODUIT=reference_produit;
    this->PRIX=prix;
    this->DATE_PRODUIT=date_produit;
    this->QUANTITE=quantite;
    this->NOM=nom;}

int produits::Getreference_produit()
{ return REFERENCE_PRODUIT; }
void produits::Setreference_produit(int reference_produit )
{ this->REFERENCE_PRODUIT = reference_produit; }

float produits::Getprix()
{ return PRIX; }
void produits::Setprix(float prix)
{ this->PRIX = prix; }

QString produits::Getdate_produit()
{ return DATE_PRODUIT; }

void produits::Setdate_produit(QString date_produit)
{ this->DATE_PRODUIT = date_produit; }

int produits::Getquantite()
{ return QUANTITE; }

void produits::Setquantite(int quantite)
{ this->QUANTITE = quantite; }

QString produits::Getnom()
{ return NOM; }

void produits::Setnom(QString nom)
{ this->NOM =nom; }

 bool produits::ajouter()
 {
     bool test = false;
     QSqlQuery query;
     QString reference_produit_string = QString::number(REFERENCE_PRODUIT);
     QString prix_string = QString::number(PRIX);
     QString quantite_string = QString::number(QUANTITE);

    query.prepare("INSERT INTO PRODUITS (REFERENCE_PRODUIT,PRIX , DATE_PRODUIT,QUANTITE,NOM) "
                        "VALUES (:reference_produit, :prix, :date_produit,:quantite,:nom)");
          query.bindValue(":reference_produit",reference_produit_string);
          query.bindValue(":prix", prix_string);
          query.bindValue(":date_produit", DATE_PRODUIT);
          query.bindValue(":quantite",quantite_string);
          query.bindValue(":nom", NOM);

          if(query.exec()){
              test =true;
         } else {
              qDebug()<<"Error:"<<query.lastError().text();
          }


          return test;
 }
 bool produits::supprimer(int reference_produit  )
 {
     QSqlQuery query;
         query.prepare("SELECT * FROM PRODUITS WHERE REFERENCE_PRODUIT = :reference_produit");
         query.bindValue(":reference_produit", reference_produit);

         if (query.exec() && query.next()) {
             // The reference_produit exists, so we can proceed with deletion.
             query.prepare("DELETE FROM PRODUITS WHERE REFERENCE_PRODUIT = :reference_produit");
             query.bindValue(":reference_produit", reference_produit);
             if (query.exec()) {
                 return true; // Deletion was successful
             } else {
                 qDebug() << "Error during deletion:" << query.lastError().text();
                 return false;
             }
         } else {
             // The reference_produit does not exist.
             return false;
         }
     }
 QSqlQueryModel* produits ::afficher()
 {

   QSqlQueryModel* model=new QSqlQueryModel();


      model->setQuery("SELECT * FROM produits");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference_produit"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_produit"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
   return model;

 }
 bool produits::modifier(int reference_produit)
 {
     bool test = false;
     QSqlQuery query;
     QString reference_produit_string = QString::number(reference_produit);
     QString prix_string = QString::number(PRIX);
     QString quantite_string = QString::number(QUANTITE);

     query.prepare("UPDATE PRODUITS SET PRIX = :prix, DATE_PRODUIT = :date_produit, QUANTITE = :quantite, NOM = :nom WHERE REFERENCE_PRODUIT = :reference_produit");
     query.bindValue(":reference_produit", reference_produit_string);
     query.bindValue(":prix", prix_string);
     query.bindValue(":date_produit", DATE_PRODUIT);
     query.bindValue(":quantite", quantite_string);
     query.bindValue(":nom", NOM);

     if (query.exec()) {
         test = true;
     } else {
         qDebug() << "Error: " << query.lastError().text();
     }

     return test;
 }



