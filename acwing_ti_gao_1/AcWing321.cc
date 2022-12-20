/*
* 将一个 $8 \\times 8$ 的棋盘进行如下分割：将原棋盘割下一块矩形棋盘并使剩下部分也是矩形，再将剩下的部分继续如此分割，这样割了 $(n-1)$ 次后，连同最后剩下的矩形棋盘共有 $n$ 块矩形棋盘。(每次切割都只能沿着棋盘格子的边进行)

![1191_1.jpg](/media/article/image/2019/02/05/19_32dad08629-1191_1.jpg)

原棋盘上每一格有一个分值，一块矩形棋盘的总分为其所含各格分值之和。

现在需要把棋盘按上述规则分割成 $n$ 块矩形棋盘，并使各矩形棋盘总分的均方差最小。

均方差![formula.png](/media/article/image/2019/02/05/19_566d096029-formula.png) ，其中平均值![lala.png](/media/article/image/2019/02/05/19_047fe57229-lala.png) ，$x\_i$ 为第 $i$ 块矩形棋盘的总分。

请编程对给出的棋盘及 $n$，求出均方差的最小值。

#### 输入格式

第 $1$ 行为一个整数 $n$。

第 $2$ 行至第 $9$ 行每行为 $8$ 个小于 $100$ 的非负整数，表示棋盘上相应格子的分值。每行相邻两数之间用一个空格分隔。

#### 输出格式

输出最小均方差值（四舍五入精确到小数点后三位）。

#### 数据范围

$1 < n < 15$

#### 输入样例：

    3
    1 1 1 1 1 1 1 3
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 0
    1 1 1 1 1 1 0 3
    

#### 输出样例：

    1.633
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 18, M = 9, INF = 0x3f3f3f3f;
int s[M][M];
double f[N][N][N][N][M];
int n, m = 8;
double X;
double get_sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}
double get(int x1, int y1, int x2, int y2) {
    int sum = get_sum(x1, y1, x2, y2) - X;
    return (double) sum * sum / n;
}
double dp(int x1, int y1, int x2, int y2, int k) {
    double& v = f[x1][y1][x2][y2][k];
    if (v >= 0) return v;
    if (k == 1) return v = get(x1, y1, x2, y2);

    v = INF;
    for (int i = x1; i < x2; i++)
    {
        v = min(v, get(i + 1,y1,x2,y2) + dp(x1, y1, i, y2, k - 1));
        v = min(v, get(x1, y1, i, y2) + dp(i + 1, y1, x2, y2, k - 1));
    }
    for (int i = y1; i < y2; i++)
    {
        v = min(v, get(x1, y1, x2, i) + dp(x1, i + 1, x2, y2, k - 1));
        v = min(v, get(x1, i + 1, x2, y2) + dp(x1, y1, x2, i,k-1));
    }
    return v;
}
int main() {
    cin >> n;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    X = (double)s[m][m] / n;
    memset(f, -1, sizeof f);
    printf("%.3lf", sqrt(dp(1, 1, 8, 8, n)));
	return 0;
}