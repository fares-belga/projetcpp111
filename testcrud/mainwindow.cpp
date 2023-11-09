#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produits.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QObject>
#include <QtDebug>
#include <QTabWidget>
#include<QSqlQuery>
#include <QDate>
#include <QDateEdit>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui ->le_reference_produit->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_produits->setModel(p.afficher());
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_Ajouter_clicked()
{

        int reference =ui->le_reference_produit->text().toInt();
        float prix=ui->le_prix->text().toFloat();
        QString date_produit=ui->le_date_produit->text();
        int quantite=ui->le_quantite->text().toInt();
        QString nom=ui->le_nom->text();
        ui->tab_produits->setModel(p.afficher());
        produits p(reference,prix,date_produit,quantite,nom);
       bool insertionSuccess =p.ajouter();

        QMessageBox messagebox;
        if(insertionSuccess){
            messagebox.setText("Data added to the database successfully");

        }else{ messagebox.setText("Failed add data to the databse");

        }
        messagebox.exec();

    }




void MainWindow::on_pb_supprimer_3_clicked()
{
    produits p;
    int REFERENCE_PRODUIT_to_delete = ui->le_reference_produit->text().toInt();
    bool test = p.supprimer(REFERENCE_PRODUIT_to_delete);
    if(test)
    {

        ui->tab_produits->setModel(p.afficher());
        QMessageBox::information(this,QObject::tr("ok"),
        QObject::tr("suppression non effectuée\nClick OK to exit."),QMessageBox::Ok);
    }

    else
    {
    QMessageBox::information(this, tr("Not OK"), tr("Deletion was not successful. Click OK to exit."), QMessageBox::Ok);
    }
}



void MainWindow::on_modifier_clicked()
{

    int reference =ui->le_reference_produit->text().toInt();
    float prix=ui->le_prix->text().toFloat();
    QString date_produit=ui->le_date_produit->text();
    int quantite=ui->le_quantite->text().toInt();
    QString nom=ui->le_nom->text();
        produits p(reference,prix,date_produit,quantite,nom);
         bool test=p.modifier(reference);
           ui->tab_produits->setModel(p.afficher());
          if(test){
              QMessageBox::information(nullptr, QObject::tr("update"),
                    QObject::tr(" successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
          else
          {
         QMessageBox::critical(nullptr, QObject::tr("update"),
                     QObject::tr(" failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         }
}
