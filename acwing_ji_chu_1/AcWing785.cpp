/*
给定两个正整数（不含前导 $0$），计算它们的和。

#### 输入格式

共两行，每行包含一个整数。

#### 输出格式

共一行，包含所求的和。

#### 数据范围

$1 \\le 整数长度 \\le 100000$

#### 输入样例：

    12
    23
    

#### 输出样例：

    35
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int len;
int q[N];
void quick_sort(int l, int r) {
	if (l >= r)return ;
	int x = q[l + r >> 1], i = l - 1, j = r + 1;
	while (i < j) {
		do i ++ ;
		while (q[i] < x);
		do j -- ;
		while (q[j] > x);
		if (i < j)swap(q[i], q[j]);
	}
	quick_sort(l, j);
	quick_sort(j + 1, r);
}
int main() {
	scanf("%d", &len);
	for (int i = 0; i < len; i ++)scanf("%d", &q[i]);
	quick_sort(0, len - 1);
	for (int i = 0; i < len; i ++)printf("%d ", q[i]);
	return 0;
}
