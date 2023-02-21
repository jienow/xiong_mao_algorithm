#include <iostream>
using namespace std;
const int N = 100000;
int arr[N], n;
void quick_sort(int l, int r) {
	if (l >= r) return;
	int x = arr[l + r >> 1], i = l - 1, j = r + 1;
	while (i < j) {
		do i++; while (arr[i] < x);
		do j--; while (arr[j] > x);
		if (i < j) swap(arr[i], arr[j]);
	}
	quick_sort(l, j), quick_sort(j + 1, r);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	quick_sort(0, n - 1);
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
	return 0;
}