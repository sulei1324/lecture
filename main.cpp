#include "lecture.h"
 
int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    lecture l;
    l.show();
    l.outputStdInfo();
    return a.exec();
}
