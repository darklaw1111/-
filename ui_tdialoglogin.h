/********************************************************************************
** Form generated from reading UI file 'tdialoglogin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDIALOGLOGIN_H
#define UI_TDIALOGLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TDialogLogin
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *editUser;
    QLabel *label_3;
    QLineEdit *editPSWD;
    QCheckBox *chkBoxSave;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *TDialogLogin)
    {
        if (TDialogLogin->objectName().isEmpty())
            TDialogLogin->setObjectName(QString::fromUtf8("TDialogLogin"));
        TDialogLogin->resize(520, 360);
        TDialogLogin->setMaximumSize(QSize(520, 360));
        QFont font;
        font.setPointSize(10);
        TDialogLogin->setFont(font);
        verticalLayout = new QVBoxLayout(TDialogLogin);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(TDialogLogin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(520, 334));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/splash2.jpg")));
        label->setScaledContents(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(TDialogLogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        editUser = new QLineEdit(TDialogLogin);
        editUser->setObjectName(QString::fromUtf8("editUser"));

        horizontalLayout->addWidget(editUser);

        label_3 = new QLabel(TDialogLogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        editPSWD = new QLineEdit(TDialogLogin);
        editPSWD->setObjectName(QString::fromUtf8("editPSWD"));
        editPSWD->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(editPSWD);

        chkBoxSave = new QCheckBox(TDialogLogin);
        chkBoxSave->setObjectName(QString::fromUtf8("chkBoxSave"));

        horizontalLayout->addWidget(chkBoxSave);

        horizontalSpacer_3 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnOK = new QPushButton(TDialogLogin);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon);

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(TDialogLogin);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon1);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TDialogLogin);
        QObject::connect(btnCancel, &QPushButton::clicked, TDialogLogin, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TDialogLogin);
    } // setupUi

    void retranslateUi(QDialog *TDialogLogin)
    {
        TDialogLogin->setWindowTitle(QCoreApplication::translate("TDialogLogin", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("TDialogLogin", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("TDialogLogin", "\345\257\206 \347\240\201", nullptr));
        chkBoxSave->setText(QCoreApplication::translate("TDialogLogin", "\344\277\235\345\255\230\347\224\250\346\210\267\345\220\215", nullptr));
        btnOK->setText(QCoreApplication::translate("TDialogLogin", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("TDialogLogin", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TDialogLogin: public Ui_TDialogLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDIALOGLOGIN_H
