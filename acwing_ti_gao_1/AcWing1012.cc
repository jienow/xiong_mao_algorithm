/*
* Palmia国有一条横贯东西的大河，河有笔直的南北两岸，岸上各有位置各不相同的N个城市。

北岸的每个城市有且仅有一个友好城市在南岸，而且不同城市的友好城市不相同。

每对友好城市都向政府申请在河上开辟一条直线航道连接两个城市，但是由于河上雾太大，政府决定避免任意两条航道交叉，以避免事故。

编程帮助政府做出一些批准和拒绝申请的决定，使得在保证任意两条航线不相交的情况下，被批准的申请尽量多。

#### 输入格式

第1行，一个整数N，表示城市数。

第2行到第n+1行，每行两个整数，中间用1个空格隔开，分别表示南岸和北岸的一对友好城市的坐标。

#### 输出格式

仅一行，输出一个整数，表示政府所能批准的最多申请数。

#### 数据范围

$1 \\le N \\le 5000$,  
$0 \\le x\_i \\le 10000$

#### 输入样例：

    7
    22 4
    2 6
    10 3
    15 12
    9 8
    17 17
    4 2
    

#### 输出样例：

    4
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5010;
typedef pair<int, int> PII;
PII q[N];
int f[N];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d%d", &q[i].first, &q[i].second);
    sort(q, q + n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (q[j].second < q[i].second)
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res << endl;

	return 0;
}