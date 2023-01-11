#include <iostream>
using namespace std;
const int N = 100010;
int f[N], a[N], n;
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int len = 0;
	f[0] = -2e9;
	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = len;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (f[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		len = max(len, r + 1);
		f[r + 1] = a[i];
	}
	cout << len << endl;
	return 0;
}