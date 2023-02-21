#include <iostream>
using namespace std;
const int N = 100000;
int arr[N],n, K;
int quick_sort(int l, int r, int k) {
	if (l >= r)return arr[k];
	int x = arr[l + r >> 1], i = l - 1, j = r + 1;
	while (i < j) {
		do i++; while (arr[i] < x);
		do j--; while (arr[j] > x);
		if (i < j) swap(arr[i], arr[j]);
	}
	if (j >= k)return quick_sort(l, j, k);
	else return quick_sort(j + 1, r, k);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> K;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int num = quick_sort(0, n - 1, K-1);
	cout << num << endl;
	return 0;
}