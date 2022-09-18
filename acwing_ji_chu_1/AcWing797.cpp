/*
输入一个长度为 $n$ 的整数序列。

接下来输入 $m$ 个操作，每个操作包含三个整数 $l, r, c$，表示将序列中 $\[l, r\]$ 之间的每个数加上 $c$。

请你输出进行完所有操作后的序列。

#### 输入格式

第一行包含两个整数 $n$ 和 $m$。

第二行包含 $n$ 个整数，表示整数序列。

接下来 $m$ 行，每行包含三个整数 $l，r，c$，表示一个操作。

#### 输出格式

共一行，包含 $n$ 个整数，表示最终序列。

#### 数据范围

$1 \\le n,m \\le 100000$,  
$1 \\le l \\le r \\le n$,  
$\-1000 \\le c \\le 1000$,  
$\-1000 \\le 整数序列中元素的值 \\le 1000$

#### 输入样例：

    6 3
    1 2 2 1 2 1
    1 3 1
    3 5 1
    1 6 1
    

#### 输出样例：

    3 4 5 3 4 2
*/

#include <iostream>
using namespace std;
const int N = 100000 + 10;
int b[N];
void insert(int l,int r,int c){
    b[l] += c;
    b[r + 1] -= c;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        int c;
        scanf("%d", &c);
        insert(i, i, c);
    }
    while(m--){
        int l, r, m;
        scanf("%d%d%d", &l, &r, &m);
        insert(l, r, m);
    }

    for (int i = 1; i <= n;i ++){
        b[i] += b[i - 1];
        printf("%d ", b[i]);
    }

    return 0;
}