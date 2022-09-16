/*
给定两个正整数（不含前导 $0$），计算它们的差，计算结果可能为负数。

#### 输入格式

共两行，每行包含一个整数。

#### 输出格式

共一行，包含所求的差。

#### 数据范围

$1 \\le 整数长度 \\le 10^5$

#### 输入样例：

    32
    11


#### 输出样例：

    21
*/

#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}
vector<int> sub(vector<int> &A, vector<int> &B)
{
    int t = 0;
    vector<int> c;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        c.emplace_back((t + 10) % 10);
        if (t >= 0)
            t = 0;
        else
            t = 1;
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.emplace_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.emplace_back(b[i] - '0');
    vector<int> c;
    if (cmp(A, B))
        c = sub(A, B);
    else
        c = sub(B, A), cout << "-";
    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}
