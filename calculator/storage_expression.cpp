#include "storage_expression.h"
#include <iostream>
#include <cstring>
void storage_expression::initialize(char expression[])
{
    for(int i=0;i<999;i++){
        c_expression[i]='k';
    }
    size=strlen(expression);
    for(int i=0;i<size;i++){//将字符数组全部读入到类的变量中
        c_expression[i]=expression[i];
    }
    location=0;
    now=c_expression[location];//指向第一个字符
}

void storage_expression::nextcharacter()//指向下一个字符函数
{
    location++;
    if(location>=size){//如果超界 则指向一个都不能处理的字符
        now='~';
        return;
    }
    now=c_expression[location];//字符指向下一个字符
}

char storage_expression::nowcharacter()//返回现在指向的字符
{
    return now;
}

char storage_expression::beforecharacter()
{
    if(location==0)return 'a';
    else return c_expression[location-1];
}
