/*
*求把 $N \\times M$ 的棋盘分割成若干个 $1 \\times 2$ 的长方形，有多少种方案。

例如当 $N=2，M=4$ 时，共有 $5$ 种方案。当 $N=2，M=3$ 时，共有 $3$ 种方案。

如下图所示：

![2411_1.jpg](/media/article/image/2019/01/26/19_4dd1644c20-2411_1.jpg)

#### 输入格式

输入包含多组测试用例。

每组测试用例占一行，包含两个整数 $N$ 和 $M$。

当输入用例 $N=0，M=0$ 时，表示输入终止，且该用例无需处理。

#### 输出格式

每个测试用例输出一个结果，每个结果占一行。

#### 数据范围

$1 \\le N,M \\le 11$

#### 输入样例：

    1 2
    1 3
    1 4
    2 2
    2 3
    2 4
    2 11
    4 11
    0 0
    

#### 输出样例：

    1
    0
    1
    2
    3
    5
    144
    51205 
*/


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 12, M = 1 << N;
int n, m;
long long f[N][M];
vector<int> state[M];
bool st[M];

int main() {
    
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            bool is_vaild = true;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1) {
                    if (cnt & 1) {
                        is_vaild = false; break;
                    }
                    cnt = 0;
                }
                else cnt++;
            }
            if (cnt & 1) is_vaild = false;
            st[i] = is_vaild;
        }


        for (int i = 0; i < (1 << n); i++) {
            state[i].clear();
            for (int j = 0; j < (1 << n); j++)
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;

        for (int i = 1; i <= m; i++)
            for (int j = 0; j < (1 << n); j++)
                for (int k : state[j])
                    f[i][j] += f[i - 1][k];
        cout << f[m][0] << endl;

    }

    return 0;
}