/*
* 司令部的将军们打算在 $N \\times M$ 的网格地图上部署他们的炮兵部队。

一个 $N \\times M$ 的地图由 $N$ 行 $M$ 列组成，地图的每一格可能是山地（用 `H` 表示），也可能是平原（用 `P` 表示），如下图。

在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示：

![1185_1.jpg](/media/article/image/2019/02/16/19_d512cdba31-1185_1.jpg)

如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。

图上其它白色网格均攻击不到。

从图上可见炮兵的攻击范围不受地形的影响。

现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。

#### 输入格式

第一行包含两个由空格分割开的正整数，分别表示 $N$ 和 $M$；

接下来的 $N$ 行，每一行含有连续的 $M$ 个字符(`P` 或者 `H`)，中间没有空格。按顺序表示地图中每一行的数据。

#### 输出格式

仅一行，包含一个整数 $K$，表示最多能摆放的炮兵部队的数量。

#### 数据范围

$N \\le 100,M \\le 10$

#### 输入样例：

    5 4
    PHPP
    PPHH
    PPPP
    PHPP
    PHHP
    

#### 输出样例：

    6
*/

#include <iostream>
#include <vector>
using namespace std;
const int N = 10, M = 1 << N;
int f[2][M][M];
int g[1010];
vector<int> state;
int cnt[M];
int n, m;
bool check(int state) { // 检查一个状态横向是否正常
    for (int i = 0; i < m; i++)
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2) & 1))
            return false;
    return true;
}
int count(int state) // 计算一个状态有多少个1
{
    int res = 0;
    for (int i = 0; i < m; i++)
        if (state >> i & 1)
            res++;
    return res;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) // 读入数据
        for (int j = 0; j < m; j++)
        {
            char c; cin >> c;
            g[i] += (c == 'H') << j;
        }
    for (int i = 0; i < 1 << m; i++) // 遍历所有的撞他i
        if (check(i)) { // 检查状态的合法性
            state.push_back(i);
            cnt[i] = count(i);
        }
    for (int i = 1; i <= n; i++) // 遍历n行
        for (int j = 0; j < state.size(); j++)
            for (int k = 0; k < state.size(); k++)
                for (int u = 0; u < state.size(); u++) // 三个状态遍历
                {
                    int a = state[j], b = state[k], c = state[u]; // 拿到状态
                    if (a & b | b & c | a & c) continue; // 纵向不可以
                    if (g[i] & b) continue; // 山地检查
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]); 
                    // 检查所有的地方 j -> k 可以从 u -> j 的状态 + 当前状态的数量
                }
    int res = 0;
    for (int i = 0; i < state.size(); i++) // 遍历所有的地方求最大值
        for (int j = 0; j < state.size(); j++)
            res = max(res, f[n & 1][i][j]);
    cout << res << endl;
    return 0;
}
