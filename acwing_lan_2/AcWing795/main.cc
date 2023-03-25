#include <iostream>
using namespace std;
const int N = 100000 + 10;
int arr[N], s[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		s[i] = s[i - 1] + arr[i];
	}
	while (m--) {
		int l, r; cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;
	}


	return 0;
}