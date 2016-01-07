#include "lecture.h"

lecture::lecture(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    QString sp = " ";
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QString grade_file_name("lecture_grade.txt");
    QString lect_file_name("lecture.txt");
    lect_weight_dict["必修"] = 1.2;
    lect_weight_dict["选修"] = 1.0;
    lect_weight_dict["实践"] = 1.1;
    initLectList(lect_file_name);
    initStdList(grade_file_name);
    connect(ui.pushButton, SIGNAL(clicked()), SLOT(button1OnClicked()));
    connect(ui.pushButton_2, SIGNAL(clicked()), SLOT(button2OnClicked()));
    connect(ui.pushButton_3, SIGNAL(clicked()), SLOT(button3OnClicked()));
    connect(ui.pushButton_4, SIGNAL(clicked()), SLOT(button4OnClicked()));
    connect(ui.pushButton_5, SIGNAL(clicked()), SLOT(button5OnClicked()));
    connect(ui.pushButton_6, SIGNAL(clicked()), SLOT(button6OnClicked()));

}

lecture::~lecture()
{

}

void lecture::button4OnClicked(){
    QString showText;
    Student tmp_std;
    QString tmp_str;
    for(int i = 0; i < std_list.count(); i ++){
        tmp_std = std_list[i];
        tmp_str = QString("Name: %1\t\t GPA: %2\n").arg(tmp_std.getName()).arg(tmp_std.getGPA());
        showText.append(tmp_str);
    }
    ui.textBrowser->setText(showText);
}

bool compareGPA(Student std1, Student std2){
    return std1.getGPA() > std2.getGPA();

}

void lecture::button5OnClicked(){
    QList<Student> sorted_std_list(std_list);
    qSort(sorted_std_list.begin(), sorted_std_list.end(), compareGPA);
    QString showText;
    Student tmp_std;
    QString tmp_str;
    for(int i = 0; i < sorted_std_list.count(); i ++){
        tmp_std = sorted_std_list[i];
        tmp_str = QString("Name: %1\t\t GPA: %2\n").arg(tmp_std.getName()).arg(tmp_std.getGPA());
        showText.append(tmp_str);
    }
    ui.textBrowser->setText(showText);
}

void lecture::button6OnClicked(){
    QList<Student> sorted_std_list(std_list);
    qSort(sorted_std_list.begin(), sorted_std_list.end(), compareGPA);
    QString showText;
    Student tmp_std;
    QString tmp_str;
    for(int i = 0; i < sorted_std_list.count(); i ++){
        tmp_std = sorted_std_list[i];
        tmp_str = QString("Name: %1\t\t GPA: %2\r\n").arg(tmp_std.getName()).arg(tmp_std.getGPA());
        showText.append(tmp_str);
    }
    QFile f1("GPA.txt");
    f1.open(QFile::WriteOnly);
    QTextStream gpa_stream(&f1);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    gpa_stream.setCodec(codec);
    gpa_stream<<showText;
    f1.close();
}


void lecture::button3OnClicked(){
    ui.lineEdit->setText("");
    ui.lineEdit_2->setText("");
    QString showText;
    showText.append("Students that have unpassed lectures are:\n");
    Student tmp_std;
    QList<int> tmp_grade_list;
    QString tmp_unpassed_name;
    for(int i = 0; i < std_list.count(); i ++){
        tmp_std = std_list[i];
        if(tmp_std.getUnPassedLectNum() != 0){
            tmp_grade_list = tmp_std.getGradeList();
            showText.append(tmp_std.getName());
            showText.append(":  ");
            for(int j = 0; j < class_lect_list.count(); j++){
                if(tmp_grade_list[j] > 0 && tmp_grade_list[j] < 60){
                    tmp_unpassed_name = class_lect_list[j];
                    showText.append(tmp_unpassed_name);
                    showText.append("\t");
                }
            }
            showText.append("\n");
        }
    }
    ui.textBrowser->setText(showText);
}


void lecture::button1OnClicked(){
    ui.lineEdit_2->setText("");
    QString checkedNum = ui.lineEdit->text();
    checkedNum = checkedNum.simplified();
    QString showText;
    Student tmp_std;
    QString tmp_number;
    QList<int> tmp_grade_list;
    QString tmp_unpassed_name;
    for(int i = 0; i < std_list.count(); i ++){
        tmp_std = std_list[i];
        if(tmp_std.getNumber().compare(checkedNum) == 0){
            showText = QString(" Name: %1\t\t Number: %2\n GPA: %3\t\t Total Grades: %4\n Learned Credits: %5\t\t Unpassed Credits: %6\n Total lecture number: %7\t\t Unpassed lecture number: %8\n")
                .arg(tmp_std.getName())
                .arg(tmp_std.getNumber())
                .arg(tmp_std.getGPA())
                .arg(tmp_std.getWholeGrade())
                .arg(tmp_std.getLearnedLectCredit())
                .arg(tmp_std.getUnPassedLectCredit())
                .arg(tmp_std.getLearnedLectNum())
                .arg(tmp_std.getUnPassedLectNum());
            if(tmp_std.getUnPassedLectNum() != 0){
                showText.append(" Unpassed Lectures: ");
                tmp_grade_list = tmp_std.getGradeList();
                for(int j = 0; j < class_lect_list.count(); j++){
                    if(tmp_grade_list[j] > 0 && tmp_grade_list[j] < 60){
                        tmp_unpassed_name = class_lect_list[j];
                        showText.append(tmp_unpassed_name);
                        showText.append(" ");
                    }
                }
            }
            break;
        }
    }
    ui.textBrowser->setText(showText);
}

