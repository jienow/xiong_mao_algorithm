#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 5010;
int f[N];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<PII> vec;
	for (int i = 1; i <= n; i++)
	{
		int a, b; cin >> a >> b;
		vec.emplace_back(PII{ a,b });
	}

	sort(vec.begin(), vec.end());

	int res = 0;
	for (int i = 0; i < n; i++) {
		f[i] = 1;
		for (int j = 0; j < i; j++)
			if (vec[i].second > vec[j].second)
				f[i] = max(f[i], f[j] + 1);
		res = max(res, f[i]);
	}
	cout << res << endl;

	return 0;
}