/*
给定一个长度为 $n$ 的整数数列，以及一个整数 $k$，请用快速选择算法求出数列从小到大排序后的第 $k$ 个数。

#### 输入格式

第一行包含两个整数 $n$ 和 $k$。

第二行包含 $n$ 个整数（所有整数均在 $1 \\sim 10^9$ 范围内），表示整数数列。

#### 输出格式

输出一个整数，表示数列的第 $k$ 小数。

#### 数据范围

$1 \\le n \\le 100000$,
$1 \\le k \\le n$

#### 输入样例：

	5 3
	2 4 1 5 3


#### 输出样例：

	3
*/

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int len;
int q[N];
int quick_sort(int l, int r, int k)
{
	if (l >= r)
		return q[l];
	int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
	while (i < j)
	{
		do
		{
			i++;
		} while (q[i] < x);
		do
		{
			j--;
		} while (q[j] > x);
		if (i < j)
			swap(q[i], q[j]);
	}
	int s1 = j - l + 1;
	if (k <= s1)
		return quick_sort(l, j, k);
	return quick_sort(j + 1, r, k - s1);
}
int main()
{
	int k;
	scanf("%d%d", &len, &k);
	for (int i = 0; i < len; i++)
		scanf("%d", &q[i]);
	printf("%d", quick_sort(0, len - 1, k));
	return 0;
}
