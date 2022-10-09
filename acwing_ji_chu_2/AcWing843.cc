/*
$n-$�ʺ�������ָ�� $n$ ���ʺ���� $n \\times n$ �Ĺ������������ϣ�ʹ�ûʺ����໥�������������������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϡ�

![1_597ec77c49-8-queens.png](https://cdn.acwing.com/media/article/image/2019/06/08/19_860e00c489-1_597ec77c49-8-queens.png)

���ڸ������� $n$������������е��������������Ӱڷ���

#### �����ʽ

��һ�У��������� $n$��

#### �����ʽ

ÿ���������ռ $n$ �У�ÿ�����һ������Ϊ $n$ ���ַ�����������ʾ����������״̬��

���� `.` ��ʾĳһ��λ�õķ���״̬Ϊ�գ�`Q` ��ʾĳһ��λ�õķ����ϰ��Żʺ�

ÿ�����������ɺ����һ�����С�

**ע�⣺��ĩ�����ж���ո�**

���������˳�����⣬ֻҪ���ظ���û����©���ɡ�

#### ���ݷ�Χ

$1 \\le n \\le 9$

#### ����������

	4


#### ���������

	.Q..
	...Q
	Q...
	..Q.

	..Q.
	Q...
	...Q
	.Q..
*/

#include <iostream>
using std::cout, std::endl, std::cin;
const int N = 20;
bool cow[N], dg[N], udg[N];
char g[N][N];
int n;
void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++)puts(g[i]);
		puts("");
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!cow[i] && !dg[i + u] && !udg[u - i + n]) {
				g[u][i] = 'Q';
				cow[i] = dg[i + u] = udg[u - i + n] = true;
				dfs(u + 1);
				cow[i] = dg[i + u] = udg[u - i + n] = false;
				g[u][i] = '.';
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';
	dfs(0);
	return 0;
}