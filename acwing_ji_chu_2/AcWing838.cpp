/*
输入一个长度为 $n$ 的整数数列，从小到大输出前 $m$ 小的数。

#### 输入格式

第一行包含整数 $n$ 和 $m$。

第二行包含 $n$ 个整数，表示整数数列。

#### 输出格式

共一行，包含 $m$ 个整数，表示整数数列中前 $m$ 小的数。

#### 数据范围

$1 \\le m \\le n \\le 10^5$，  
$1 \\le 数列中元素 \\le 10^9$

#### 输入样例：

    5 3
    4 5 1 3 2
    

#### 输出样例：

    1 2 3
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int h[N], sz;

void down(int u){
    int t = u;
    if(2*u <= sz && h[2*u] < h[t])
        t = 2 * u;
    if(2*u+1 <= sz && h[2*u+1] < h[t])
        t = 2 * u + 1;
    if(u!=t){
        swap(h[u], h[t]);
        down(t);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i ++)
        scanf("%d", &h[i]);
    sz = n;
    for (int i = n / 2; i;i--)
        down(i);
    while(m--){
        printf("%d ", h[1]);
        h[1] = h[sz--];
        down(1);
    }
    return 0;
}