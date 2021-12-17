#include <iostream>
#include "count.h"
#include "corecomputing.h"//核心计算的头文件
#define numerror 0.979899
using namespace std;

char expression[1000];//存储计算的字符
int endcharacter=0;//指向最后一个字符的下一个位置

Counter::Counter(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    //将信号与槽连接
    connect(pushButton0,SIGNAL(clicked()),this,SLOT(add0()));
    connect(pushButton1,SIGNAL(clicked()),this,SLOT(add1()));
    connect(pushButton2,SIGNAL(clicked()),this,SLOT(add2()));
    connect(pushButton3,SIGNAL(clicked()),this,SLOT(add3()));
    connect(pushButton4,SIGNAL(clicked()),this,SLOT(add4()));
    connect(pushButton5,SIGNAL(clicked()),this,SLOT(add5()));
    connect(pushButton6,SIGNAL(clicked()),this,SLOT(add6()));
    connect(pushButton7,SIGNAL(clicked()),this,SLOT(add7()));
    connect(pushButton8,SIGNAL(clicked()),this,SLOT(add8()));
    connect(pushButton9,SIGNAL(clicked()),this,SLOT(add9()));
    connect(pushButtonjia,SIGNAL(clicked()),this,SLOT(addjia()));
    connect(pushButtonjian,SIGNAL(clicked()),this,SLOT(addjian()));
    connect(pushButtonchen,SIGNAL(clicked()),this,SLOT(addchen()));
    connect(pushButtonchu,SIGNAL(clicked()),this,SLOT(addchu()));
    connect(pushButtondian,SIGNAL(clicked()),this,SLOT(adddian()));
    connect(pushButtonz,SIGNAL(clicked()),this,SLOT(addzuo()));
    connect(pushButtony,SIGNAL(clicked()),this,SLOT(addyou()));
    connect(pushButtoncifang,SIGNAL(clicked()),this,SLOT(addcifang()));
    connect(pushButtonsin,SIGNAL(clicked()),this,SLOT(addsin()));
    connect(pushButtoncos,SIGNAL(clicked()),this,SLOT(addcos()));
    connect(pushButtontan,SIGNAL(clicked()),this,SLOT(addtan()));
    connect(pushButtonkaifang,SIGNAL(clicked()),this,SLOT(addkaifang()));
    connect(pushButtonC,SIGNAL(clicked()),this,SLOT(reset()));
    connect(pushButtontui,SIGNAL(clicked()),this,SLOT(deleteone()));
    connect(pushButtonok,SIGNAL(clicked()),this,SLOT(calculate()));
    connect(pushButtonclear,SIGNAL(clicked()),this,SLOT(clear()));
    connect(pushButtonretain,SIGNAL(clicked()),this,SLOT(retain()));
    setstyle();//设置样式
}

void Counter::output()//输出字符数组的字符到label
{
    QString s=expression;
    label->setText(s);
}
void Counter::add0()
{
    expression[endcharacter++]='0';
    output();
}
void Counter::add1()
{
    expression[endcharacter++]='1';
    output();
}
void Counter::add2()
{
    expression[endcharacter++]='2';
    output();
}
void Counter::add3()
{
    expression[endcharacter++]='3';
    output();
}
void Counter::add4()
{
    expression[endcharacter++]='4';
    output();
}
void Counter::add5()
{
    expression[endcharacter++]='5';
    output();
}
void Counter::add6()
{
    expression[endcharacter++]='6';
    output();
}
void Counter::add7()
{
    expression[endcharacter++]='7';
    output();
}
void Counter::add8()
{
    expression[endcharacter++]='8';
    output();
}
void Counter::add9()
{
    expression[endcharacter++]='9';
    output();
}
void Counter::addjia()
{
    expression[endcharacter++]='+';
    output();
}
void Counter::addjian()
{
    expression[endcharacter++]='-';
    output();
}
void Counter::addchen()
{
    expression[endcharacter++]='*';
    output();
}
void Counter::addchu()
{
    expression[endcharacter++]='/';
    output();
}
void Counter::adddian()
{
    expression[endcharacter++]='.';
    output();
}
void Counter::addzuo()
{
    expression[endcharacter++]='(';
    output();
}
void Counter::addyou()
{
    expression[endcharacter++]=')';
    output();
}
void Counter::addcifang()
{
    expression[endcharacter++]='^';
    output();
}
void Counter::addsin()
{
    expression[endcharacter++]='s';
    expression[endcharacter++]='i';
    expression[endcharacter++]='n';
    output();
}
void Counter::addcos()
{
    expression[endcharacter++]='c';
    expression[endcharacter++]='o';
    expression[endcharacter++]='s';
    output();
}
void Counter::addtan()
{
    expression[endcharacter++]='t';
    expression[endcharacter++]='a';
    expression[endcharacter++]='n';
    output();
}
void Counter::addkaifang()
{
    expression[endcharacter++]='$';
    output();
}

