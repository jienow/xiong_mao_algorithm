/*
实现一个双链表，双链表初始为空，支持 $5$ 种操作：

1.  在最左侧插入一个数；
2.  在最右侧插入一个数；
3.  将第 $k$ 个插入的数删除；
4.  在第 $k$ 个插入的数左侧插入一个数；
5.  在第 $k$ 个插入的数右侧插入一个数

现在要对该链表进行 $M$ 次操作，进行完所有操作后，从左到右输出整个链表。

**注意**:题目中第 $k$ 个插入的数并不是指当前链表的第 $k$ 个数。例如操作过程中一共插入了 $n$ 个数，则按照插入的时间顺序，这 $n$ 个数依次为：第 $1$ 个插入的数，第 $2$ 个插入的数，…第 $n$ 个插入的数。

#### 输入格式

第一行包含整数 $M$，表示操作次数。

接下来 $M$ 行，每行包含一个操作命令，操作命令可能为以下几种：

1.  `L x`，表示在链表的最左端插入数 $x$。
2.  `R x`，表示在链表的最右端插入数 $x$。
3.  `D k`，表示将第 $k$ 个插入的数删除。
4.  `IL k x`，表示在第 $k$ 个插入的数左侧插入一个数。
5.  `IR k x`，表示在第 $k$ 个插入的数右侧插入一个数。

#### 输出格式

共一行，将整个链表从左到右输出。

#### 数据范围

$1 \\le M \\le 100000$  
所有操作保证合法。

#### 输入样例：

    10
    R 7
    D 1
    L 3
    IL 2 10
    D 3
    IL 2 7
    L 8
    R 9
    IL 4 7
    IR 2 2
    

#### 输出样例：

    8 7 7 3 2 9
*/

#include <iostream>
using namespace std;
const int N = 100000 + 10;
int e[N], l[N], r[N], idx;
void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
void insert(int k,int x){
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}
void remove(int k){
    r[k] = r[r[k]];
    l[r[k]] = k;
}
int main(){
    int n;
    cin >> n;
    init();
    while(n--){
        string op;
        cin >> op;
        if(op == "L"){
            int x;
            cin >> x;
            insert(0, x);
        }else if(op == "R"){
            int x;
            cin >> x;
            insert(l[1], x);
        }else if(op == "D"){
            int k;
            cin >> k;
            remove(l[k+1]);
        }else if(op == "IL"){
            int k, x;
            cin >> k >> x;
            insert(l[k+1], x);
        }else if(op == "IR"){
            int k, x;
            cin >> k >> x;
            insert(k+1, x);
        }
    }
    for (int i = r[0]; i != 1;i = r[i]){
        cout << e[i] << " ";
    }
    return 0;
}