/********************************************************************************
** Form generated from reading UI file 'tdialogdata.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDIALOGDATA_H
#define UI_TDIALOGDATA_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TDialogData
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnSetPhoto;
    QPushButton *btnClearPhoto;
    QPushButton *btnOK;
    QPushButton *btnClose;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *editMemo;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinEmpNo;
    QLabel *label_2;
    QLineEdit *editName;
    QLabel *label_3;
    QComboBox *comboSex;
    QLabel *label_5;
    QDateEdit *editBirth;
    QLabel *label_7;
    QComboBox *comboProvince;
    QLabel *label_6;
    QComboBox *comboDep;
    QLabel *label_12;
    QSpinBox *spinSalary;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *LabPhoto;

    void setupUi(QDialog *TDialogData)
    {
        if (TDialogData->objectName().isEmpty())
            TDialogData->setObjectName(QString::fromUtf8("TDialogData"));
        TDialogData->resize(609, 447);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        TDialogData->setFont(font);
        layoutWidget = new QWidget(TDialogData);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(450, 10, 137, 216));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSetPhoto = new QPushButton(layoutWidget);
        btnSetPhoto->setObjectName(QString::fromUtf8("btnSetPhoto"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/00.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetPhoto->setIcon(icon);

        verticalLayout_2->addWidget(btnSetPhoto);

        btnClearPhoto = new QPushButton(layoutWidget);
        btnClearPhoto->setObjectName(QString::fromUtf8("btnClearPhoto"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/103.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearPhoto->setIcon(icon1);

        verticalLayout_2->addWidget(btnClearPhoto);

        btnOK = new QPushButton(layoutWidget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon2);

        verticalLayout_2->addWidget(btnOK);

        btnClose = new QPushButton(layoutWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon3);

        verticalLayout_2->addWidget(btnClose);

        groupBox_3 = new QGroupBox(TDialogData);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 250, 406, 151));
        groupBox_3->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, -1, 3, -1);
        editMemo = new QPlainTextEdit(groupBox_3);
        editMemo->setObjectName(QString::fromUtf8("editMemo"));
        editMemo->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(editMemo);

        layoutWidget1 = new QWidget(TDialogData);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(5, 5, 430, 229));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinEmpNo = new QSpinBox(groupBox_2);
        spinEmpNo->setObjectName(QString::fromUtf8("spinEmpNo"));
        spinEmpNo->setMinimum(1);
        spinEmpNo->setMaximum(10000);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinEmpNo);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        editName = new QLineEdit(groupBox_2);
        editName->setObjectName(QString::fromUtf8("editName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editName);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboSex = new QComboBox(groupBox_2);
        comboSex->addItem(QString());
        comboSex->addItem(QString());
        comboSex->addItem(QString());
        comboSex->setObjectName(QString::fromUtf8("comboSex"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboSex);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        editBirth = new QDateEdit(groupBox_2);
        editBirth->setObjectName(QString::fromUtf8("editBirth"));
        editBirth->setDateTime(QDateTime(QDate(2024, 1, 5), QTime(0, 0, 0)));
        editBirth->setCalendarPopup(true);
        editBirth->setDate(QDate(2024, 1, 5));

        formLayout->setWidget(3, QFormLayout::FieldRole, editBirth);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        comboProvince = new QComboBox(groupBox_2);
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->setObjectName(QString::fromUtf8("comboProvince"));
        comboProvince->setEditable(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, comboProvince);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        comboDep = new QComboBox(groupBox_2);
        comboDep->addItem(QString());
        comboDep->addItem(QString());
        comboDep->setObjectName(QString::fromUtf8("comboDep"));
        comboDep->setEditable(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, comboDep);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_12);

        spinSalary = new QSpinBox(groupBox_2);
        spinSalary->setObjectName(QString::fromUtf8("spinSalary"));
        spinSalary->setEnabled(true);
        spinSalary->setMinimum(0);
        spinSalary->setMaximum(50000);
        spinSalary->setSingleStep(1);
        spinSalary->setValue(1);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinSalary);


        horizontalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(layoutWidget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabPhoto = new QLabel(groupBox);
        LabPhoto->setObjectName(QString::fromUtf8("LabPhoto"));
        LabPhoto->setMinimumSize(QSize(150, 0));
        LabPhoto->setMaximumSize(QSize(350, 16777215));

        verticalLayout->addWidget(LabPhoto);


        horizontalLayout->addWidget(groupBox);

#if QT_CONFIG(shortcut)
        label->setBuddy(spinEmpNo);
        label_2->setBuddy(editName);
        label_3->setBuddy(comboSex);
        label_5->setBuddy(editBirth);
        label_7->setBuddy(comboProvince);
        label_6->setBuddy(comboDep);
        label_12->setBuddy(spinSalary);
#endif // QT_CONFIG(shortcut)

        retranslateUi(TDialogData);
        QObject::connect(btnClose, &QPushButton::clicked, TDialogData, qOverload<>(&QDialog::reject));
        QObject::connect(btnOK, &QPushButton::clicked, TDialogData, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(TDialogData);
    } // setupUi

    void retranslateUi(QDialog *TDialogData)
    {
        TDialogData->setWindowTitle(QCoreApplication::translate("TDialogData", "\347\274\226\350\276\221\350\256\260\345\275\225", nullptr));
        btnSetPhoto->setText(QCoreApplication::translate("TDialogData", "\345\257\274\345\205\245\347\205\247\347\211\207", nullptr));
        btnClearPhoto->setText(QCoreApplication::translate("TDialogData", "\346\270\205\351\231\244\347\205\247\347\211\207", nullptr));
        btnOK->setText(QCoreApplication::translate("TDialogData", "\347\241\256  \345\256\232", nullptr));
        btnClose->setText(QCoreApplication::translate("TDialogData", "\345\217\226  \346\266\210", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("TDialogData", "\345\211\251\344\275\231\345\220\215\351\242\235\351\207\217", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("TDialogData", "\350\257\276\347\250\213\347\274\226\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("TDialogData", "\350\257\276\347\250\213\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("TDialogData", "\350\257\276\347\250\213\347\261\273\345\236\213", nullptr));
        comboSex->setItemText(0, QCoreApplication::translate("TDialogData", "\345\277\205\344\277\256\350\257\276", nullptr));
        comboSex->setItemText(1, QCoreApplication::translate("TDialogData", "\351\200\211\344\277\256\350\257\276", nullptr));
        comboSex->setItemText(2, QCoreApplication::translate("TDialogData", "\351\207\215\344\277\256\350\257\276", nullptr));

        label_5->setText(QCoreApplication::translate("TDialogData", "\345\274\200\350\257\276\346\227\266\351\227\264", nullptr));
        editBirth->setDisplayFormat(QCoreApplication::translate("TDialogData", "yyyy-MM-dd", nullptr));
        label_7->setText(QCoreApplication::translate("TDialogData", "\345\274\200\350\256\276\345\255\246\351\231\242", nullptr));
        comboProvince->setItemText(0, QCoreApplication::translate("TDialogData", "\351\251\254\345\205\213\346\200\235\345\255\246\351\231\242", nullptr));
        comboProvince->setItemText(1, QCoreApplication::translate("TDialogData", "\347\220\206\345\255\246\351\231\242", nullptr));
        comboProvince->setItemText(2, QCoreApplication::translate("TDialogData", "\350\256\241\347\256\227\346\234\272\345\255\246\351\231\242", nullptr));
        comboProvince->setItemText(3, QCoreApplication::translate("TDialogData", "\345\244\226\345\233\275\350\257\255\345\255\246\351\231\242", nullptr));
        comboProvince->setItemText(4, QCoreApplication::translate("TDialogData", "\347\224\265\346\260\224\345\255\246\351\231\242", nullptr));
        comboProvince->setItemText(5, QCoreApplication::translate("TDialogData", "\350\207\252\345\212\250\345\214\226\345\255\246\351\231\242", nullptr));

        comboProvince->setCurrentText(QCoreApplication::translate("TDialogData", "\351\251\254\345\205\213\346\200\235\345\255\246\351\231\242", nullptr));
        label_6->setText(QCoreApplication::translate("TDialogData", "\350\200\203\350\257\225\347\261\273\345\236\213", nullptr));
        comboDep->setItemText(0, QCoreApplication::translate("TDialogData", "\351\227\255\345\215\267", nullptr));
        comboDep->setItemText(1, QCoreApplication::translate("TDialogData", "\345\274\200\345\215\267", nullptr));

        comboDep->setCurrentText(QCoreApplication::translate("TDialogData", "\351\227\255\345\215\267", nullptr));
        label_12->setText(QCoreApplication::translate("TDialogData", "\345\255\246\345\210\206", nullptr));
        spinSalary->setPrefix(QString());
        groupBox->setTitle(QCoreApplication::translate("TDialogData", "\347\205\247  \347\211\207", nullptr));
        LabPhoto->setText(QCoreApplication::translate("TDialogData", "dbLabPhoto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TDialogData: public Ui_TDialogData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDIALOGDATA_H
