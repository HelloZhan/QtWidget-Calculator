#ifndef COUNTER_H
#define COUNTER_H
#include "ui_counter.h"
#include <QtGui>
#include <QDialog>
class Counter:public QDialog,public Ui_Form
{
    Q_OBJECT
public:
    Counter(QWidget *parent=0);
    void output();//刷新label，将数组的字符串输出到label上
    //下面三个函数存放在style.cpp
    void forbitallbutton();//将全部按钮设置禁止使用
    void enableallbutton();//将全部按钮设置允许使用
    void setstyle();
private slots:
    //添加数字0-9
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    //添加+ - * / ( )
    void addjia();
    void addjian();
    void addchen();
    void addchu();
    void adddian();
    void addzuo();
    void addyou();
    //添加次方，sin,cos,tan,根号按钮
    void addcifang();
    void addsin();
    void addcos();
    void addtan();
    void addkaifang();
    //添加功能按钮
    void calculate();//等于 点击计算结果
    void deleteone();//删除一个字符
    void reset();//清零
    void clear();//将答案清除
    void retain();//将答案保留
};

#endif
