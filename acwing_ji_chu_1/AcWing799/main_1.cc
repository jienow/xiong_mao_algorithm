#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 1e5 + 10;
int arr[N], n;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	unordered_map<int, int> hash;
	int res = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		hash[arr[i]] ++;
		while (j <= n && hash[arr[i]] > 1) {
			hash[arr[j]]--;
			j++;
		}
		res = max(res, i - j + 1);
	}
	cout << res << endl;
	return 0;
}