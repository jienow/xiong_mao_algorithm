#include <iostream>
using namespace std;
const int N = 1010;
int f[N], n, q[N];
int g[N];
int main() {
	ios::sync_with_stdio(false);
	while (cin >> f[n]) n++;

	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		q[i] = 1;
		for (int j = n - 1; j > i; j--)
			if (f[i] >= f[j])
				q[i] = max(q[i], q[j] + 1);
		res = max(res, q[i]);
	}
	cout << res << endl;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		while (k < cnt && g[k] < f[i]) k++;
		g[k] = f[i];
		if (k >= cnt) cnt++;
	}
	cout << cnt << endl;

	return 0;
}