#include <iostream>
using namespace std;
const int N = 100000 + 10;
int arr[N], n, m;
void add(int l, int r, int num) {
	arr[l] += num;
	arr[r + 1] -= num;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		add(i, i, num);
	}
	for (int i = 1; i <= m; i++) {
		int l, r, c; cin >> l >> r >> c;
		add(l, r, c);
	}
	for (int i = 1; i <= n; i++) {
		arr[i] += arr[i - 1];
		cout << arr[i] << endl;
	}
	return 0;
}