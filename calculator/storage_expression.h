#ifndef STORAGE_EXPRESSION_H
#define STORAGE_EXPRESSION_H
#include <iostream>
class storage_expression{
public:
    void initialize(char expression[]);//对类进行初始化
    void nextcharacter();//下一个字符
    char nowcharacter();//现在的字符
    char beforecharacter();//前一个字符
private:
    char c_expression[1000];//存放表达式的数组
    int size;//存放表达式数组的大小
    int location;//存放现在指向字符的位置
    char now;//现在指向的字符
};
#endif // STORAGE_EXPRESSION_H
