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
    // QPrintDialog dialog(&printer, this);
    // if (dialog.exec() != QDialog::Accepted) return;
    QPainter painter;
    painter.begin(&printer);
    qApp->processEvents();
    painter.scale(0.65, 0.65);
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
    int x0 = 200;
    int y0 = 50;

    QFont font;
    font.setFamily("Arial");
    font.setPixelSize(48);
    font.setWeight(QFont::Bold);
    painter->setFont(font);

    if (ui->radioButton1->isChecked())
        painter->drawText(x0, y0, "OG3Z");
    else if (ui->radioButton2->isChecked())
        painter->drawText(x0, y0, "OG2Z");
    else
        painter->drawText(x0, y0, "OH2LHE");

    font.setPixelSize(20);
    font.setWeight(QFont::Normal);
    painter->setFont(font);

    int y = y0 + 34;
    int dy = 26;
    painter->drawText(x0, y, "Hannu Eloranta");
    y+= dy;
    painter->drawText(x0, y, "Niittykatu 1 as 10");
    y+= dy;
    painter->drawText(x0, y, "29200 Harjavalta");
    y+= dy;
    painter->drawText(x0, y, "FINLAND");
    y+= dy + 10;
    painter->drawText(x0, y, "CQ 15");
    y+= dy;
    painter->drawText(x0, y, "ITU 18");
    y+= dy;
    painter->drawText(x0, y, "Grid: KP11mk");

    if (ui->radioButton_3->isChecked())
        painter->drawText(x0+300, y, "Pse QSL                       73, op.");
    else
        painter->drawText(x0+300, y, "Tnx QSL                       73, op.");

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
    font.setPixelSize(20);
    painter->setFont(font);

    int xa = x0 + 240;
    int xb = 940;
    painter->drawRoundedRect(xa, 10, 940-xa, 200, 10, 10);

    // horizontal lines
    y = 50;
    dy = 40;
    int db = 3;
    painter->drawLine(xa, y, xb-db, y);
    y += dy;
    painter->drawLine(xa, y, xb-db, y);
    y += dy;
    painter->drawLine(xa, y, xb-db, y);
    y += dy;
    painter->drawLine(xa, y, xb-db, y);

    // vertical lines
    int x = xa + 150;
    int dx = 80;
    painter->drawLine(x, 50, x, 210);
    x += dx;
    painter->drawLine(x, 50, x, 210);
    x += dx;
    painter->drawLine(x, 50, x, 210);
    x += dx;
    painter->drawLine(x, 50, x, 210);


    x = xa+10;
    y = 80;
    painter->drawText(x, y,  "Date");
    painter->drawText(x+150, y, "UTC");
    painter->drawText(x+230, y, "MHz");
    painter->drawText(x+310, y, "Mode");
    painter->drawText(x+390, y, "RST");

    y += dy;
    painter->drawText(x, y, getData(1, 0));
    y += dy;
    painter->drawText(x, y, getData(2, 0));
    y += dy;
    painter->drawText(x, y, getData(3, 0));

    x = xa+160;
    y = 80 + dy;
    painter->drawText(x, y, getData(1, 1));
    y += dy;
    painter->drawText(x, y, getData(2, 1));
    y += dy;
    painter->drawText(x, y, getData(3, 1));

    x = xa + 240;
    y = 80 + dy;
    painter->drawText(x, y, getData(1, 2));
    y += dy;
    painter->drawText(x, y, getData(2, 2));
    y += dy;
    painter->drawText(x, y, getData(3, 2));

    x = xa + 320;
    y = 80 + dy;
    painter->drawText(x, y, getData(1, 3));
    y += dy;
    painter->drawText(x, y, getData(2, 3));
    y += dy;
    painter->drawText(x, y, getData(3, 3));

    x = xa + 400;
    y = 80 + dy;
    painter->drawText(x, y, getData(1, 4));
    y += dy;
    painter->drawText(x, y, getData(2, 4));
    y += dy;
    painter->drawText(x, y, getData(3, 4));

    x = x0 + 35;
    y = 300;
    painter->drawText(x, y, ui->lineEdit->text());
    y += 50;
    painter->drawText(x, y, ui->lineEdit_2->text());
    y += 50;
    painter->drawText(x, y, ui->lineEdit_3->text());

    font.setItalic(false);
    font.setPixelSize(15);
    painter->setFont(font);
    painter->drawText(xa+10, 25, "Confirming");
    painter->drawText(xa+10, 45, "QSO with");

    font.setPixelSize(25);
    font.setWeight(QFont::Bold);
    painter->setFont(font);
    painter->drawText(xa+120, y0-15, ui->lineEdit_4->text().toUpper());

    font.setWeight(QFont::Normal);
    font.setPixelSize(20);
    font.setFamily("Segoe Script");
    painter->setFont(font);
    painter->drawText(800, 250, "Hannu");
}
