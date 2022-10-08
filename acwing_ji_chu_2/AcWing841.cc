/*
给定一个长度为 $n$ 的字符串，再给定 $m$ 个询问，每个询问包含四个整数 $l\_1, r\_1, l\_2, r\_2$，请你判断 $\[l\_1, r\_1\]$ 和 $\[l\_2, r\_2\]$ 这两个区间所包含的字符串子串是否完全相同。

字符串中只包含大小写英文字母和数字。

#### 输入格式

第一行包含整数 $n$ 和 $m$，表示字符串长度和询问次数。

第二行包含一个长度为 $n$ 的字符串，字符串中只包含大小写英文字母和数字。

接下来 $m$ 行，每行包含四个整数 $l\_1, r\_1, l\_2, r\_2$，表示一次询问所涉及的两个区间。

注意，字符串的位置从 $1$ 开始编号。

#### 输出格式

对于每个询问输出一个结果，如果两个字符串子串完全相同则输出 `Yes`，否则输出 `No`。

每个结果占一行。

#### 数据范围

$1 \\le n, m \\le 10^5$

#### 输入样例：

	8 3
	aabbaabb
	1 3 5 7
	1 3 6 8
	1 2 1 2


#### 输出样例：

	Yes
	No
	Yes
*/

/*
这个题目的主要收获是我之前的思维一直都是左边的是低位，右边的是高位
这个题目是左边是高位，右边是低位，所以思路一开始就错了
应该将h[i-1]左移就是乘P，但是要是右边是高位就应该让str[i]乘P加上h[i-1]
*/

#include <iostream>
using std::cout;
using std::endl;
const int N = 1e5 + 10, P = 131;
typedef unsigned long long ULL;
ULL h[N], p[N];
char str[N];
ULL get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main() {
	int n, m;
	scanf("%d%d%s", &n, &m, str + 1);
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}
	while (m--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (get(l1, r1) == get(l2, r2)) puts("Yes");
		else puts("No");
	}

	return 0;
}