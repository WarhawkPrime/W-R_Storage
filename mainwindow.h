#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "storing.h"

#include "newliquordialog.h"

#include <QMainWindow>

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
    void on_actionProgramm_beenden_triggered();

    void on_WhiskyTabelle_cellClicked(int row, int column);

    void on_actionNeuen_Whisky_hinzuf_gen_triggered();

    void updateTable();

private:
    Ui::MainWindow *ui;
    Storing* storing;
    NewLiquorDialog* newLiquorDialog;
};

#endif // MAINWINDOW_H
