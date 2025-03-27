#include "mainwindow.h"
#include "ui_mainwindow.h"

#include    <QFileDialog>
#include    <QMessageBox>
#include    "tdialogdata.h"
#include    <QInputDialog>
#include    <QSqlError>
#include    <QTableWidgetItem>
#include    <QTableView>
#include    <QStandardItemModel>


//打开数据表
void MainWindow::selectData()
{
    qryModel=new QSqlQueryModel(this);
    selModel=new QItemSelectionModel(qryModel,this);//选择模型
    ui->tableView->setModel(qryModel);//设置数据模型
    ui->tableView->setSelectionModel(selModel);//设置选择模型

    qryModel->setQuery("SELECT empNo,Name, Gender, Birthday, Province, Department,"
                       "Salary FROM employee order by empNo");//设置查询SQL语句
    if (qryModel->lastError().isValid())//查询出错
    {
        QMessageBox::information(this, "错误", "数据表查询错误,错误信息\n"
                                 +qryModel->lastError().text());
        return;
    }

    QSqlRecord rec=qryModel->record();  //获取空记录，用于获取字段序号

    //    connect(theSelection,&QItemSelectionModel::currentRowChanged,
    //            this, &MainWindow::do_currentRowChanged);


    //设置字段显示标题
    qryModel->setHeaderData(rec.indexOf("empNo"),    Qt::Horizontal, "课程编号");//设置字段标题名
    qryModel->setHeaderData(rec.indexOf("Name"),     Qt::Horizontal, "课程名");
    qryModel->setHeaderData(rec.indexOf("Gender"),   Qt::Horizontal, "课程类型");
    qryModel->setHeaderData(rec.indexOf("Birthday"), Qt::Horizontal, "开课时间");
    qryModel->setHeaderData(rec.indexOf("Province"), Qt::Horizontal, "开设学院");
    qryModel->setHeaderData(rec.indexOf("Department"),   Qt::Horizontal, "考试类型");
    qryModel->setHeaderData(rec.indexOf("Salary"),       Qt::Horizontal, "学分");

    ui->actRecInsert->setEnabled(true);//设置动作按钮状态
    ui->actRecDelete->setEnabled(true);
    ui->actRecEdit->setEnabled(true);
}

