#include <iostream>
#include <vector>
using namespace std;
const int N = 15;
int f[N][N]; // 一共有i个数字，第j个位置上面填j的次数是多少
int a, b;
void init() {
	for (int i = 0; i <= 9; i++)f[1][i] = 1;  
	for (int i = 2; i < N; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = j; k <= 9; k++)
				f[i][j] += f[i - 1][k]; // 后一位，填的位数少并且后一位的大小的更大（或等于）
}
int dp(int n) {
	if (!n) return 1;
	
	vector<int> nums;
	while (n) nums.push_back(n % 10), n /= 10; 

	int res = 0, last = 0; // res是结果（数量），last是前一位的数字，也是后一位最小的数字
	for (int i = nums.size() - 1; i >= 0; i--) {
		int x = nums[i]; // 拿到当前位数
		for (int j = last; j < x; j++) // 枚举后一位，是last最小，一直到x上
			res += f[i + 1][j]; // i + 1是个数，i是下标
		if (x < last) break;
		last = x;
		if (!i) res++;
	}
	return res;


}
int main() {
	ios::sync_with_stdio(false);
	init();
	while (cin >> a >> b) {
		cout << dp(b) - dp(a - 1) << endl;
	}
	return 0;
}