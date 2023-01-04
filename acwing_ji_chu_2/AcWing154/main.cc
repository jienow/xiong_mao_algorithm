#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int arr[N], q[N];
int n, k, hh, tt = -1;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	// i - k + 1    ~     i 之间是窗口
	// q[hh]        ~     q[tt] 之间是队列，队列是保证单调行的窗口
	for (int i = 1; i <= n; i++) {
		if (hh <= tt /*队列非空*/ && i - k + 1 > q[hh] /*判断窗口是否过长，更新队头*/) hh++;
		while (hh <= tt && arr[q[tt]] >= arr[i]) /*保证单调性*/
			tt--;
		q[++tt] = i;
		if (i >= k) cout << arr[q[hh]] << " "; /*如果窗口的长度达标，就输出最值*/
	}

	cout << endl;

	hh = 0, tt = -1;
	for (int i = 1; i <= n; i++) {
		if (hh <= tt && i - k + 1 > q[hh]) hh++;
		while (hh <= tt && arr[q[tt]] <= arr[i])
			tt--;
		q[++tt] = i;
		if (i >= k) cout << arr[q[hh]] << " ";
	}

	return 0;
}