void Counter::calculate()//计算按钮
{
    expression[endcharacter++]='=';
    double result=corecomputing(expression);//将字符数组传入计算函数进行计算
    if(result!=numerror){
        int z=result;//保留整数部分
        int x=(result-z)*100000;//保留5位小数部分

        if(abs(x)>0){//如果小数部分大于0则是有小数的值
            char ds[100];//保存结果值
            sprintf(ds,"%f",result);//将double类型转换为char型数组
            int length=strlen(ds);
            int onum=length-1;
            while(1){//从后往前去掉多余的0
                if(ds[onum]=='0'){
                    onum--;
                }else{
                    break;
                }
            }
            for(int i=0;i<=onum;i++){
                expression[endcharacter++]=ds[i];
            }
        }else{//等于0 说明计算结果没有小数
            char ds[100];
            snprintf(ds,sizeof(ds),"%d",z);//将int类型转换为char型数组
            int length=strlen(ds);
            for(int i=0;i<length;i++){
                expression[endcharacter++]=ds[i];
            }
        }
        forbitallbutton();
        pushButtonclear->setEnabled(true);
        pushButtonC->setEnabled(true);
        pushButtonretain->setEnabled(true);
    }else{//如果错误就将保存答案按钮禁掉
        expression[endcharacter++]='e';
        expression[endcharacter++]='r';
        expression[endcharacter++]='r';
        expression[endcharacter++]='o';
        expression[endcharacter++]='r';
        forbitallbutton();
        pushButtonclear->setEnabled(true);
        pushButtonC->setEnabled(true);
    }

    //按下等于按钮则不能按方程式的按钮，只能按功能按钮（清零，清楚答案，保留答案）
    output();
}

void Counter::deleteone()
{
    if(endcharacter>0)endcharacter--;
    if(expression[endcharacter]=='n'||expression[endcharacter]=='s'){
        expression[endcharacter--]='\0';
        expression[endcharacter--]='\0';
    }
    expression[endcharacter]='\0';
    output();
}

void Counter::reset()//清零按钮
{
    for(int i=0;i<=endcharacter;i++){
        expression[i]='\0';
    }
    endcharacter=0;
    //按下清零按钮则不能按（清除答案，保留答案按钮）
    enableallbutton();
    pushButtonclear->setEnabled(false);
    pushButtonretain->setEnabled(false);
    output();
}
void Counter::clear()//清除答案按钮
{
    while(1){//从后往前清除，直到等于符号
        endcharacter--;
        if(expression[endcharacter]=='='){
            expression[endcharacter]='\0';
            break;
        }
        expression[endcharacter]='\0';
    }
    //按下此按钮则不能按（清除答案，保留答案）按钮
    enableallbutton();
    pushButtonclear->setEnabled(false);
    pushButtonretain->setEnabled(false);
    output();
}

void Counter::retain()//保留答案按钮
{
    char result[100];
    int num=0;
    int flag=0;
    for(int i=0;i<endcharacter;i++){//将答案保存到result数组中，并保存长度num
        if(flag==1)result[num++]=expression[i];
        if(expression[i]=='=')flag=1;
    }
    for(int i=0;i<num;i++){//将答案转移到expression数组的前面
        expression[i]=result[i];
    }
    for(int i=num;i<endcharacter;i++){//将除了答案的后面全部清空
        expression[i]='\0';
    }
    endcharacter=num;
    //按下此按钮不能再按（清除答案，保留答案）按钮
    enableallbutton();
    pushButtonclear->setEnabled(false);
    pushButtonretain->setEnabled(false);
    output();
}

