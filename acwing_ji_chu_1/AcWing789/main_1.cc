#include <iostream>
using namespace std;
const int N = 100010;
int arr[N], n, q;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	while (q--) {
		int num; cin >> num;
		int l = 1, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (arr[mid] < num)l = mid + 1;
			else r = mid;
		}
		if (arr[l] != num) {
			cout << "-1 -1" << endl;
			continue;
		}
		cout << l - 1 << " ";
		l = 1, r = n;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (arr[mid] > num) r = mid - 1;
			else l = mid;
		}
		cout << l - 1 << endl;
	}

	return 0;
}