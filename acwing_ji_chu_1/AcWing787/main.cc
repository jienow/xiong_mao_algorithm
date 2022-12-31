#include <iostream>
using namespace std;
const int N = 100010;
int f[N];
int w[N];
int n;
void merge_sort(int l, int r) {
	if (l >= r) return;
	int mid = l + r >> 1;
	merge_sort(l, mid), merge_sort(mid + 1, r);
	int k = 1, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (f[j] <= f[i])
			w[k++] = f[j++];
		else w[k++] = f[i++];
	while (i <= mid) w[k++] = f[i++];
	while (j <= r) w[k++] = f[j++];
	for (int i = l,j = 1; i <= r; i++,j ++)
		f[i] = w[j];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> f[i];

	merge_sort(1, n);

	for (int i = 1; i <= n; i++)
		cout << f[i] << " ";

	return 0;
}