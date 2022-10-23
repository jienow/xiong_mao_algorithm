/*
* 给定一个长度为 $N$ 的数列，求数值严格单调递增的子序列的长度最长是多少。

#### 输入格式

第一行包含整数 $N$。

第二行包含 $N$ 个整数，表示完整序列。

#### 输出格式

输出一个整数，表示最大长度。

#### 数据范围

$1 \\le N \\le 1000$，
$\-10^9 \\le 数列中的数 \\le 10^9$

#### 输入样例：

	7
	3 1 2 1 8 5 6


#### 输出样例：

	4
*
*/


#include <iostream>
using namespace std;
const int N = 1010;
int f[N], res[N];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		res[i] = 1;
	}
	int ans = 1;
	for (int i = 1; i  <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (f[i] > f[j]) {
				res[i] = max(res[j] + 1, res[i]);
				ans = max(ans, res[i]);
			}
	cout << ans;
	return 0;
}

//521