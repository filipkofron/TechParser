#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStringBuilder>
#include "token.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_selectFile_clicked()
{
  QFileDialog dialog;
  if (dialog.exec())
  {
    if (!dialog.selectedFiles().size()) return;
    int counter = 0;
    QFile file(dialog.selectedFiles()[0]);
    file.open(QFile::ReadOnly);
    Tokenizer tokenizer(file);
    Token tok;
    QString sb;
    QString sb1k;
    QString sb32k;
    do
    {
      tok = tokenizer.Next();
      if (tok.GetType() == Token::eof) break;
      if (!(counter++ % 256))
      {
        std::cout << "counter: " << counter << std::endl;
      }
      sb1k = sb1k % tok.GetText();
      if (sb1k.size() == 256)
      {
        sb32k = sb32k % sb1k;
        sb1k.clear();
        if (sb32k.size() == 32768)
        {
          sb = sb % sb32k;
          sb32k.clear();
        }
      }
    } while (true);
    if (sb1k.size())
    {
      sb32k = sb32k % sb1k;
    }
    if (sb32k.size())
    {
      sb = sb % sb32k;
    }
    ui->textBrowser->setText(sb);
    file.close();
  }
}
