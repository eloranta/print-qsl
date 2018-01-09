#include "mainwindow.h"
#include <QApplication>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

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

    QPainter painter;
    painter.begin(&printer);
    painter.drawRect(0, 0, 100, 100);   //drawText(100, 100, 500, 500, Qt::AlignLeft|Qt::AlignTop, "hello");


    painter.end();

    return app.exec();
}
