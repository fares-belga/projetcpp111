#ifndef GESTION_PRODUIT_H
#define GESTION_PRODUIT_H
#include <QString>
#include<iostream>


#include <QMainWindow>

namespace Ui {
class gestion_produit;
}

class gestion_produit : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_produit(QWidget *parent = nullptr);

     gestion_produit();
    gestion_produit(int,int,QString,int,QString);
    ~gestion_produit();
     bool ajouter();

     int Getreference_produit() { return reference_produit; }
     void Setreference_produit(int val) { reference_produit = val; }
     int Getprix() { return prix; }
     void Setprix(int val) { prix = val; }
     QString Getdate_produit() { return date_produit; }
     void Setdate_produit(QString val) { date_produit = val; }
     int Getquantite() { return quantite; }
     void Setquantite(int val) { quantite = val; }
     QString Getnom() { return nom; }
     void Setnom(QString val) { nom = val; }





private slots:
     void on_pushButton_clicked();

private:
    Ui::gestion_produit *ui;

    int reference_produit;
    int prix;
    QString date_produit;
    int quantite;
    QString nom;
};

#endif // GESTION_PRODUIT_H
