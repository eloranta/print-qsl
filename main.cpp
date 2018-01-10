#include "mainwindow.h"
#include <QApplication>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

void printPage(QPainter* painter, int thePage)
{
    QPen aPen;
    aPen.setColor(Qt::black);
    aPen.setWidth(0);
    aPen.setStyle(Qt::SolidLine);
    painter->setPen(aPen);

//    painter->drawRect(520, 240, 500, 310);


    // Set brush
//    QBrush aBrush;
//    aBrush.setColor(Qt::black);
//    aBrush.setStyle(Qt::SolidPattern);
//    painter->setBrush(aBrush);

    QFont font;
    font.setFamily("Arial");
    font.setPixelSize(32);
    font.setWeight(QFont::Bold);
    font.setItalic(false);
    painter->setFont(font);

    int x0 = 550;
    int y0 = 290;
    int dy = 14;
    painter->drawText(x0, y0, "OH2LHE");

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

    font.setItalic(false);
    painter->setFont(font);

    x = 735;
    y = 316;
    painter->drawText(x, y, "Date");
    painter->drawText(x+75, y, "UTC");
    painter->drawText(x+125, y, "MHz");
    painter->drawText(x+172, y, "2-way");
    painter->drawText(x+225, y, "RST");

    dy = 10;
    font.setItalic(false);
    font.setPixelSize(dy);
    painter->setFont(font);
    painter->drawText(710, 275, "Confirming");
    painter->drawText(710, 275+dy+5, "QSO with");

}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");
    if (dialog->exec() != QDialog::Accepted)
            return -1;

    printer.setPageOrientation(QPageLayout::Landscape);

    QPainter aPainter;
    aPainter.begin(&printer);
//    int aLogicalWidth  = printer.width();
//    int aLogicalHeight = printer.height();
//    aPainter.setWindow(0, 0, aLogicalWidth, aLogicalHeight);
//    int aPhysicalWidth  = printer.width();
//    int aPhysicalHeight = printer.height();
//    aPainter.setViewport(0, 0, aPhysicalWidth, aPhysicalHeight);

    // Print all pages
    bool aFirstPage = true;
    for (int aPage = printer.fromPage(); aPage <= printer.toPage(); ++aPage)
    {
        if (!aFirstPage)
            printer.newPage();

        qApp->processEvents();
//        if (aProgress.wasCanceled())
//            break;

        // Print page
        printPage(&aPainter, aPage);

//        aProgress.setValue(aPage);
        aFirstPage = false;
    }

    aPainter.end();
    return app.exec();
}

