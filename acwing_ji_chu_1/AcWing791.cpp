/*给定两个正整数（不含前导 $0$），计算它们的和。

#### 输入格式

共两行，每行包含一个整数。

#### 输出格式

共一行，包含所求的和。

#### 数据范围

$1 \\le 整数长度 \\le 100000$

#### 输入样例：

    12
    23


#### 输出样例：

    35
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> add(vector<int> &A, vector<int> &B)
{
    if(A.size() < B.size())
        return add(B, A);
    int t = 0;
    vector<int> c;
    for (int i = 0; i < A.size();i ++){
        t += A[i];
        if(i < B.size())
            t += B[i];
        c.emplace_back(t % 10);
        t /= 10;
    }
    if(t!=0)
        c.emplace_back(t);
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
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}