void MainWindow::updateRecord(int recNo)
{ //更新一条记录
    QSqlRecord  curRec=qryModel->record(recNo); //获取数据模型的一条记录
    int empNo=curRec.value("EmpNo").toInt();    //获取EmpNo

    QSqlQuery query;
    query.prepare("select * from employee where EmpNo = :ID");
    query.bindValue(":ID",empNo);
    query.exec();
    query.first();
    if (!query.isValid())   //无有效记录
        return;

    curRec=query.record();  //获取当前记录
    TDialogData    *dataDialog=new TDialogData(this); //创建对话框
    Qt::WindowFlags    flags=dataDialog->windowFlags();
    dataDialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint); //对话框固定大小

    dataDialog->setUpdateRecord(curRec);    //更新对话框的数据和界面
    int ret=dataDialog->exec();
    if (ret==QDialog::Accepted)
    {
        QSqlRecord  recData=dataDialog->getRecordData();    //获得对话框返回的记录

        query.prepare("update employee set Name=:Name, Gender=:Gender,"
                      " Birthday=:Birthday,  Province=:Province,"
                      " Department=:Department, Salary=:Salary,"
                      " Memo=:Memo, Photo=:Photo "
                      " where EmpNo = :ID");

        query.bindValue(":Name",    recData.value("Name"));
        query.bindValue(":Gender",  recData.value("Gender"));
        query.bindValue(":Birthday",recData.value("Birthday"));
        query.bindValue(":Province",recData.value("Province"));
        query.bindValue(":Department",  recData.value("Department"));
        query.bindValue(":Salary",  recData.value("Salary"));
        query.bindValue(":Memo",    recData.value("Memo"));
        query.bindValue(":Photo",   recData.value("Photo"));

        query.bindValue(":ID",      empNo);

        if (!query.exec())
            QMessageBox::critical(this, "错误", "记录更新错误\n"+query.lastError().text());
        else
            qryModel->query().exec();   //数据模型重新查询数据，更新tableView显示
    }

    delete dataDialog;      //删除对话框
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);      //不能编辑
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);     //行选择
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);    //单行选择
    ui->tableView->setAlternatingRowColors(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::openDatabase(QString aFile)
{
    DB=QSqlDatabase::addDatabase("QSQLITE"); //添加 SQLITE数据库驱动
    DB.setDatabaseName(aFile);  //设置数据库文件
    if (DB.open())
    {
        selectData();
        return true;
    }
    else
        return false;
}


void MainWindow::on_actOpenDB_triggered()
{
    QString aFile=QFileDialog::getOpenFileName(this,"选择文件","","SQLite数据库(*.db3)");
    if (aFile.isEmpty())
        return;

    DB=QSqlDatabase::addDatabase("QSQLITE"); //添加 SQLITE数据库驱动
    DB.setDatabaseName(aFile);  //设置数据库文件
    if (DB.open())
        selectData();
    else
        QMessageBox::warning(this, "错误", "打开数据库失败");
}

//插入记录
void MainWindow::on_actRecInsert_triggered()
{
    QSqlQuery query;
    query.exec("select * from employee where EmpNo =-1");   //实际查不出记录，只查询字段信息

    QSqlRecord curRec=query.record();   //获取当前记录,实际为空记录
    curRec.setValue("EmpNo",qryModel->rowCount()+1);

    TDialogData    *dataDialog=new TDialogData(this);
    Qt::WindowFlags    flags=dataDialog->windowFlags();
    dataDialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint); //对话框固定大小
    dataDialog->setInsertRecord(curRec); //插入记录

    int ret=dataDialog->exec();
    if (ret==QDialog::Accepted)
    {
        QSqlRecord  recData=dataDialog->getRecordData();
        query.prepare("INSERT INTO employee (EmpNo,Name,Gender,Birthday,Province,"
                      " Department,Salary,Memo,Photo) "
                      " VALUES(:EmpNo,:Name, :Gender,:Birthday,:Province,"
                      " :Department,:Salary,:Memo,:Photo)");

        query.bindValue(":EmpNo",recData.value("EmpNo"));
        query.bindValue(":Name",recData.value("Name"));
        query.bindValue(":Gender",recData.value("Gender"));
        query.bindValue(":Birthday",recData.value("Birthday"));
        query.bindValue(":Province",recData.value("Province"));
        query.bindValue(":Department",recData.value("Department"));
        query.bindValue(":Salary",recData.value("Salary"));
        query.bindValue(":Memo",recData.value("Memo"));
        query.bindValue(":Photo",recData.value("Photo"));

        if (!query.exec())
            QMessageBox::critical(this, "错误", "插入记录错误\n"+query.lastError().text());
        else //插入，删除记录后需要重新设置SQL语句查询
        {
            QString sqlStr=qryModel->query().executedQuery();   //执行过的SELECT语句
            qryModel->setQuery(sqlStr);         //重新查询数据
        }
    }

    delete dataDialog;
}

//删除当前记录
void MainWindow::on_actRecDelete_triggered()
{
    int curRecNo=selModel->currentIndex().row();
    QSqlRecord  curRec=qryModel->record(curRecNo); //获取当前记录
    if (curRec.isEmpty()) //当前为空记录
        return;

    int empNo=curRec.value("EmpNo").toInt();    //获取编号
    QSqlQuery query;
    query.prepare("delete  from employee where EmpNo = :ID");
    query.bindValue(":ID",empNo);

    if (!query.exec())
        QMessageBox::critical(this, "错误", "删除记录出现错误\n"+query.lastError().text());
    else //插入，删除记录后需要重新设置SQL语句查询
    {
        QString sqlStr=qryModel->query().executedQuery();//  执行过的SELECT语句
        qryModel->setQuery(sqlStr);         //重新查询数据
    }
}


void MainWindow::on_actRecEdit_triggered()
{//编辑当前记录
    int curRecNo=selModel->currentIndex().row();
    updateRecord(curRecNo);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{ //tableView上双击,编辑当前记录
    int curRecNo=index.row();
    updateRecord(curRecNo);
}

//遍历记录
void MainWindow::on_actScan_triggered()
{

//    /////////直接执行SQL语句的方式
    QSqlQuery qryUpdate;
    qryUpdate.exec("UPDATE employee SET Salary=Salary+10");

    qryModel->query().exec();   //数据模型重新查询数据，更新tableView的显示
    QMessageBox::information(this, "提示", "计算完毕");
}

void MainWindow::on_actSQLtest_triggered()
{




}


void MainWindow::on_action_triggered()
{
    //输入编号，查询对应的记录
    bool ok;
    int empNo=QInputDialog::getInt(this,"输入编号","编号",1,1,9999,1,&ok);
    if (!ok)
        return;
    //查询对应的记录
    QSqlQuery query;
    query.prepare("select * from employee where EmpNo = :ID");
    query.bindValue(":ID",empNo);
    query.exec();
    query.first();
    if (!query.isValid())   //无有效记录
        return;
    else
    {
        QSqlRecord  curRec=query.record();  //获取当前记录
        TDialogData    *dataDialog=new TDialogData(this); //创建对话框
        Qt::WindowFlags    flags=dataDialog->windowFlags();
        dataDialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint); //对话框固定大小

        dataDialog->setUpdateRecord(curRec);    //更新对话框的数据和界面
        dataDialog->exec();
        delete dataDialog;      //删除对话框
    }



}


