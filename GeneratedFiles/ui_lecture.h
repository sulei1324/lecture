/********************************************************************************
** Form generated from reading UI file 'lecture.ui'
**
** Created: Thu Jan 7 09:48:12 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE_H
#define UI_LECTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lectureClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QLabel *label_6;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_6;

    void setupUi(QMainWindow *lectureClass)
    {
        if (lectureClass->objectName().isEmpty())
            lectureClass->setObjectName(QString::fromUtf8("lectureClass"));
        lectureClass->resize(611, 643);
        centralWidget = new QWidget(lectureClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 571, 91));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 120, 100, 30));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 120, 120, 30));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 120, 75, 30));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 170, 100, 30));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 170, 120, 30));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 170, 75, 30));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 220, 200, 30));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 220, 75, 30));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 270, 200, 30));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 270, 75, 30));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 320, 200, 30));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 320, 75, 30));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 370, 581, 261));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(400, 320, 75, 30));
        lectureClass->setCentralWidget(centralWidget);

        retranslateUi(lectureClass);

        QMetaObject::connectSlotsByName(lectureClass);
    } // setupUi

    void retranslateUi(QMainWindow *lectureClass)
    {
        lectureClass->setWindowTitle(QApplication::translate("lectureClass", "Query System", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("lectureClass", "Notice: \nthe lecture and lecture_grade txt file should be \nput in the exe file, and should be coded by UTF-8; \nthe GPA txt file will be saved in the exe file as the GPA.txt.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("lectureClass", "Student Number:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("lectureClass", "Check", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("lectureClass", "Student Name:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("lectureClass", "Check", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("lectureClass", "Show Unpassed Imformation", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("lectureClass", "Check", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("lectureClass", "Show GPA Imformation(unsorted)", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("lectureClass", "Check", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("lectureClass", "Show GPA Imformation(sorted)", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("lectureClass", "Check", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("lectureClass", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class lectureClass: public Ui_lectureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE_H
