#include <iostream>
using namespace std;
const int N = 1010;
int w[N], n;
int f[N], f2[N];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (w[i] > w[j])
				f[i] = max(f[i], f[j] + 1);
	}
	for (int i = n; i >= 1; i--) {
		f2[i] = 1;
		for (int j = n; j > i; j--)
			if (w[i] > w[j])
				f2[i] = max(f2[i], f2[j] + 1);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res = max(res, f[i] + f2[i] - 1);
	cout << res << endl;



	return 0;
}