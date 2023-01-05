#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int f[N], sz = 1;
int h[N], q[N];
int num, n;
int main() {
	ios::sync_with_stdio(false);

	while (cin >> num) {
		h[sz++] = num;
	}
	sz -= 1;

	int res = 0;
	for (int i = sz; i >= 1; i--) {
		q[i] = 1;
		for (int j = sz; j > i; j--)
			if (h[i] > h[j])
				q[i] = max(q[i], q[j] + 1);
		res = max(res, q[i]);
	}
	cout << res << endl;


	for (int j = 1; j <= sz; j++)
	{
		int num = h[j];
		int i = 1;
		while (i <= n && f[i] < num) i++;
		if (i == n + 1) n++;
		f[i] = num;
	}
	cout << n;
	return 0;
}