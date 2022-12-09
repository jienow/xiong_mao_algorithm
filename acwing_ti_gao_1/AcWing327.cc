/*
* 农夫约翰的土地由 $M \\times N$ 个小方格组成，现在他要在土地里种植玉米。

非常遗憾，部分土地是不育的，无法种植。

而且，相邻的土地不能同时种植玉米，也就是说种植玉米的所有方格之间都不会有公共边缘。

现在给定土地的大小，请你求出共有多少种种植方法。

土地上什么都不种也算一种方法。

#### 输入格式

第 $1$ 行包含两个整数 $M$ 和 $N$。

第 $2..M+1$ 行：每行包含 $N$ 个整数 $0$ 或 $1$，用来描述整个土地的状况，$1$ 表示该块土地肥沃，$0$ 表示该块土地不育。

#### 输出格式

输出总种植方法对 $10^8$ 取模后的值。

#### 数据范围

$1 \\le M,N \\le 12$

#### 输入样例：

    2 3
    1 1 1
    0 1 0
    

#### 输出样例：

    9
*/

/*
* 这个题可以分为四步：
*       将所有的数据读到读入存储器中
*       检查所有的正确状态
*       将所有的正确状态并且符合每个状态的后面，push进head里面
*       状态计算
*/


#include <iostream>
#include <vector>
using namespace std;
const int N = 14, M = 1 << 12, mod = 1e8;

int n, m;
int w[N];
vector<int> state;
vector<int> head[M];
int f[N][M];

bool check(int state) {
    for (int i = 0; i + 1 < m; i++)
        if ((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
        {
            int t; cin >> t;
            w[i] |= !t * (1 << j);
        }

    for (int i = 0; i < 1 << m; i++)
        if (check(i))
            state.push_back(i);

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if (!(a & b))
                head[i].push_back(j);
        }
    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j < state.size(); j++)
            if (!(w[i] & state[j]))
                for (int k : head[j])
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
    cout << f[n + 1][0] << endl;


    return 0;
}