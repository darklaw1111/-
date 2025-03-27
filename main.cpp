#include "mainwindow.h"

#include <QApplication>
#include "tdialoglogin.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TDialogLogin *dlgLogin=new TDialogLogin;
    if(dlgLogin->exec()==QDialog::Accepted)
    {
        if(argc>1)
        {
            QString filename=argv[1];   //获取文件名
            w.openDatabase(filename);
        }

        w.show();
        return a.exec();
    }
    else{
        return 0;
    }
}
