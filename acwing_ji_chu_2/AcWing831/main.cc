#include <iostream>
#include <string>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
int n, m, ne[N];
char q[N], s[M];
int main() {
	ios::sync_with_stdio(false);
	scanf("%d%s%d%s", &n, q + 1, &m, s + 1);

	for (int i = 2, j = 0; i <= n; i++) { // i��ʾ������������j��ʾ����ƥ�䴮
		while (j /*���jû��ne����ʼ��*/ && q[i] != q[j + 1]) j = ne[j]; // �ص�ne����
		if (q[i] == q[j + 1]) j++; // �������Ǿ͵���һ������
		ne[i] = j; // ����neֵ
	}

	for (int i = 2, j = 1; i <= m; i++) { // ��������һ���ǵ�ͬ������
		while (j && s[i] != q[j + 1])j = ne[j];
		if (s[i] == q[j + 1]) j++;
		if (j == n) {
			cout << i - j << " ";
			j = ne[j];
		}
	}


	return 0;
}