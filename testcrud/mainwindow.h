#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"produits.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_Ajouter_clicked();



   void on_pb_supprimer_3_clicked();



   void on_modifier_clicked();

private:
    Ui::MainWindow *ui;
    produits p ;

};

#endif // MAINWINDOW_H
