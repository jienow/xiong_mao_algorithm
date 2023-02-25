#include <iostream>
using namespace std;
const int N = 100000 + 10;
int arr[N], n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	while (m--) {
		int l, r; cin >> l >> r;
		cout << arr[r] - arr[l - 1] << endl;
	}
	return 0;
}