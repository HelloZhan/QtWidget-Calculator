#include "corecomputing.h"
#include <cmath>
#define numerror 0.979899
storage_expression s;//存储表达式的类
double corecomputing(char expression[])
{
    s.initialize(expression);//初始化这个类
    return expression_value();
}
double cifang(double result,int n){//计算次方
    double num=1;
    int N=abs(n);
    for(int i=0;i<N;i++){
        num=result*num;
    }
    if(n>=0){
        return num;
    }else{
        return 1/num;
    }
}
double expression_value()//求一个表达式的值
{
    double result=term_value();//求第一项的值
    if(result==numerror)return numerror;
    bool more=true;
    while(more){
        char op=s.nowcharacter();//读取现在的字符
        if(op=='+'||op=='-'){
            s.nextcharacter();//指向下一个字符
            double value=term_value();//读取项
            if(value==numerror)return numerror;
            if(op=='+')result +=value;
            else result -=value;
        }else if(op=='('||op=='s'||op=='c'||op=='.'||op=='t'||op=='*'||op=='/'||op=='^'||op=='$'){
            return numerror;
        }else{
            more=false;
        }
    }
    return result;
}
double term_value()//求一个项的值
{
    double result=factor_value();//求第一个因子的值
    if(result==numerror){
        return numerror;
    }
    while(true){
        char op=s.nowcharacter();//读取现在的字符
        if(op=='*'||op=='/'||op=='^'){//如果是乘 除 次方
            s.nextcharacter();
            double value=factor_value();
            if(value==numerror)return numerror;
            if(op=='*')
                result *=value;
            else if(op=='/'){
                if((result-0)<=1e-8){
                    return numerror;
                }
                result /=value;
            }
            else if(op=='^')
                result=cifang(result,value);
        }
        else break;
    }
    return result;
}
double factor_value()//求一个因子的值
{
    double result=0;
    char c=s.nowcharacter();//读取现在的字符
    if(c=='('){//如果是左括号
        s.nextcharacter();
        result=expression_value();//读取一个表达式
        if(s.nowcharacter()==')'){
            s.nextcharacter();
        }else{
            return numerror;
        }
    }else if(c=='s'){//如果是sin
        s.nextcharacter();
        s.nextcharacter();
        s.nextcharacter();
        result=expression_value();
        result=sin(result);
    }else if(c=='c'){//如果是cos
        s.nextcharacter();
        s.nextcharacter();
        s.nextcharacter();
        result=expression_value();
        result=cos(result);
    }else if(c=='t'){//如果是tan
        s.nextcharacter();
        s.nextcharacter();
        s.nextcharacter();
        result=expression_value();
        result=tan(result);
    }else if(c=='$'){//如果是根号
        s.nextcharacter();
        result=expression_value();
        if(result<0)return numerror;
        result=sqrt(result);
    }else if(isdigit(c)){//如果是数和小数点
        double k=0.1;
        int flag=1;
        while(isdigit(c)||c=='.'){
            //如果是.则代表后面是小数
            if(c=='.'){
                if(flag==0)return numerror;
                flag=0;s.nextcharacter();c=s.nowcharacter();continue;
            }
            if(flag){//读入整数部分
                result=10*result+c-'0';
            }else{//读入小数部分
                result=result+(c-'0')*k;
                k=k*0.1;
            }
            s.nextcharacter();
            c=s.nowcharacter();
        }
    }else if(c=='-'||c=='+'){
        if(s.beforecharacter()=='('||s.beforecharacter()=='a'){
            return 0;
        }else{
            return numerror;
        }
    }else{//错误处理
        return numerror;
    }
    return result;
}
