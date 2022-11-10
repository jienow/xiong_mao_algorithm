/*
* 总公司拥有 $M$ 台 **相同** 的高效设备，准备分给下属的 $N$ 个分公司。

各分公司若获得这些设备，可以为国家提供一定的盈利。盈利与分配的设备数量有关。

问：如何分配这M台设备才能使国家得到的盈利最大？

求出最大盈利值。

分配原则：每个公司有权获得任意数目的设备，但总台数不超过设备数 $M$。

#### 输入格式

第一行有两个数，第一个数是分公司数 $N$，第二个数是设备台数 $M$；

接下来是一个 $N \\times M$ 的矩阵，矩阵中的第 $i$ 行第 $j$ 列的整数表示第 $i$ 个公司分配 $j$ 台机器时的盈利。

#### 输出格式

第一行输出最大盈利值；

接下 $N$ 行，每行有 $2$ 个数，即分公司编号和该分公司获得设备台数。

答案不唯一，输出任意合法方案即可。

#### 数据范围

$1 \\le N \\le 10$,
$1 \\le M \\le 15$

#### 输入样例：

	3 3
	30 40 50
	20 30 50
	20 25 30


#### 输出样例：

	70
	1 1
	2 1
	3 1
*/

/*
* 这跟之前学的背包问题没有任何区别，如果有区别，那就是脑筋急转问的问题，如果想通了，
* 把之前学的背包问题套进去就可以了
* i,j都是之前的双层循环，但是k就是之前的v只不过从原来的输入v转变成为了从头开始遍历，
* 
* 第二个循环
* j的意思是当前一共有多少个机器
* 思路是把第一个大循环从后往前过一遍，把之前的w减去，
* 并且记录当前的k(当前公司应该需要k个机器)
*/


#include <iostream>
using namespace std;
const int N = 11, M = 16;
int f[N][M];
int w[N][M];
int way[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> w[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= j; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
	cout << f[n][m] << endl;

	int j = m;
	for (int i = n; i; i--)
		for (int k = 0; k <= j; k++)
			if (f[i][j] == f[i - 1][j - k] + w[i][k])
			{
				way[i] = k;
				j -= k;
				break;
			}
	for (int i = 1; i <= n; i++)cout << i << " " << way[i] << endl;

	return 0;
}