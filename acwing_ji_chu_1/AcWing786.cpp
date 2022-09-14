#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int len;
int q[N];
int quick_sort(int l, int r, int k) {
	if (l >= r) return q[l];
	int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
	while (i < j) {
		do {
			i ++;
		} while (q[i] < x);
		do {
			j --;
		} while (q[j] > x);
		if (i < j)swap(q[i], q[j]);
	}
	int s1 = j - l + 1;
	if (k <= s1)return quick_sort(l, j, k);
	return quick_sort(j + 1, r, k - s1);
}
int main() {
	int k;
	scanf("%d%d", &len, &k);
	for (int i = 0; i < len; i ++)scanf("%d", &q[i]);
	printf("%d", quick_sort(0, len - 1, k));
	return 0;
}
