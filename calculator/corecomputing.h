#ifndef CORECOMPUTING_H
#define CORECOMPUTING_H
//这是一个计算器处理计算的程序
//将一个   表达式---->项(+-)项 项----->因子(*/)因子 因子---->数 (表达式)
#include "storage_expression.h"
double corecomputing(char expression[]);//处理计算的主函数
double cifang(double result,int n);//额外的次方函数
double factor_value();//因子函数
double term_value();//项函数
double expression_value();//表达式函数
#endif // CORECOMPUTING_H
