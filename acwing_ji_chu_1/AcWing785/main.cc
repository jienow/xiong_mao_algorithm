#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int f[N];
int n;
void quick_sort(int l, int r) {
	if (l >= r) return;
	int x = f[l + r >> 1], i = l - 1, j = r + 1;
	while (i < j) {
		do i++; while (f[i] < x);
		do j--; while (f[j] > x);
		if (i < j) swap(f[i], f[j]);
	}
	quick_sort(l, j);
	quick_sort(j + 1, r);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i];

	quick_sort(1, n);
	for (int i = 1; i <= n; i++)
		cout << f[i] << " ";

	return 0;
}