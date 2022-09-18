/**
 * 给定两个非负整数（不含前导 $0$） $A，B$，请你计算 $A / B$ 的商和余数。

#### 输入格式

共两行，第一行包含整数 $A$，第二行包含整数 $B$。

#### 输出格式

共两行，第一行输出所求的商，第二行输出所求余数。

#### 数据范围

$1 \\le A的长度 \\le 100000$,
$1 \\le B \\le 10000$,
$B$ 一定不为 $0$

#### 输入样例：

    7
    2


#### 输出样例：

    3
    1
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
auto mdiv(vector<int> &A, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        t = t * 10 + A[i];
        c.emplace_back((t / b) % 10);
        t %= b;
    }

    reverse(c.begin(), c.end());
    while (c.size() - 1 && c.back() == 0)
        c.pop_back();
    return tuple<vector<int>, int>{c, t};
}
int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.emplace_back(a[i] - '0');
    auto [c ,yushu] = mdiv(A, b);
    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;
    cout << yushu;
    return 0;
}