/*给定一个具有 $N$ 个顶点的凸多边形，将顶点从 $1$ 至 $N$ 标号，每个顶点的权值都是一个正整数。

将这个凸多边形划分成 $N-2$ 个互不相交的三角形，对于每个三角形，其三个顶点的权值相乘都可得到一个权值乘积，试求所有三角形的顶点权值乘积之和至少为多少。

#### 输入格式

第一行包含整数 $N$，表示顶点数量。

第二行包含 $N$ 个整数，依次为顶点 $1$ 至顶点 $N$ 的权值。

#### 输出格式

输出仅一行，为所有三角形的顶点权值乘积之和的最小值。

#### 数据范围

$N \\le 50$,  
数据保证所有顶点的权值都小于$10^9$

#### 输入样例：

    5
    121 122 123 245 231
    

#### 输出样例：

    12214884
*/


#include <iostream>
#include <cstring> 
using namespace std;
const int N = 55, M = 35, INF = 1e9;
typedef long long LL;

int n;
int w[N];
LL f[N][N][M];

void add(LL a[], LL b[]) {
    static LL c[M];
    for (int i = 0, t = 0; i < M; i++)
    {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}
void mult(LL a[], int b) {
    static LL c[M];
    LL t = 0;
    for (int i = 0; i < M; i++) {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}
int cmp(LL a[], LL b[]) {
    for (int i = M - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return 0;
}
void print(LL a[]) {
    int k = M - 1;
    while (k && !a[k]) k--;
    while (k >= 0) cout << a[k--];
    cout << endl;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    LL tmp[M];
    for (int len = 3; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
			f[l][r][M - 1] = 1;
            for (int k = l + 1; k < r; k++)
            {
                memset(tmp, 0, sizeof tmp);
                tmp[0] = w[l];
                mult(tmp, w[k]);
                mult(tmp, w[r]);
                add(tmp, f[l][k]);
                add(tmp, f[k][r]);
                if (cmp(f[l][r], tmp) > 0)
                    memcpy(f[l][r], tmp, sizeof tmp);
            }
        }
    print(f[1][n]);
    return 0;
}
