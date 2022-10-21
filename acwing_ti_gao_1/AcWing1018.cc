/*
* 一个商人穿过一个 $N×N$ 的正方形的网格，去参加一个非常重要的商务活动。

他要从网格的左上角进，右下角出。

每穿越中间 $1$ 个小方格，都要花费 $1$ 个单位时间。

商人必须在 $(2N-1)$ 个单位时间穿越出去。

而在经过中间的每个小方格时，都需要缴纳一定的费用。

这个商人期望在规定时间内用最少费用穿越出去。

请问至少需要多少费用？

注意：不能对角穿越各个小方格（即，只能向上下左右四个方向移动且不能离开网格）。

#### 输入格式

第一行是一个整数，表示正方形的宽度 $N$。

后面 $N$ 行，每行 $N$ 个不大于 $100$ 的正整数，为网格上每个小方格的费用。

#### 输出格式

输出一个整数，表示至少需要的费用。

#### 数据范围

$1 \\le N \\le 100$

#### 输入样例：

    5
    1  4  6  8  10
    2  5  7  15 17
    6  8  9  18 20
    10 11 12 19 21
    20 23 25 29 33
    

#### 输出样例：

    109
    

#### 样例解释

样例中，最小值为 $109=1+2+5+7+9+12+19+21+33$。
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
int arr[N][N];
int n;
int main() {
    ios::sync_with_stdio(false);
    memset(arr, N, sizeof arr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == 1 && j == 1) continue;
            else arr[i][j] = min(arr[i - 1][j] + arr[i][j], arr[i][j - 1] + arr[i][j]);
    cout << arr[n][n];
    return 0;
}