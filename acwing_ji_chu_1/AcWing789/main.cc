#include <iostream>
using namespace std;
const int N = 100010;
int f[N];
int n,q;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i < n; i++)cin >> f[i];

	while (q--) {
		int num; cin >> num;
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (f[mid] >= num) r = mid;
			else l = mid + 1;
		}
		if (f[l] != num) {
			cout << "-1 -1" << endl;
			continue;
		}
		cout << l << " ";
		l = 0, r = n - 1;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (f[mid] <= num) l = mid;
			else r = mid - 1;
		}
		cout << l << endl;
	}
	return 0;
}