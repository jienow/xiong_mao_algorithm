#include <iostream>
using namespace std;
const int N = 6010;
int f[N];
int n, m;
int main() {
	// 几乎所有的多重背包问题都是将问题转换成为01背包问题来求解的
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int v, w, s;
		cin >> v >> w >> s;
		for (int j = m; j >= 0; --j)
			for (int k = 0; k <= s && k * v <= j; k++)
				f[j] = max(f[j], f[j - k * v] + k * w);
	}
	cout << f[m] << endl;
	return 0;
}