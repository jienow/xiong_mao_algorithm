#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5010;
typedef pair<int, int> PII;
typedef long long LL;
LL f[N], n;
PII w[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i].first >> w[i].second;
	sort(w + 1, w + n + 1);

	LL res = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (w[i].second > w[j].second)
				f[i] = max(f[i], f[j] + 1);
		res = max(res, f[i]);
	}
	cout << res << endl;

	return 0;
}