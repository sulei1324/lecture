#ifndef LECTURE_H
#define LECTURE_H

#include <QtGui/QMainWindow>
#include "ui_lecture.h"
#include <QtGui/QApplication>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QTextCodec>
#include <QByteArray>
#include <QLabel>
#include <iostream>
#include <fstream>
#include <QStringList>
#include <QList>
#include <QMap>
#include <QtAlgorithms>



class Student
{
    QString name;
    QString student_number;
    QStringList grade_str_list;
    QList<int> grade_list;
    int whole_grade;
    int learned_lect_num;
    int unpassed_lect_num;
    double learned_lect_credit;
    double unpassed_lect_credit;
    double gpa;
    void strList2intList();
    QStringList lect_name_list;
    double countGPA(QMap<QString, double> lect_credit_dict, QMap<QString, double> lect_stat_dict);
    double countLearnedLectCredit(QMap<QString, double> lect_credit_dict, QMap<QString, double> lect_stat_dict);
    double countUnPassedLectCredit(QMap<QString, double> lect_credit_dict, QMap<QString, double> lect_stat_dict);


public:
    Student();
    Student(QString std_name, QString std_num, QStringList gradeList, QMap<QString, double> lect_credit_dict, QMap<QString, double> lect_stat_dict, QStringList class_lect_list);
    ~Student();
    QString getNumber();
    int getLearnedLectNum();
    int getUnPassedLectNum();
    int getWholeGrade();
    double getGPA();
    double getLearnedLectCredit();
    double getUnPassedLectCredit();
    QStringList getList();
    QList<int> getGradeList();
    QString getName();
};

bool compareGPA(Student std1, Student std2);

class lecture : public QMainWindow
{
    Q_OBJECT

public:
    lecture(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~lecture();
    void outputStdInfo();

public slots:
    void button1OnClicked();
    void button2OnClicked();
    void button3OnClicked();
    void button4OnClicked();
    void button5OnClicked();
    void button6OnClicked();

private:
    Ui::lectureClass ui;
    QList<Student> std_list;
    QMap<QString, double> lect_credit_dict;
    QMap<QString, double> lect_stat_dict;
    QMap<QString, double> lect_weight_dict;
    QStringList class_lect_list;
    void initStdList(QString file_name);
    void initLectList(QString file_name);
};




#endif // LECTURE_H
