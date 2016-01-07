本程序的编写环境为vs2008 with sp1　和　Qt4.8.2；
运行时需要确保lecture.txt　和　lecture_grade.txt这两个文件均在exe的同一文件夹中，并且这两个txt的编码方式应为utf-8,　否则会发生编码解析错误。

程序源代码在编译时也应确保所有的cpp和h文件的编码方式为utf-8，可以在vs2008的文件的另存为的编码保存中选择utf-8无签名。

程序中设置了ui和student两个类，分别管理界面和学生信息，主要使用的数据结构由QList、QStringlist和QMap实现，qmap起的是键值对作用。排序使用的是QtAlgorithms中的qSort。
