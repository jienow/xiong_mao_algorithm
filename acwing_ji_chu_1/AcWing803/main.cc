#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
typedef pair<int, int> PII;
PII f[N];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		int l, r; cin >> l >> r;
		f[i].first = l, f[i].second = r;
	}

	sort(f, f + n);

	int res = 1;
	int hr = f[1].second;
	for (int i = 2; i <= n; i++)
	{
		int l = f[i].first;
		if (l > hr)res++;
		hr = max(hr, f[i].second);
	}
	cout << res << endl;

	return 0;
}