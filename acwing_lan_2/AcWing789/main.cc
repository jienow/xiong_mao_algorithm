#include <iostream>
using namespace std;
const int N = 100000 + 10;
int arr[N];
int main() {
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	while (q--) {
		int x; cin >> x;
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (arr[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if (arr[l] != x) cout << "-1 -1" << endl;
		else {
			cout << l - 1 << " ";
			l = 1, r = n;
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (arr[mid] <= x) l = mid;
				else r = mid - 1;
			}
			cout << l - 1<< endl;
		}
	}
	return 0;
}