void lecture::button2OnClicked(){
    ui.lineEdit->setText("");
    QString checkedName = ui.lineEdit_2->text();
    checkedName = checkedName.simplified();
    QString showText;
    Student tmp_std;
    QString tmp_number;
    QList<int> tmp_grade_list;
    QString tmp_unpassed_name;
    for(int i = 0; i < std_list.count(); i ++){
        tmp_std = std_list[i];
        if(tmp_std.getName().compare(checkedName) == 0){
            showText = QString(" Name: %1\t\t Number: %2\n GPA: %3\t\t Total Grades: %4\n Learned Credits: %5\t\t Unpassed Credits: %6\n Total lecture number: %7\t\t Unpassed lecture number: %8\n")
                .arg(tmp_std.getName())
                .arg(tmp_std.getNumber())
                .arg(tmp_std.getGPA())
                .arg(tmp_std.getWholeGrade())
                .arg(tmp_std.getLearnedLectCredit())
                .arg(tmp_std.getUnPassedLectCredit())
                .arg(tmp_std.getLearnedLectNum())
                .arg(tmp_std.getUnPassedLectNum());
            if(tmp_std.getUnPassedLectNum() != 0){
                showText.append(" Unpassed Lectures: ");
                tmp_grade_list = tmp_std.getGradeList();
                for(int j = 0; j < class_lect_list.count(); j++){
                    if(tmp_grade_list[j] > 0 && tmp_grade_list[j] < 60){
                        tmp_unpassed_name = class_lect_list[j];
                        showText.append(tmp_unpassed_name);
                        showText.append(" ");
                    }
                }
            }
            break;
        }
    }
    ui.textBrowser->setText(showText);
}




void lecture::initLectList(QString file_name){
    QFile lect_file(file_name);
    lect_file.open(QFile::ReadOnly);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextStream lect_stream(&lect_file);
    lect_stream.setCodec(codec);
    QString tmp_line_str;
    int line_num = 1;
    QString sp = " ";
    QString stat1 = "必修";
    QString stat2 = "选修";
    QString stat3 = "实践";
    QStringList tmp_line_list;
    while( ! lect_stream.atEnd()){
        tmp_line_str = lect_stream.readLine();
        if(line_num == 1){
            line_num ++;
            continue;
        }else{
            tmp_line_list = tmp_line_str.split(sp);
            QStringList used_line_list;
            for(int i = 0; i < tmp_line_list.count(); i ++){
                if(tmp_line_list[i].compare("") != 0){
                    used_line_list.append(tmp_line_list[i]);
                }
            }
            lect_credit_dict[used_line_list[0]] = used_line_list[1].toDouble();
            lect_stat_dict[used_line_list[0]] = lect_weight_dict[used_line_list[2]];
        }
    }
}


void lecture::initStdList(QString file_name){
    QStringList tmp_class_lect_list;
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString sp = " ";
    QFile grade_file(file_name);
    grade_file.open(QFile::ReadOnly);
    QTextStream grade_stream(&grade_file);
    grade_stream.setCodec(codec);
    int i = 0;
    while(!grade_stream.atEnd()){
        QString tmp_str = grade_stream.readLine();
        QStringList tmp_list = tmp_str.split(sp);
        QStringList tmp_std_list;
        if(i == 0){
            for(int k = 0; k < tmp_list.count(); k ++){
                if(tmp_list[k].compare("") == 0){
                }else{
                    class_lect_list.append(tmp_list[k]);
                }
            }
            class_lect_list.pop_front();
            class_lect_list.pop_front();
            for(int k = 0; k <class_lect_list.count(); k ++){
                //qDebug()<<class_lect_list[k]<<lect_grade_dict[class_lect_list[k]]<<lect_weight_dict[class_lect_list[k]];
            }
            i ++;
            continue;
        }
        for(int k = 0; k < tmp_list.count(); k ++){
            if(tmp_list[k].compare("") == 0){
                qDebug()<<"Should be Deleted!!!!!!";
            }else{
                tmp_std_list.append(tmp_list[k]);
            }
        }
        Student tmp_std(tmp_std_list[1], tmp_std_list[0], tmp_std_list.mid(2), lect_credit_dict, lect_stat_dict, class_lect_list);
        std_list.append(tmp_std);
        //qDebug()<<tmp_std.getName()<<tmp_std.getWholeGrade();
    }
    //for(int i = 0; i < class_lect_list.count(); i ++){
    //    qDebug()<<class_lect_list[i]<<lect_credit_dict[class_lect_list[i]]<<lect_stat_dict[class_lect_list[i]];
    //}
}


