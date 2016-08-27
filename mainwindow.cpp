#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include<QString>
#include<QTableWidget>
#include <vector>
#include <algorithm>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int Grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                         {5, 2, 0, 0, 0, 0, 0, 0, 0},
                         {0, 8, 7, 0, 0, 0, 0, 3, 1},
                         {0, 0, 3, 0, 1, 0, 0, 8, 0},
                         {9, 0, 0, 8, 6, 3, 0, 0, 5},
                         {0, 5, 0, 0, 9, 0, 6, 0, 0},
                         {1, 3, 0, 0, 0, 0, 2, 5, 0},
                         {0, 0, 0, 0, 0, 0, 0, 7, 4},
                         {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
        {
            QString str;
            str.setNum(Grid[row][col]);
            ui->tableWidget->setItem(row,col,new QTableWidgetItem(str));
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_resetButton_clicked()
{
    int Grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                         {5, 2, 0, 0, 0, 0, 0, 0, 0},
                         {0, 8, 7, 0, 0, 0, 0, 3, 1},
                         {0, 0, 3, 0, 1, 0, 0, 8, 0},
                         {9, 0, 0, 8, 6, 3, 0, 0, 5},
                         {0, 5, 0, 0, 9, 0, 6, 0, 0},
                         {1, 3, 0, 0, 0, 0, 2, 5, 0},
                         {0, 0, 0, 0, 0, 0, 0, 7, 4},
                         {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
        {
            QString str;
            str.setNum(Grid[row][col]);
            ui->tableWidget->setItem(row,col,new QTableWidgetItem(str));
        }

}




void MainWindow::on_answerButton_2_clicked()
{
    int NewGrid[9][9];
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
        {
            NewGrid[row][col]= ui->tableWidget->item(row,col)->text().toInt();

        }


        int count_i,count_j,temp,count_ij,i,j,flag=1;
        for (  i = 0 ; i < 9 ; i++)
        {
            for (  j = 0 ; j < 9 ; j++)
            {
                if(flag==0)
                    break;
                count_i = 0;
                count_j=0;
                count_ij=0;
                temp = NewGrid[i][j];
                if ( temp != 0)
                {
                    for ( int k = 0 ; k < 9 ; k++ )
                    {
                        if (NewGrid[i][k] == temp)
                            count_i++;
                    }
                    for ( int k = 0 ; k < 9 ; k++ )
                    {
                        if (NewGrid[k][j] == temp)
                            count_j++;
                    }
                    int StartRow = (i-i%3),StartCol = (j-j%3);
                    for(int row=StartRow;row<=StartRow+2;row++)
                            for(int col=StartCol;col<=StartCol+2;col++)
                                if(NewGrid[row][col]==temp)
                                    count_ij++;

                    if((count_i>=2)||(count_j>=2)||(count_ij>=2))
                    {


                        flag=0;
                    }

                }
                else
                    flag=0;
            }
        }
    QMessageBox msgBox;
    if(i==9&&j==9)
    {

        msgBox.setText("Successful Sudoku");
        msgBox.exec();
    }
    else
    {
        msgBox.setText("Sudoku Not Valid");
        msgBox.exec();
    }

}
