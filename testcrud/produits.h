#ifndef Produits_H
#define Produits_H
#include <QString>
#include<iostream>
#include <QSqlQueryModel>




class produits
{


    public:
        produits();
       produits(int,float,QString,int,QString);
        bool ajouter();
    bool modifier(int );
        QSqlQueryModel* afficher();
        bool supprimer(int REFERENCE_PRODUIT );

        int Getreference_produit();
        void Setreference_produit(int);
       float Getprix();
        void Setprix(float) ;
        QString Getdate_produit();
        void Setdate_produit(QString);
        int Getquantite();
        void Setquantite(int);
        QString Getnom();
        void Setnom(QString);
    protected:

    private:
        int REFERENCE_PRODUIT;
        float PRIX;
        QString DATE_PRODUIT;
        int QUANTITE;
        QString NOM;
};


#endif // PRODUIT_H
