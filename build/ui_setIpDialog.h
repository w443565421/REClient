/********************************************************************************
** Form generated from reading UI file 'setIpDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETIPDIALOG_H
#define UI_SETIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetIpDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *SetIpDialog)
    {
        if (SetIpDialog->objectName().isEmpty())
            SetIpDialog->setObjectName(QStringLiteral("SetIpDialog"));
        SetIpDialog->resize(312, 135);
        verticalLayoutWidget = new QWidget(SetIpDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 271, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SetIpDialog);

        pushButton_2->setDefault(false);
        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(SetIpDialog);
    } // setupUi

    void retranslateUi(QDialog *SetIpDialog)
    {
        SetIpDialog->setWindowTitle(QApplication::translate("SetIpDialog", "Dialog", 0));
        label->setText(QApplication::translate("SetIpDialog", "\350\257\267\350\276\223\345\205\245\346\234\215\345\212\241\345\231\250\347\232\204ip\345\234\260\345\235\200\357\274\232", 0));
        lineEdit->setText(QString());
        pushButton_2->setText(QApplication::translate("SetIpDialog", "\345\217\226\346\266\210(&C)", 0));
        pushButton->setText(QApplication::translate("SetIpDialog", "\347\241\256\345\256\232(&Y)", 0));
    } // retranslateUi

};

namespace Ui {
    class SetIpDialog: public Ui_SetIpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETIPDIALOG_H
