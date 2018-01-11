#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrintDialog>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPrintDialog dialog(&printer);
    dialog.setWindowTitle("Print QSL");
    if (dialog.exec() != QDialog::Accepted)
    {
            return;
    }
    printer.setOrientation(QPrinter::Landscape);
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
    QPen aPen;
    aPen.setColor(Qt::black);
    aPen.setWidth(0);
    aPen.setStyle(Qt::SolidLine);
    painter->setPen(aPen);

    QFont font;
    font.setFamily("Arial");
    font.setPixelSize(32);
    font.setWeight(QFont::Bold);
    font.setItalic(false);
    painter->setFont(font);

    int x0 = 550;
    int y0 = 290;
    int dy = 14;
    if (ui->radioButton->isChecked())
        painter->drawText(x0, y0, "OH2LHE");
    else
        painter->drawText(x0, y0, "OG2Z");

    font.setPixelSize(dy);
    dy++;
    painter->setFont(font);
    int y = 310;
    painter->drawText(x0, y, "Hannu Eloranta");
    y+= dy;
    painter->drawText(x0, y, "Maininkitie 9 G 87");
    y+= dy;
    painter->drawText(x0, y, "02320 Espoo");
    y+= dy;
    painter->drawText(x0, y, "FINLAND");
    y+= 2*dy;
    painter->drawText(x0, y, "CQ 15");
    y+= dy;
    painter->drawText(x0, y, "ITU 18");
    y+= dy;
    painter->drawText(x0, y, "Grid: KP11mk");

    font.setWeight(QFont::Normal);
    painter->setFont(font);
    painter->drawText(x0+170, y, "Pse QSL Tnx              73, op.");

    painter->drawLine(x0+370, y, 1020, y);

    y+= 2*dy;
    painter->drawLine(x0, y, 1020, y);
    y+= 2*dy;
    painter->drawLine(x0, y, 1020, y);
    y+= 2*dy;
    painter->drawLine(x0, y, 1020, y);
    y+= 2*dy;

    font.setItalic(true);
    painter->setFont(font);
    painter->drawText(x0, y, "Photo by OH2LHE: Waxwing (Bombycilla garrulus)");
    font.setItalic(false);
    painter->setFont(font);

    painter->drawRoundedRect(700, 260, 300, 128, 10, 10);
    y = 300;
    painter->drawLine(700, y, 1000, y);
    dy = 22;
    y += dy;
    painter->drawLine(700, y, 1000, y);
    y += dy;
    painter->drawLine(700, y, 1000, y);
    y += dy;
    painter->drawLine(700, y, 1000, y);

    int x = 800;
    int dx = 50;
    painter->drawLine(x, 300, 800, 388);
    x += dx;
    painter->drawLine(x, 300, x, 388);
    x += dx;
    painter->drawLine(x, 300, x, 388);
    x += dx;
    painter->drawLine(x, 300, x, 388);

    x = 715;
    y = 338;
    painter->drawText(x, y, getData(1, 0));
    y += dy;
    painter->drawText(x, y, getData(2, 0));
    y += dy;
    painter->drawText(x, y, getData(3, 0));

    x = 810;
    y = 338;
    painter->drawText(x, y, getData(1, 1));
    y += dy;
    painter->drawText(x, y, getData(2, 1));
    y += dy;
    painter->drawText(x, y, getData(3, 1));

    x = 865;
    y = 338;
    painter->drawText(x, y, getData(1, 2));
    y += dy;
    painter->drawText(x, y, getData(2, 2));
    y += dy;
    painter->drawText(x, y, getData(3, 2));

    x = 910;
    y = 338;
    painter->drawText(x, y, getData(1, 3));
    y += dy;
    painter->drawText(x, y, getData(2, 3));
    y += dy;
    painter->drawText(x, y, getData(3, 3));

    x = 960;
    y = 338;
    painter->drawText(x, y, getData(1, 4));
    y += dy;
    painter->drawText(x, y, getData(2, 4));
    y += dy;
    painter->drawText(x, y, getData(3, 4));


    x = 735;
    y = 316;
    painter->drawText(x, y, "Date");
    painter->drawText(x+75, y, "UTC");
    painter->drawText(x+125, y, "MHz");
    painter->drawText(x+172, y, "2-way");
    painter->drawText(x+225, y, "RST");

    x = 570;
    y = 440;
    painter->drawText(x, y, ui->lineEdit->text());
    y += 28;
    painter->drawText(x, y, ui->lineEdit_2->text());
    y += 28;
    painter->drawText(x, y, ui->lineEdit_3->text());

    dy = 10;
    font.setItalic(false);
    font.setPixelSize(dy);
    painter->setFont(font);
    painter->drawText(710, 275, "Confirming");
    painter->drawText(710, 275+dy+5, "QSO with");

    font.setPixelSize(16);
    font.setItalic(true);
    painter->setFont(font);
    painter->drawText(930, 410, "Hannu");


}
