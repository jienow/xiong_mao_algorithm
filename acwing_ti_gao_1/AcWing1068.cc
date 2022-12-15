/*
*将 $n$ 堆石子绕圆形操场排放，现要将石子有序地合并成一堆。

规定每次只能选相邻的两堆合并成新的一堆，并将新的一堆的石子数记做该次合并的得分。

请编写一个程序，读入堆数 $n$ 及每堆的石子数，并进行如下计算：

*   选择一种合并石子的方案，使得做 $n-1$ 次合并得分总和最大。
*   选择一种合并石子的方案，使得做 $n-1$ 次合并得分总和最小。

#### 输入格式

第一行包含整数 $n$，表示共有 $n$ 堆石子。

第二行包含 $n$ 个整数，分别表示每堆石子的数量。

#### 输出格式

输出共两行：

第一行为合并得分总和最小值，

第二行为合并得分总和最大值。

#### 数据范围

$1 \\le n \\le 200$

#### 输入样例：

	4
	4 5 9 4


#### 输出样例：

	43
	54
*/
/*
* 这个题的主要思路是将原本的n个长度的石子变成2n个长度的石子
* 题目的思路是将一个环形的石子的最短
* 然后解题的思路是将n变成2n，然后dp这个2n，找到其中的n个长度的最大值，就是原来环形的最大值
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N = 410, INF = 0x3f3f3f3f;
int n;
int f[N][N], g[N][N];
int w[N], s[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)  // 环形长度，需要2n个大小
	{
		cin >> w[i];
		w[i + n] = w[i];
	}
	for (int i = 1; i <= 2 * n; i++) // 求和
		s[i] = s[i - 1] + w[i];

	memset(f, 0x3f, sizeof f);
	memset(g, -0x3f, sizeof g);

	for (int len = 1; len <= n; len++) // 枚举长度
		for (int l = 1; l + len - 1 <= 2 * n; l++) // 枚举作曲兼，并且右区间不能大于2n
		{
			int r = l + len - 1;
			if (l == r) g[l][r] = f[l][r] = 0; // 当l == r 时，不和定义，设值为0
			else
				for (int k = l;k < r; k++) // dp这个区间
				{
					f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
					g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
				}
		}
	int maxv = -INF, minv = INF;
	for (int i = 1; i <= n; i++) // 枚举最大值，就是求那个一开始的缺口
	{
		maxv = max(maxv, g[i][i + n - 1]);
		minv = min(minv, f[i][i + n - 1]);
	}
	cout << minv << endl << maxv << endl;

	return 0;
}