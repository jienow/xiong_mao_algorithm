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

	// k 表示求的是位置，cnt求的是数量
	// 所以k最大是cnt-1
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		while (k < cnt && g[k] < q[i]) k++; // 正常情况下k < cnt的 , 等于cnt的时候就是添加了一个组
		g[k] = q[i]; // 赋值
		if (k == cnt) cnt++; // 等于,记录新组
	}
	cout << cnt << endl;

	return 0;
}