/*
* 在 $n \\times n$ 的棋盘上放 $k$ 个国王，国王可攻击相邻的 $8$ 个格子，求使它们无法互相攻击的方案总数。

#### 输入格式

共一行，包含两个整数 $n$ 和 $k$。

#### 输出格式

共一行，表示方案总数，若不能够放置则输出$0$。

#### 数据范围

$1 \\le n \\le 10$,  
$0 \\le k \\le n^2$

#### 输入样例：

    3 2
    

#### 输出样例：

    16
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;// 数字会溢出，就将所有的都改成LL

const int N = 12; // 提前计算
const int M = 1 << 10, K = 110; // k是国王数量
int n, m; // m表示国王数量，因为我们习惯使用n来表示一个数，m来表示一个值
vector<int> state; // 表示所有的合法状态
int id[M]; // id用来表示每个状态和他的下标之间的合法关系
vector<int> head[M]; // 表示每一个状态都可以转变成为其他状态
int cnt[M]; // cnt表示每个状态里面1的个数，

LL f[N][K][M]; // 状态表示

bool check(int state) // 检查一个数字是否存在两个相邻的1
{ 
    for (int i = 0; i < n; i++)
        if ((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    return true;
}

int count(int state) // 计算数字二进制表示中1的个数
{
    int res = 0;
    for (int i = 0; i < n; i++) res += state >> i & 1;
    return res;
}
int main() {
    cin >> n >> m;
    // 把所有的合法状态找出来，提前预处理以下
    for (int i = 0; i < 1 << n; i++)
        if (check(i)) 
        {
            state.push_back(i);
            id[i] = state.size() - 1;
            cnt[i] = count(i);
        }

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b)) 
            {
                head[i].push_back(j);
            }
        }

    f[0][0][0] = 1;

    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= m; j++)
            for (int a = 0;a < state.size();a ++)
                for (int b : head[a]) 
                {
                    int c = cnt[state[a]];
                    if (j >= c) {
                        f[i][j][a] += f[i - 1][j - c][b];
                    }
                }
    cout << f[n + 1][m][0] << endl;

    return 0;
}