void lecture::outputStdInfo(){
    Student tmp_std;
    for(int i = 0; i < std_list.count(); i ++){
        tmp_std = std_list[i];
        //qDebug()<<tmp_std.getName()<<tmp_std.getGPA()<<tmp_std.getLearnedLectCredit();
    }
}


Student::Student(){

}

QString Student::getNumber(){
    return student_number;
}

QString Student::getName(){
    return name;
}

QList<int> Student::getGradeList(){
    return grade_list;

}

Student::Student(QString std_name, QString std_num, QStringList gradeList, QMap<QString, double> lect_credit_dict, QMap<QString, double> lect_stat_dict, QStringList class_lect_list){
    lect_name_list = class_lect_list;
    name = std_name;
    student_number = std_num;
    grade_str_list = gradeList;
    strList2intList();
    whole_grade = getWholeGrade();
    learned_lect_num = getLearnedLectNum();
    unpassed_lect_num = getUnPassedLectNum();
    learned_lect_credit = countLearnedLectCredit(lect_credit_dict, lect_stat_dict);
    unpassed_lect_credit = countUnPassedLectCredit(lect_credit_dict, lect_stat_dict);
    gpa = countGPA(lect_credit_dict, lect_stat_dict);
}

Student::~Student(){

}

double Student::getGPA(){
    return gpa;
}

double Student::getLearnedLectCredit(){
    return learned_lect_credit;
}

double Student::getUnPassedLectCredit(){
    return unpassed_lect_credit;
}


int Student::getLearnedLectNum(){
    int num = 0;
    for(int i = 0; i < grade_list.count(); i ++){
        if(grade_list[i] != 0){
            ++num;
        }
    }
    return num;
}

int Student::getUnPassedLectNum(){
    int num = 0;
    for(int i = 0; i < grade_list.count(); i ++){
        if(grade_list[i] < 60 && grade_list[i] != 0){
            ++num;
        }
    }
    return num;
}

double Student::countLearnedLectCredit(QMap<QString, double> lect_credit_dict, QMap<QString, double> lect_stat_dict){
    double tmp_credit = 0;
    QString lect_name;
    double lect_credit;
    int lect_grade;
    double lect_stat;
    for(int i = 0; i < lect_name_list.count(); i ++){
        lect_name = lect_name_list[i];
        lect_credit = lect_credit_dict[lect_name];
        lect_grade = grade_list[i];
        lect_stat = lect_stat_dict[lect_name];
        if(lect_grade != 0){
            //qDebug()<<name<<lect_name<<lect_grade<<lect_credit<<lect_stat;
            tmp_credit += lect_credit;
        }
    }
    //qDebug()<<name<<tmp_credit;
    return tmp_credit;
}

double Student::countUnPassedLectCredit(QMap<QString, double> lect_credit_dict, QMap<QString, double> lect_stat_dict){
    double tmp_credit = 0;
    QString lect_name;
    double lect_credit;
    int lect_grade;
    double lect_stat;
    for(int i = 0; i < lect_name_list.count(); i ++){
        lect_name = lect_name_list[i];
        lect_credit = lect_credit_dict[lect_name];
        lect_grade = grade_list[i];
        lect_stat = lect_stat_dict[lect_name];
        if(lect_grade != 0 && lect_grade < 60){
            //qDebug()<<name<<lect_name<<lect_grade<<lect_credit<<lect_stat;
            tmp_credit += lect_credit;
        }
    }
    //qDebug()<<name<<tmp_credit;
    return tmp_credit;

}


double Student::countGPA(QMap<QString, double> lect_credit_dict, QMap<QString, double> lect_stat_dict){
    double tmp_gpa = 0;
    double tmp_lect_gpa = 0;
    QString lect_name;
    int lect_grade;
    double lect_credit;
    double lect_stat;
    for(int i = 0; i < lect_name_list.count(); i ++){
        lect_name = lect_name_list[i];
        lect_grade = grade_list[i];
        lect_credit = lect_credit_dict[lect_name];
        lect_stat = lect_stat_dict[lect_name];
        if(lect_grade != 0){
            tmp_lect_gpa = (lect_grade / 10.0) - 5;
            //qDebug()<<QString().setNum(tmp_lect_gpa);
            tmp_gpa += tmp_lect_gpa * lect_credit * lect_stat / learned_lect_credit;
        }

    }
    //qDebug()<<name<<tmp_gpa;
    return tmp_gpa;
}




void Student::strList2intList(){
    qint16 list_length = grade_str_list.length();
    for(qint16 i = 0; i < list_length; i++){
        grade_list.append(grade_str_list[i].toInt());
    }
}

int Student::getWholeGrade(){
    int tmp_grade = 0;
    qint16 list_length = grade_list.count();
    for(qint16 i = 0; i < list_length; i++){
        tmp_grade += grade_list[i];
    }

    return tmp_grade;
}


QStringList Student::getList(){
    return grade_str_list;
}