void MainWindow::on_action_2_triggered()
{
    //使用文件对话框选择txt文件
    //txt文件的格式如下
    //学号 姓名 选中课程编号 选中课程名 课程成绩
    //将txt文件中的数据显示到tableView_2中
    //使用QStandardItemModel模型
    //开始实现
    QString filename = QFileDialog::getOpenFileName(this,"选择文件","","TXT文件(*.txt)");
    if(filename.isEmpty())
    {
        return;
    }
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","打开文件失败");
        return;
    }
    QTextStream in(&file);
    QStringList list;

    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,"学号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"选中课程编号");
    model->setHeaderData(3,Qt::Horizontal,"选中课程名");
    model->setHeaderData(4,Qt::Horizontal,"课程成绩");
    //逐行读取文件内容，直到文件结束
    while(!in.atEnd())
    {
        QString line = in.readLine();
        list = line.split(" ");
        model->setRowCount(model->rowCount()+1);
        for(int i=0;i<5;i++)//将list中的内容写入model
        {
            model->setData(model->index(model->rowCount()-1,i),list.at(i));
        }
    }
    file.close();
    ui->tableView->setModel(model);
    ui->tableView->show();




}


void MainWindow::on_action_3_triggered()
{
    //先检测当前tableView中为课程信息还是学生信息
    //如果是课程信息，提示用户未打开学生信息
    //如果是学生信息，则提示用户先输入学号
    //再提示用户输入课程编号，检查课程编号在数据库文件中是否存在
    //如果不存在，提示用户输入的课程编号不存在
    //如果存在，则再检测该学号是否已经选过该课程
    //如果选过，则提示用户选课失败
    //如果未选过，则再检测该课程是否已经选满
    //如果选满，则提示用户选课失败
    //再提示用户要输入的名字
    //再提示用户要输入的成绩
    //将输入的信息写入txt文件中
    //然后更新数据库文件中该行对应的Memo字段的值，更新为课程数量减去1
    //提示用户选课成功
    //开始实现
    if(ui->tableView->model()->headerData(0,Qt::Horizontal)=="课程编号")
    {
        QMessageBox::warning(this,"错误","未打开学生信息");
        return;
    }
    int empNo = QInputDialog::getInt(this,"输入学号","学号",1,1,9999,1);
    //在txt文件中查找该学号对应的所有选课信息
    QFile file("10.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","打开文件失败");
        return;
    }
    QTextStream in(&file);
    QString line;
    QStringList list;
    int num = 0;
    while(!in.atEnd())
    {
        line = in.readLine();
        list = line.split(" ");
        if(list.at(0).toInt()==empNo)
        {
            num++;
        }
    }
    file.close();
    int courseNo = QInputDialog::getInt(this,"输入课程编号","课程编号",1,1,9999,1);
    //在txt文件中查找该课程编号对应的所有选课信息
    QFile file2("10.txt");
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","打开文件失败");
        return;
    }
    QTextStream in2(&file2);
    QString line2;
    QStringList list2;
    int num2 = 0;
    //在数据库文件中查找该课程编号是否存在
    QSqlQuery query3;
    query3.prepare("select * from employee where EmpNo = :ID");
    query3.bindValue(":ID",courseNo);
    query3.exec();
    query3.first();
    if(!query3.isValid())
    {
        QMessageBox::warning(this,"错误","输入的课程编号不存在");
        return;
    }
    if(num!=0)
    {
        QMessageBox::warning(this,"错误","选课失败");
        return;
    }
    QSqlQuery query;
    query.prepare("select * from employee where EmpNo = :ID");
    query.bindValue(":ID",courseNo);
    query.exec();
    query.first();
    if(!query.isValid())
    {
        QMessageBox::warning(this,"错误","不能重复选课");
        return;
    }
    if(query.value("Memo").toInt()==0)
    {
        QMessageBox::warning(this,"错误","选课失败");
        return;
    }
    QString name = QInputDialog::getText(this,"输入名字","名字");
    int score = QInputDialog::getInt(this,"输入成绩","成绩",60,0,100,1);
    //将输入的信息写入txt文件中
    QFile file3("10.txt");
    if(!file3.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        QMessageBox::warning(this,"错误","打开文件失败");
        return;
    }
    QTextStream out(&file3);
    //学号 姓名 选中课程编号 选中课程名 课程成绩
    out<<empNo<<" "<<name<<" "<<courseNo<<" "<<query.value("Name").toString()<<" "<<score<<"\n";
    file3.close();
    //然后更新数据库文件中该行对应的Memo字段的值，更新为课程数量减去1
    QSqlQuery query2;
    query2.prepare("update employee set Memo = Memo - 1 where EmpNo = :ID");
    query2.bindValue(":ID",courseNo);
    query2.exec();
    QMessageBox::information(this,"提示","选课成功");
    //更新tableView
    on_action_2_triggered();
    ui->tableView->show();
}


