#include <iostream>
using namespace std;
const int N = 100000;
int arr[N];
int back[N];
int n;
void merge_sort(int l, int r) {
	if (l >= r) return;
	int mid = l + r >> 1;
	merge_sort(l, mid), merge_sort(mid + 1, r);
	int i = l, j = mid + 1, idx = l;
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) back[idx++] = arr[i++];
		else back[idx++] = arr[j++];
	}
	while (i <= mid)back[idx++] = arr[i++];
	while (j <= r) back[idx++] = arr[j++];
	for (int k = l; k <= r; k++)
		arr[k] = back[k];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
	return 0;
}