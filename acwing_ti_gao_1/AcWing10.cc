/*
* 有 $N$ 个物品和一个容量是 $V$ 的背包。

物品之间具有依赖关系，且依赖关系组成一棵树的形状。如果选择一个物品，则必须选择它的父节点。

如下图所示：
![QQ图片20181018170337.png](/media/article/image/2018/10/18/1_bb51ecbcd2-QQ图片20181018170337.png)

如果选择物品5，则必须选择物品1和2。这是因为2是5的父节点，1是2的父节点。

每件物品的编号是 $i$，体积是 $v\_i$，价值是 $w\_i$，依赖的父节点编号是 $p\_i$。物品的下标范围是 $1 … N$。

求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。

输出最大价值。

#### 输入格式

第一行有两个整数 $N，V$，用空格隔开，分别表示物品个数和背包容量。

接下来有 $N$ 行数据，每行数据表示一个物品。
第 $i$ 行有三个整数 $v\_i, w\_i, p\_i$，用空格隔开，分别表示物品的体积、价值和依赖的物品编号。
如果 $p\_i = -1$，表示根节点。 **数据保证所有物品构成一棵树。**

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

$1 \\le N, V \\le 100$
$1 \\le v\_i, w\_i\\le 100$

父节点编号范围：

*   内部结点：$1 \\le p\_i \\le N$;
*   根节点 $p\_i = -1$;

#### 输入样例

	5 7
	2 3 -1
	2 2 1
	3 5 1
	4 7 2
	3 6 2


#### 输出样例：

	11
*/


#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
int f[N][N];
int h[N], e[N], ne[N], idx;
int v[N], w[N];
int n, m;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u) {
	for (int i = h[u]; ~i; i = ne[i]) { // 循环所有的节点
		int son = e[i]; // 拿到当前的子节点的value
		dfs(son); // 深搜这个子节点
		for (int j = m - v[u]; j >= 0; j--) // 循环所有的体积
			for (int k = 0; k <= j; k++) // 循环所有的决策
				f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
				// 求这个节点的最大值
	}
	for (int i = m; i >= v[u]; i--)
		f[u][i] = f[u][i - v[u]] + w[u]; // 将当前的节点加入到f数组中
	for (int i = 0; i < v[u]; i++)
		f[u][i] = 0; // 将不合法的点都置为0
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int root;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++)
	{
		int p;
		cin >> v[i] >> w[i] >> p;
		if (p == -1) root = i;
		else add(p, i);
	}
	dfs(root);
	cout << f[root][m] << endl;

	return 0;
}