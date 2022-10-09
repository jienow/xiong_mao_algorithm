/*
* 给定一个整数 $n$，将数字 $1 \\sim n$ 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

#### 输入格式

共一行，包含一个整数 $n$。

#### 输出格式

按字典序输出所有排列方案，每个方案占一行。

#### 数据范围

$1 \\le n \\le 7$

#### 输入样例：

	3


#### 输出样例：

	1 2 3
	1 3 2
	2 1 3
	2 3 1
	3 1 2
	3 2 1
*/

#include <iostream>
using std::cout;
using std::endl;
const int N = 10;
int arr[N], n;
bool st[N];
void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= n; ++i) {
			printf("%d ", arr[i]);
		}
		puts("");
	}
	else
		for (int i = 1; i <= n; ++i) {
			if (!st[i]) {
				arr[u] = i;
				st[i] = true;
				dfs(u + 1);
				st[i] = false;
				arr[u] = 0;
			}
		}
}
int main() {
	scanf("%d", &n);
	dfs(1);
	return 0;
}