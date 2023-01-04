#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int arr[N], q[N];
int n, k, hh, tt = -1;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	// i - k + 1    ~     i ֮���Ǵ���
	// q[hh]        ~     q[tt] ֮���Ƕ��У������Ǳ�֤�����еĴ���
	for (int i = 1; i <= n; i++) {
		if (hh <= tt /*���зǿ�*/ && i - k + 1 > q[hh] /*�жϴ����Ƿ���������¶�ͷ*/) hh++;
		while (hh <= tt && arr[q[tt]] >= arr[i]) /*��֤������*/
			tt--;
		q[++tt] = i;
		if (i >= k) cout << arr[q[hh]] << " "; /*������ڵĳ��ȴ�꣬�������ֵ*/
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