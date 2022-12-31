#include <iostream>
using namespace std;
const int N = 100010;
int f[N];
int n, k;
int quick_sort(int l, int r, int k) {
	if (l >= r) return f[l];
	int x = f[l + r >> 1], i = l - 1, j = r + 1;
	while (i < j) {
		do i++; while (f[i] < x);
		do j--; while (f[j] > x);
		if (i < j) swap(f[i], f[j]);
	}
	if (k <= j) return quick_sort(l, j, k); // ����ȵ����±꣬��y�д�s1��k�������ǳ���
	else return quick_sort(j + 1, r, k);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> f[i];
	cout << quick_sort(1, n, k);
	return 0;
}