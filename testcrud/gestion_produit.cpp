#include "gestion_produit.h"
#include "ui_gestion_produit.h"
#include "gestion_produit.h"
#include <QString>
#include<iostream>
#include <QtDebug>
#include <QSqlQuery>
using namespace std;

gestion_produit::gestion_produit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_produit)
{
    ui->setupUi(this);
}

gestion_produit::~gestion_produit()
{
    delete ui;
}


gestion_produit::gestion_produit()
{
  reference_produit=0;
    prix=0;
   date_produit="";
    quantite=0;
    nom="";
}

gestion_produit::gestion_produit(int reference_produit , int prix, QString date_produit , int quantite , QString nom)

{
    this->reference_produit=reference_produit;
    this->prix=prix;
    this->date_produit=date_produit;
    this->quantite=quantite;
    this->nom=nom;

}
 bool gestion_produit:: ajouter()
 {
     bool test = false;
         QSqlQuery query;

          query.prepare("INSERT INTO Produit (reference_produit,prix , date_produit,quantite,nom) "
                        "VALUES (:reference_produit, :forename, :surname)");
          query.bindValue(":reference_produit", 1001);
          query.bindValue(":forename", "Bart");
          query.bindValue(":surname", "Simpson");
          query.exec();

     return test;
 }


void gestion_produit::on_pushButton_clicked()
{
    int reference =ui->le_reference_produit->text().toInt();
    int prix=ui->le_prix->text().toInt();
    QString date_produit=ui->le_date_produit->text();
    int quantite=ui->le_quantite->text().toInt();
    QString nom=ui->le_nom->text();
     gestion_produit p(reference,prix,date_produit,quantite,nom);
}