void MainWindow::on_action_4_triggered()
{
    //先检测当前tableView中为课程信息还是学生信息
    //如果是课程信息，提示用户未打开学生信息
    //如果是学生信息，则提示用户先输入学号
    //检测该学号是否已经选过课程
    //如果未选过，则提示用户未选课，无法退课
    //如果选过，则再提示用户输入课程编号
    //检测该学号是否选过该课程
    //如果选过，则提示用户退课成功
    //如果未选过，则提示用户未选该课程，无法退课
    //然后更新数据库文件中该行对应的Memo字段的值，更新为课程数量加上1
    //开始实现
    if(ui->tableView->model()->headerData(0,Qt::Horizontal)=="课程编号")
    {
        QMessageBox::warning(this,"错误","未打开学生信息");
        return;
    }
    int empNo = QInputDialog::getInt(this,"输入学号","学号",1,1,9999,1);
    //在txt文件中查找该学号对应的所有选课信息
    QFile file("10.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","打开文件失败");
        return;
    }
    QTextStream in(&file);
    QString line;
    QStringList list;
    int num = 0;
    while(!in.atEnd())
    {
        line = in.readLine();
        list = line.split(" ");
        if(list.at(0).toInt()==empNo)
        {
            num++;
        }
    }
    file.close();
    if(num==0)
    {
        QMessageBox::warning(this,"错误","未选课，无法退课");
        return;
    }
    int courseNo = QInputDialog::getInt(this,"输入课程编号","课程编号",1,1,9999,1);
    //在txt文件中查找该课程编号对应的所有选课信息
    QFile file2("10.txt");
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","打开文件失败");
        return;
    }
    QTextStream in2(&file2);
    QString line2;
    QStringList list2;
    int num2 = 0;
    while(!in2.atEnd())
    {
        line2 = in2.readLine();
        list2 = line2.split(" ");
        if(list2.at(2).toInt()==courseNo)
        {
            num2++;
        }
    }
    file2.close();
    if(num2==0)
    {
        QMessageBox::warning(this,"错误","未选该课程，无法退课");
        return;
    }
    QSqlQuery query;
    query.prepare("select * from employee where EmpNo = :ID");
    query.bindValue(":ID",courseNo);
    query.exec();
    query.first();
    if(!query.isValid())
    {
        QMessageBox::warning(this,"错误","退课成功");
        return;
    }
    //然后更新数据库文件中该行对应的Memo字段的值，更新为课程数量加上1
    QSqlQuery query2;
    query2.prepare("update employee set Memo = Memo + 1 where EmpNo = :ID");
    query2.bindValue(":ID",courseNo);
    query2.exec();
    QMessageBox::information(this,"提示","退课成功");
    //删除txt文件中该行

    QFile file3("10.txt");
    if(!file3.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","打开文件失败");
        return;
    }
    QTextStream in3(&file3);
    QString line3;
    QStringList list3;
    QString str;
    while(!in3.atEnd())
    {
        line3 = in3.readLine();
        list3 = line3.split(" ");
        if(list3.at(0).toInt()!=empNo||list3.at(2).toInt()!=courseNo)
        {
            str += line3 + "\n";
        }
    }
    file3.close();
    QFile file4("10.txt");
    if(!file4.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","打开文件失败");
        return;
    }
    QTextStream out(&file4);
    out<<str;
    file4.close();
    //更新tableView
    on_action_2_triggered();
    ui->tableView->show();
}

