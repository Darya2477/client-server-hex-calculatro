/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *pushButton_22;
    QPushButton *pushButton_32;
    QPushButton *pushButton_26;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_16;
    QPushButton *pushButton_3;
    QPushButton *pushButton_14;
    QPushButton *pushButton_24;
    QPushButton *pushButton_13;
    QPushButton *pushButton_21;
    QPushButton *pushButton_31;
    QPushButton *pushButton_11;
    QPushButton *pushButton_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_23;
    QPushButton *pushButton_33;
    QPushButton *pushButton_19;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_18;
    QPushButton *pushButton_29;
    QPushButton *pushButton_10;
    QPushButton *pushButton_25;
    QPushButton *pushButton;
    QPushButton *pushButton_20;
    QPushButton *pushButton_28;
    QPushButton *pushButton_17;
    QPushButton *pushButton_27;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_15;
    QPushButton *pushButton_30;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1071, 606);
        MainWindow->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(119, 170, 631, 355));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:rgb(237, 51, 59)"));
        label->setTextFormat(Qt::MarkdownText);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(26);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_22 = new QPushButton(layoutWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton_22);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setMinimumSize(QSize(40, 40));
        QFont font2;
        font2.setPointSize(20);
        pushButton_22->setFont(font2);

        gridLayout->addWidget(pushButton_22, 4, 7, 1, 1);

        pushButton_32 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_32);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        pushButton_32->setMinimumSize(QSize(40, 40));
        pushButton_32->setFont(font2);

        gridLayout->addWidget(pushButton_32, 4, 0, 1, 1);

        pushButton_26 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_26);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));
        pushButton_26->setMinimumSize(QSize(40, 40));
        pushButton_26->setFont(font2);

        gridLayout->addWidget(pushButton_26, 0, 8, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_9);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(40, 40));
        pushButton_9->setFont(font2);

        gridLayout->addWidget(pushButton_9, 5, 2, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(40, 40));
        pushButton_4->setFont(font2);

        gridLayout->addWidget(pushButton_4, 1, 4, 1, 1);

        pushButton_16 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_16);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(40, 40));
        pushButton_16->setFont(font2);

        gridLayout->addWidget(pushButton_16, 3, 6, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(40, 40));
        pushButton_3->setFont(font2);

        gridLayout->addWidget(pushButton_3, 4, 4, 1, 1);

        pushButton_14 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_14);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(40, 40));
        pushButton_14->setFont(font2);

        gridLayout->addWidget(pushButton_14, 1, 6, 1, 1);

        pushButton_24 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_24);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        pushButton_24->setMinimumSize(QSize(40, 40));
        pushButton_24->setFont(font2);

        gridLayout->addWidget(pushButton_24, 4, 8, 1, 1);

        pushButton_13 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_13);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(40, 40));
        pushButton_13->setFont(font2);

        gridLayout->addWidget(pushButton_13, 0, 6, 1, 1);

        pushButton_21 = new QPushButton(layoutWidget);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setMinimumSize(QSize(40, 40));
        pushButton_21->setFont(font2);

        gridLayout->addWidget(pushButton_21, 5, 7, 1, 2);

        pushButton_31 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_31);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
        pushButton_31->setMinimumSize(QSize(40, 40));
        pushButton_31->setFont(font2);

        gridLayout->addWidget(pushButton_31, 3, 1, 1, 1);

        pushButton_11 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_11);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(40, 40));
        pushButton_11->setFont(font2);

        gridLayout->addWidget(pushButton_11, 1, 7, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(40, 40));
        pushButton_2->setFont(font2);

        gridLayout->addWidget(pushButton_2, 3, 2, 1, 1);

        pushButton_12 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_12);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(40, 40));
        pushButton_12->setFont(font2);
        pushButton_12->setStyleSheet(QString::fromUtf8("color:rgb(237, 51, 59)"));

        gridLayout->addWidget(pushButton_12, 0, 0, 1, 1);

        pushButton_23 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_23);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(40, 40));
        pushButton_23->setFont(font2);

        gridLayout->addWidget(pushButton_23, 3, 7, 1, 1);

        pushButton_33 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_33);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        pushButton_33->setMinimumSize(QSize(40, 40));
        pushButton_33->setFont(font2);

        gridLayout->addWidget(pushButton_33, 4, 1, 1, 1);

        pushButton_19 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_19);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setMinimumSize(QSize(40, 40));
        pushButton_19->setFont(font2);

        gridLayout->addWidget(pushButton_19, 5, 4, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_8);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(40, 40));
        pushButton_8->setFont(font2);

        gridLayout->addWidget(pushButton_8, 4, 2, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_6);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(40, 40));
        pushButton_6->setFont(font2);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_18 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_18);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(40, 40));
        pushButton_18->setFont(font2);

        gridLayout->addWidget(pushButton_18, 5, 6, 1, 1);

        pushButton_29 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_29);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
        pushButton_29->setMinimumSize(QSize(40, 40));
        pushButton_29->setFont(font2);

        gridLayout->addWidget(pushButton_29, 1, 1, 1, 1);

        pushButton_10 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_10);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(40, 40));
        pushButton_10->setFont(font2);

        gridLayout->addWidget(pushButton_10, 3, 4, 1, 1);

        pushButton_25 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_25);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
        pushButton_25->setMinimumSize(QSize(40, 40));
        pushButton_25->setFont(font2);

        gridLayout->addWidget(pushButton_25, 3, 8, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(40, 40));
        pushButton->setFont(font2);

        gridLayout->addWidget(pushButton, 3, 3, 1, 1);

        pushButton_20 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_20);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setMinimumSize(QSize(40, 40));
        pushButton_20->setFont(font2);

        gridLayout->addWidget(pushButton_20, 0, 7, 1, 1);

        pushButton_28 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_28);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));
        pushButton_28->setMinimumSize(QSize(40, 40));
        pushButton_28->setFont(font2);

        gridLayout->addWidget(pushButton_28, 1, 0, 1, 1);

        pushButton_17 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_17);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(40, 40));
        pushButton_17->setFont(font2);

        gridLayout->addWidget(pushButton_17, 4, 6, 1, 1);

        pushButton_27 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_27);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
        pushButton_27->setMinimumSize(QSize(40, 40));
        pushButton_27->setFont(font2);

        gridLayout->addWidget(pushButton_27, 1, 8, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(40, 40));
        pushButton_5->setFont(font2);

        gridLayout->addWidget(pushButton_5, 1, 3, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_7);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(40, 40));
        pushButton_7->setFont(font2);

        gridLayout->addWidget(pushButton_7, 4, 3, 1, 1);

        pushButton_15 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_15);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(40, 40));
        pushButton_15->setFont(font1);

        gridLayout->addWidget(pushButton_15, 5, 3, 1, 1);

        pushButton_30 = new QPushButton(layoutWidget);
        buttonGroup->addButton(pushButton_30);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
        pushButton_30->setMinimumSize(QSize(40, 40));
        pushButton_30->setFont(font2);

        gridLayout->addWidget(pushButton_30, 3, 0, 1, 1);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(40, 40));
        QFont font3;
        font3.setPointSize(16);
        groupBox->setFont(font3);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setEnabled(true);
        radioButton->setGeometry(QRect(20, 20, 145, 40));
        radioButton->setMinimumSize(QSize(20, 40));
        QFont font4;
        font4.setPointSize(10);
        radioButton->setFont(font4);
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 20, 145, 40));
        radioButton_2->setMinimumSize(QSize(20, 40));
        radioButton_2->setFont(font4);

        gridLayout->addWidget(groupBox, 0, 1, 1, 4);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1071, 27));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_26->setToolTip(QCoreApplication::translate("MainWindow", "ti", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "a^b", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\342\235\214", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "lg", nullptr));
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "\320\237", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_27->setToolTip(QCoreApplication::translate("MainWindow", "ti", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_27->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \321\201\321\207\320\270\321\201\321\202\320\273\320\265\320\275\320\270\321\217", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\321\201\321\217\321\202\320\270\321\207\320\275\320\260\321\217", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\320\250\320\265\321\201\321\202\320\275\320\260\320\264\321\206\320\260\321\202\320\265\321\200\320\270\321\207\320\275\320\260\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
