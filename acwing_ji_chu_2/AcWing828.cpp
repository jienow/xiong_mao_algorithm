/*
实现一个栈，栈初始为空，支持四种操作：

1.  `push x` – 向栈顶插入一个数 $x$；
2.  `pop` – 从栈顶弹出一个数；
3.  `empty` – 判断栈是否为空；
4.  `query` – 查询栈顶元素。

现在要对栈进行 $M$ 个操作，其中的每个操作 $3$ 和操作 $4$ 都要输出相应的结果。

#### 输入格式

第一行包含整数 $M$，表示操作次数。

接下来 $M$ 行，每行包含一个操作命令，操作命令为 `push x`，`pop`，`empty`，`query` 中的一种。

#### 输出格式

对于每个 `empty` 和 `query` 操作都要输出一个查询结果，每个结果占一行。

其中，`empty` 操作的查询结果为 `YES` 或 `NO`，`query` 操作的查询结果为一个整数，表示栈顶元素的值。

#### 数据范围

$1 \\le M \\le 100000$,  
$1 \\le x \\le 10^9$  
所有操作保证合法。

#### 输入样例：

    10
    push 5
    query
    push 6
    pop
    query
    pop
    empty
    push 4
    query
    empty
    

#### 输出样例：

    5
    5
    YES
    4
    NO
*/

#include <iostream>
using namespace std;
const int N = 100000 + 10;
int st[N], hh, tt = -1;
void push(int x){
    st[++tt] = x;
}
void pop(){
    tt--;
}
string empty(){
    if(tt < 0)
        return "YES";
    else
        return "NO";
}
int query(){
    return st[tt];
}
int main(){
    int n;
    cin >> n;
    while(n--){
        string op;
        cin >> op;
        if(op == "push"){
            int x;
            cin >> x;
            push(x);
        }else if(op == "query"){
            cout << query() << endl;
        }else if(op == "pop"){
            pop();
        }else if(op == "empty"){
            cout << empty() << endl;
        }
    }
    return 0;
}