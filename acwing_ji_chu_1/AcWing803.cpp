/*
给定 $n$ 个区间 $\[l\_i, r\_i\]$，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。

例如：$\[1,3\]$ 和 $\[2,6\]$ 可以合并为一个区间 $\[1,6\]$。

#### 输入格式

第一行包含整数 $n$。

接下来 $n$ 行，每行包含两个整数 $l$ 和 $r$。

#### 输出格式

共一行，包含一个整数，表示合并区间完成后的区间个数。

#### 数据范围

$1 \\le n \\le 100000$,
$\-10^9 \\le l\_i \\le r\_i \\le 10^9$

#### 输入样例：

    5
    1 2
    2 4
    5 6
    7 8
    7 9


#### 输出样例：

    3
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
typedef pair<int, int> PII;
int merge(vector<PII> &meges)
{
    vector<PII> res;
    int st = -2e9, ed = -2e9;
    for (auto mege : meges)
    {
        if(ed < mege.first){
            if(st!=-2e9)
                res.push_back({st, ed});
            st = mege.first, ed = mege.second;
        }else
            ed = max(ed, mege.second);
    }
    if(st!=-2e9)res.push_back({st, ed});
    return res.size();
}
int main()
{
    int n;
    cin >> n;
    vector<PII> mges;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        mges.emplace_back(pair(l, r));
    }
    sort(mges.begin(), mges.end());
    cout << merge(mges) << endl;
    return 0;
}