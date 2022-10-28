/*
* ���� $n$ �����Ȳ����� $10$ ���ַ����Լ� $m$ ��ѯ�ʣ�ÿ��ѯ�ʸ���һ���ַ�����һ�������������ޡ�

����ÿ��ѯ�ʣ�������������� $n$ ���ַ������ж��ٸ��ַ������������޲��������ھ����������ѯ�ʸ������ַ�����

ÿ�����ַ������еĵ����ַ��Ĳ��롢ɾ�����滻����һ�β�����

#### �����ʽ

��һ�а����������� $n$ �� $m$��

������ $n$ �У�ÿ�а���һ���ַ�������ʾ�������ַ�����

�ٽ����� $m$ �У�ÿ�а���һ���ַ�����һ����������ʾһ��ѯ�ʡ�

�ַ�����ֻ����Сд��ĸ���ҳ��Ⱦ������� $10$��

#### �����ʽ

����� $m$ �У�ÿ�����һ��������Ϊ�������ʾһ��ѯ���������������ַ���������

#### ���ݷ�Χ

$1 \\le n, m \\le 1000$,

#### ����������

	3 2
	abc
	acd
	bcd
	ab 1
	acbd 2


#### ���������

	1
	3
*/



#include <iostream>
#include <algorithm>
using namespace std;

const int N = 15, M = 1010;
int n, m;
int f[N][N];
char str[M][N];

int edit_disitance(char a[], char b[]) {
	int a1 = strlen(a + 1), b1 = strlen(b + 1);
	for (int i = 0; i <= b1; i++) f[0][i] = i;
	for (int i = 0; i <= a1; i++)f[i][0] = i;

	for (int i = 1; i <= a1; i++)
		for (int j = 1; j <= b1; j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
		}
	return f[a1][b1];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%s", str[i] + 1);

	while (m--) {
		char s[N];
		int limit;
		scanf("%s%d", s + 1, &limit);

		int res = 0;
		for (int i = 0; i < n; i++)
			if (edit_disitance(str[i], s) <= limit)
				res++;
		printf("%d\n", res);
	}

	return 0;
}