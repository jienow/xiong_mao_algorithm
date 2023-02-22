#include <iostream>
using namespace std;
const int N = 100000;
long long  arr[N];
long long back[N];
int n;
int merge_sort(int l, int r) {
	if (l >= r) return 0;
	int mid = (l + r) >> 1, i = l, j = mid + 1, idx = l;
	int num = merge_sort(l, mid) + merge_sort(mid + 1, r);
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) {
			back[idx++] = arr[i++];
		}
		else { back[idx++] = arr[j++]; num += mid - i + 1; }
	}
	while (i <= mid) back[idx++] = arr[i++];
	while (j <= r) back[idx++] = arr[j++];
	for (int k = l; k <= r; k++)
		arr[k] = back[k];
	return num;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	printf("%lld", merge_sort(0, n - 1));
	return 0;
}