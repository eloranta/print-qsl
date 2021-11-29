#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrintDialog>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(print()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print()
{
    QPainter painter;
    painter.begin(&printer);
    qApp->processEvents();
    printPage(&painter);
    painter.end();
}

QString MainWindow::getData(int x, int y)
{
    QTableWidgetItem *item = ui->tableWidget->item(x, y);
    if (item)
        return item->text();
    else
        return "";
}

void MainWindow::printPage(QPainter* painter)
{
    int x0 = 240;
    int y0 = 50;

    QFont font;
    font.setFamily("Arial");
    font.setPixelSize(50);
    font.setWeight(QFont::Bold);
    painter->setFont(font);

    if (ui->radioButton1->isChecked())
        painter->drawText(x0, y0, "OG2Z");
    else if (ui->radioButton2->isChecked())
        painter->drawText(x0, y0, "OG3Z");
    else
        painter->drawText(x0, y0, "OH2LHE");

    font.setPixelSize(25);
    font.setWeight(QFont::Normal);
    painter->setFont(font);

    int y = y0 + 30;
    int dy = 26;
    painter->drawText(x0, y, "Hannu Eloranta");
    y+= dy;
    painter->drawText(x0, y, "Kelohongantie 14 F 35");
    y+= dy;
    painter->drawText(x0, y, "02120 Espoo");
    y+= dy;
    painter->drawText(x0, y, "FINLAND");
    y+= 2*dy;
    painter->drawText(x0, y, "CQ 15");
    y+= dy;
    painter->drawText(x0, y, "ITU 18");
    y+= dy;
    painter->drawText(x0, y, "Grid: KP11mk");

    if (ui->radioButton_3->isChecked())
        painter->drawText(x0+300, y, "Pse QSL                73, op.");
    else
        painter->drawText(x0+300, y, "Tnx QSL                73, op.");

    QPen aPen;
    aPen.setColor(Qt::black);
    aPen.setWidth(0);
    aPen.setStyle(Qt::SolidLine);
    painter->setPen(aPen);

    painter->drawLine(x0+600, y, 950, y);
    y+= 2*dy;
    painter->drawLine(x0, y, 950, y);
    y+= 2*dy;
    painter->drawLine(x0, y, 950, y);
    y+= 2*dy;
    painter->drawLine(x0, y, 950, y);
    y+= 2*dy;

    font.setItalic(true);
    font.setPixelSize(15);
    painter->setFont(font);
    painter->drawText(x0, y, "Photo by OH2LHE: Waxwing (Bombycilla garrulus)");

    font.setItalic(false);
    font.setPixelSize(25);
    painter->setFont(font);

    int xa = x0 + 300;
    int xb = 940;
    painter->drawRoundedRect(xa, 10, 400, 200, 10, 10);

    y = 50;
    dy = 40;
    painter->drawLine(xa, y, xb, y);
    y += dy;
    painter->drawLine(xa, y, xb, y);
    y += dy;
    painter->drawLine(xa, y, xb, y);
    y += dy;
    painter->drawLine(xa, y, xb, y);

    int x = xa + 110;
    int dx = 70;
    painter->drawLine(x, 50, x, 210);
    x += dx;
    painter->drawLine(x, 50, x, 210);
    x += dx;
    painter->drawLine(x, 50, x, 210);
    x += dx;
    painter->drawLine(x, 50, x, 210);


    x = xa+25;
    y = 80;
    painter->drawText(x+8, y,  "Date");
    painter->drawText(x+95, y, "UTC");
    painter->drawText(x+165, y, "MHz");
    painter->drawText(x+230, y, "Mode");
    painter->drawText(x+310, y, "RST");

    y += dy;
    painter->drawText(x-20, y, getData(1, 0));
    y += dy;
    painter->drawText(x-20, y, getData(2, 0));
    y += dy;
    painter->drawText(x-20, y, getData(3, 0));

    x = xa+115;
    y = 80 + dy;
    painter->drawText(x, y, getData(1, 1));
    y += dy;
    painter->drawText(x, y, getData(2, 1));
    y += dy;
    painter->drawText(x, y, getData(3, 1));

    x = xa + 185;
    y = 80 + dy;
    painter->drawText(x, y, getData(1, 2));
    y += dy;
    painter->drawText(x, y, getData(2, 2));
    y += dy;
    painter->drawText(x, y, getData(3, 2));

    x = xa + 260;
    y = 80 + dy;
    painter->drawText(x, y, getData(1, 3));
    y += dy;
    painter->drawText(x, y, getData(2, 3));
    y += dy;
    painter->drawText(x, y, getData(3, 3));

    x = xa + 330;
    y = 80 + dy;
    painter->drawText(x, y, getData(1, 4));
    y += dy;
    painter->drawText(x, y, getData(2, 4));
    y += dy;
    painter->drawText(x, y, getData(3, 4));

    x = x0 + 35;
    y = 305;
    painter->drawText(x, y, ui->lineEdit->text());
    y += 50;
    painter->drawText(x, y, ui->lineEdit_2->text());
    y += 50;
    painter->drawText(x, y, ui->lineEdit_3->text());

    font.setItalic(false);
    font.setPixelSize(15);
    painter->setFont(font);
    painter->drawText(xa+5, 25, "Confirming");
    painter->drawText(xa+5, 45, "QSO with");

    font.setPixelSize(25);
    font.setWeight(QFont::Bold);
    painter->setFont(font);
    painter->drawText(xa+120, y0-12, ui->lineEdit_4->text());

    font.setWeight(QFont::Normal);
    font.setPixelSize(20);
    font.setFamily("Segoe Script");
    painter->setFont(font);
    painter->drawText(835, 255, "Hannu");
}
