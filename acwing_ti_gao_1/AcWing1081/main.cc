#include <iostream>
#include <vector>
using namespace std;
const int N = 50;
int f[N][N];
int X, Y, K, B;
void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!j) f[i][j] = 1;
			else f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
}
int dp(int u) {
	if (!u) return 0;

	vector<int> nums;
	while (u) nums.push_back(u % B), u /= B;

	int last = 0;
	int res = 0;
	for (int i = nums.size() - 1; i >= 0; i--) {
		int x = nums[i];
		if (x > 0) {
			res += f[i][K - last];
			if (x > 1) {
				if (K - last - 1 >= 0)res += f[i][K - last - 1];
				break;
			}
			else {
				last++;
				if(last > K)break;
			}
		}
		if (i == 0 && last == K) res++;
	}
	return res;
}
int main() {
	init();
	cin >> X >> Y >> K >> B;
	cout << dp(Y) - dp(X - 1) << endl;
	return 0;
}