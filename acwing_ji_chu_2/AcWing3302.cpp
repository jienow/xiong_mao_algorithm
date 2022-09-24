/*
给定一个表达式，其中运算符仅包含 `+,-,*,/`（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

**注意：**

*   数据保证给定的表达式合法。
*   题目保证符号 `-` 只作为减号出现，不会作为负号出现，例如，`-1+2`,`(2+2)*(-(1+1)+2)` 之类表达式均不会出现。
*   题目保证表达式中所有数字均为正整数。
*   题目保证表达式在中间计算过程以及结果中，均不超过 $2^{31}-1$。
*   题目中的整除是指向 $0$ 取整，也就是说对于大于 $0$ 的结果向下取整，例如 $5/3=1$，对于小于 $0$ 的结果向上取整，例如 $5/(1-4) = -1$。
*   C++和Java中的整除默认是向零取整；Python中的整除`//`默认向下取整，因此Python的`eval()`函数中的整除也是向下取整，在本题中不能直接使用。

#### 输入格式

共一行，为给定表达式。

#### 输出格式

共一行，为表达式的结果。

#### 数据范围

表达式的长度不超过 $10^5$。

#### 输入样例：

    (2+2)*(1+1)
    

#### 输出样例：

    8
*/

#include <bits/stdc++.h>
using namespace std;
stack<int> num;
stack<char> op;
string str;
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
void eval(){
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    int x = 0;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else if (c == '/')
        x = a / b;
    num.push(x);
}
int main(){
    cin >> str;
    for (int i = 0; i < str.size();i ++){
        char c = str[i];
        if (isdigit(c)){
            int x = 0, j = i;
            while(j < str.size() && isdigit(str[j]))
                x = x * 10 + (str[j++] - '0');
            i = j - 1;
            num.push(x);
        }else if(c == '(')
            op.push(c);
        else if (c == ')'){
            //由于我们的括号内部的符号都再他们相遇的时候被计算了,到这里的时候他们都是弱递增
            //所以一直从后往前计算就可以，从后往前就是计算顺序是从大到小
            while( op.top() != '(')
                eval();
            op.pop();
        }else {
            // 这个计算之后可以保证符号栈是弱递增序列
            while(op.size() && op.top() != '('&& pr[op.top()] >= pr[c])
            //用while 可以保证如果多个括号相乘
                eval();
            op.push(c);
        }
    }
    while(op.size())
        eval();
    cout << num.top();
    return 0;
}