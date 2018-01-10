#include "mainwindow.h"
#include <QApplication>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

void printPage(QPainter* thePainter, int thePage)
{
    // Set pen
    QPen aPen;
    aPen.setColor(Qt::black);
    aPen.setWidth(0);
    aPen.setStyle(Qt::SolidLine);
    thePainter->setPen(aPen);

    // Set brush
//    QBrush aBrush;
//    aBrush.setColor(Qt::black);
//    aBrush.setStyle(Qt::SolidPattern);
//    thePainter->setBrush(aBrush);

    // Set font
    QFont aFont;
    aFont.setFamily("Arial");
    aFont.setPixelSize(10); // ??? how to set the font size to 1cm ???
    aFont.setWeight(QFont::Normal);
    aFont.setItalic(false);
    thePainter->setFont(aFont);

    // Draw line
//    thePainter->drawLine(QPoint(1000, 1000), QPoint(5000, 5000));

    // Print a rectangle
    thePainter->drawRect(QRect(1, 1, 80, 130));

    // Print a text
    thePainter->drawText(520, 240, "(520,240)");
    thePainter->drawText(1020, 550, "(1020,550)");

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

