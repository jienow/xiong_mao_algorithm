/*
* ����һ������ $n$�������� $1 \\sim n$ �ų�һ�ţ������кܶ������з�����

���ڣ����㰴���ֵ������е����з��������

#### �����ʽ

��һ�У�����һ������ $n$��

#### �����ʽ

���ֵ�������������з�����ÿ������ռһ�С�

#### ���ݷ�Χ

$1 \\le n \\le 7$

#### ����������

	3


#### ���������

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