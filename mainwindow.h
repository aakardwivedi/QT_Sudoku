#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_tableWidget_cellClicked(int row, int column);


    void on_resetButton_clicked();

    void on_answerButton_2_clicked();


private:
    int Grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                         {5, 2, 0, 0, 0, 0, 0, 0, 0},
                         {0, 8, 7, 0, 0, 0, 0, 3, 1},
                         {0, 0, 3, 0, 1, 0, 0, 8, 0},
                         {9, 0, 0, 8, 6, 3, 0, 0, 5},
                         {0, 5, 0, 0, 9, 0, 6, 0, 0},
                         {1, 3, 0, 0, 0, 0, 2, 5, 0},
                         {0, 0, 0, 0, 0, 0, 0, 7, 4},
                         {0, 0, 5, 2, 0, 6, 3, 0, 0}};

Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
