/*
给定两个非负整数（不含前导 $0$） $A$ 和 $B$，请你计算 $A \\times B$ 的值。

#### 输入格式

共两行，第一行包含整数 $A$，第二行包含整数 $B$。

#### 输出格式

共一行，包含 $A \\times B$ 的值。

#### 数据范围

$1 \\le A 的长度 \\le 100000$,
$0 \\le B \\le 10000$

#### 输入样例：

    2
    3


#### 输出样例：

    6
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> mult(vector<int> &A, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i] * b;
        c.emplace_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.emplace_back(t % 10);
        t /= 10;
    }
    while(c.size()>1&&c.back()==0)
        c.pop_back();
    return c;
}
int main()
{
    string a;
    int b = 0;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    vector<int> c = mult(A, b);
    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}