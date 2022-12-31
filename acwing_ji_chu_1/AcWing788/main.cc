/*
*  Ԥ�������5 6 1 midָ��6��Ȼ��merge��������������Ļ�������1,�Ӷ����ٽ��
*  ��������������ᷢ�������봦������õ��Ŀ϶���5 1 6��Ȼ��õ�һ��1
*/
#include <iostream>
using namespace std;
const int N = 100010;
typedef long long LL;
int f[N], tmp[N];
int n;
LL merge_sort(int l, int r) {
	if (l >= r) return 0;
	int mid = l + r >> 1;
	LL all = merge_sort(l, mid) + merge_sort(mid + 1, r);
	int k = 1, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (f[i] <= f[j])
			tmp[k++] = f[i++];
		else {
			tmp[k++] = f[j++];
			all += mid - i + 1;
		}
	while (i <= mid) tmp[k++] = f[i++];
	while (j <= r) tmp[k++] = f[j++];
	for (int i = l, j = 1; i <= r; i++, j++)
		f[i] = tmp[j];
	return all;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i];
	
	cout << merge_sort(1, n);

	return 0;
}