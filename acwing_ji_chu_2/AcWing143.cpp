/*
在给定的 $N$ 个整数 $A\_1，A\_2……A\_N$ 中选出两个进行 $xor$（异或）运算，得到的结果最大是多少？

#### 输入格式

第一行输入一个整数 $N$。

第二行输入 $N$ 个整数 $A\_1$～$A\_N$。

#### 输出格式

输出一个整数表示答案。

#### 数据范围

$1 \\le N \\le 10^5$,  
$0 \\le A\_i < 2^{31}$

#### 输入样例：

    3
    1 2 3
    

#### 输出样例：

    3
*/


#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, M = 3e6 + 20;//1e5个节点,每个数31个节点
int s[M][2], idx;
int a[N];
void insert(int x){
    int p = 0;
    for (int i = 30; ~i;i --){
        int &a = s[p][x >> i & 1];
        if(!a)
            a = ++idx;
        p = a;
    }
}
int query(int x){
    int res = 0, p = 0;
    for (int i = 30; ~i;i --){
        int a = x >> i & 1;
        if(s[p][!a]){
            res += 1 << i;
            p = s[p][!a];
        }
        else
            p = s[p][a];
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;i ++){
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n;i ++)
        res = max(res, query(a[i]));
    cout << res << " ";
    return 0;
}