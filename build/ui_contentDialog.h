/********************************************************************************
** Form generated from reading UI file 'contentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTENTDIALOG_H
#define UI_CONTENTDIALOG_H

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

class Ui_contentDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *contentDialog)
    {
        if (contentDialog->objectName().isEmpty())
            contentDialog->setObjectName(QStringLiteral("contentDialog"));
        contentDialog->resize(310, 131);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contentDialog->sizePolicy().hasHeightForWidth());
        contentDialog->setSizePolicy(sizePolicy);
        contentDialog->setStyleSheet(QStringLiteral(""));
        verticalLayoutWidget = new QWidget(contentDialog);
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

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(contentDialog);

        QMetaObject::connectSlotsByName(contentDialog);
    } // setupUi

    void retranslateUi(QDialog *contentDialog)
    {
        contentDialog->setWindowTitle(QApplication::translate("contentDialog", "\346\217\220\347\244\272", 0));
        label->setText(QApplication::translate("contentDialog", "\346\217\220\347\244\272\344\277\241\346\201\257", 0));
        pushButton->setText(QApplication::translate("contentDialog", "\347\241\256\345\256\232(&C)", 0));
    } // retranslateUi

};

namespace Ui {
    class contentDialog: public Ui_contentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTENTDIALOG_H
