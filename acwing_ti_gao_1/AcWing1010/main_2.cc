#include <iostream>
using namespace std;
const int N = 1010;
int a[N], f[N], q[N], n;
int main() {
	ios::sync_with_stdio(false);
	while (cin >> a[n]) n++;

	int res = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		f[i] = 1;
		for (int j = n - 1; j > i; j--)
			if (a[i] >= a[j])
				f[i] = max(f[i], f[j] + 1);
		res = max(res, f[i]);
	}
	cout << res << endl;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		while (k < cnt && q[k] < a[i]) k++;
		q[k] = a[i];
		if (k >= cnt) cnt++;
	}
	cout << cnt << endl;

	return 0;
}