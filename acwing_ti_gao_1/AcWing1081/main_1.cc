#include <iostream>
#include <vector>
using namespace std;
const int N = 35;
int f[N][N];
int X, Y, K, B;
void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!j) f[i][j] = 1;
			else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
}
int dp(int x) {
	if (!x) return 0;

	vector<int> nums;
	while (x) nums.push_back(x % B), x /= B;

	int res = 0, last = 0;
	for (int i = nums.size() - 1; i >= 0; i--) {
		int x = nums[i];
		if (x) {
			res += f[i][K - last];
			if (x > 1) {
				if (K - last >= 1) res += f[i][K - last - 1];
				break;
			}
			else {
				last++;
				if (last > K) break;
			}
		}
		if (!i && K == last) res++;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	init();
	cin >> X >> Y >> K >> B;
	cout << dp(Y) - dp(X - 1) << endl;
	return 0;
}