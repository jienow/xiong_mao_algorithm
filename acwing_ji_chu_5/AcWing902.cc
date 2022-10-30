/*
* ���������ַ��� $A$ �� $B$������Ҫ�� $A$ �������ɲ�����Ϊ $B$���ɽ��еĲ����У�

1.  ɾ���C���ַ��� $A$ �е�ĳ���ַ�ɾ����
2.  ����C���ַ��� $A$ ��ĳ��λ�ò���ĳ���ַ���
3.  �滻�C���ַ��� $A$ �е�ĳ���ַ��滻Ϊ��һ���ַ���

��������������� $A$ ��Ϊ $B$ ������Ҫ���ж��ٴβ�����

#### �����ʽ

��һ�а������� $n$����ʾ�ַ��� $A$ �ĳ��ȡ�

�ڶ��а���һ������Ϊ $n$ ���ַ��� $A$��

�����а������� $m$����ʾ�ַ��� $B$ �ĳ��ȡ�

�����а���һ������Ϊ $m$ ���ַ��� $B$��

�ַ����о�ֻ������Сд��ĸ��

#### �����ʽ

���һ����������ʾ���ٲ���������

#### ���ݷ�Χ

$1 \\le n, m \\le 1000$

#### ����������

	10
	AGTCTGACGC
	11
	AGTAAGTAGGC


#### ���������

	4
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];
int main() {
	scanf("%d%s", &n, a + 1);
	scanf("%d%s", &m, b + 1);


	for (int i = 0; i <= n; i++) f[i][0] = i;
	for (int i = 0; i <= m; i++) f[0][i] = i;


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	printf("%d\n", f[n][m]);

	return 0;
}