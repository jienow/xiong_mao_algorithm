#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 1e5 + 10;
int f[N];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i];

	unordered_map<int,int> map;
	int res = 0;
	for (int i = 1, j = 1; i <= n; i++)
	{
		map[f[i]]++;
		while (j <= n && map[f[i]] > 1) {
			map[f[j]]--;
			j++;
		}
		res = max(res, i - j + 1);
	}
	cout << res << endl;

	return 0;
}