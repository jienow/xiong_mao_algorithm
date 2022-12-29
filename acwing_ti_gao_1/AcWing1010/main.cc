#include <iostream>
using namespace std;
const int N = 1010;
int f[N], q[N], g[N];
int n;
int main() {
	while (cin >> q[n]) n++;

	int res = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		f[i] = 1;
		for (int j = n - 1; j > i; j--)
			if (q[i] >= q[j])
				f[i] = max(f[i], f[j] + 1);
		res = max(res, f[i]);
	}
	cout << res << endl;

	// k ��ʾ�����λ�ã�cnt���������
	// ����k�����cnt-1
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		while (k < cnt && g[k] < q[i]) k++; // ���������k < cnt�� , ����cnt��ʱ����������һ����
		g[k] = q[i]; // ��ֵ
		if (k == cnt) cnt++; // ����,��¼����
	}
	cout << cnt << endl;

	return 0;
}