/********************************************************************************
** Form generated from reading UI file 'contentDialog_2.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTENTDIALOG_2_H
#define UI_CONTENTDIALOG_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_contentDialog_2
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *contentDialog_2)
    {
        if (contentDialog_2->objectName().isEmpty())
            contentDialog_2->setObjectName(QStringLiteral("contentDialog_2"));
        contentDialog_2->resize(310, 131);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contentDialog_2->sizePolicy().hasHeightForWidth());
        contentDialog_2->setSizePolicy(sizePolicy);
        contentDialog_2->setStyleSheet(QStringLiteral(""));
        verticalLayoutWidget = new QWidget(contentDialog_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 271, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(contentDialog_2);

        QMetaObject::connectSlotsByName(contentDialog_2);
    } // setupUi

    void retranslateUi(QDialog *contentDialog_2)
    {
        contentDialog_2->setWindowTitle(QApplication::translate("contentDialog_2", "\346\217\220\347\244\272", 0));
        label->setText(QApplication::translate("contentDialog_2", "\346\217\220\347\244\272\344\277\241\346\201\257", 0));
        pushButton_2->setText(QApplication::translate("contentDialog_2", "\346\233\264\346\224\271\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200(&G)", 0));
        pushButton->setText(QApplication::translate("contentDialog_2", "\347\241\256\345\256\232(&C)", 0));
    } // retranslateUi

};

namespace Ui {
    class contentDialog_2: public Ui_contentDialog_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTENTDIALOG_2_H
