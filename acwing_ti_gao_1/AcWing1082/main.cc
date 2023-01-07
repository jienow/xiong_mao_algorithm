#include <iostream>
#include <vector>
using namespace std;
const int N = 15;
int f[N][N]; // һ����i�����֣���j��λ��������j�Ĵ����Ƕ���
int a, b;
void init() {
	for (int i = 0; i <= 9; i++)f[1][i] = 1;  
	for (int i = 2; i < N; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = j; k <= 9; k++)
				f[i][j] += f[i - 1][k]; // ��һλ�����λ���ٲ��Һ�һλ�Ĵ�С�ĸ��󣨻���ڣ�
}
int dp(int n) {
	if (!n) return 1;
	
	vector<int> nums;
	while (n) nums.push_back(n % 10), n /= 10; 

	int res = 0, last = 0; // res�ǽ������������last��ǰһλ�����֣�Ҳ�Ǻ�һλ��С������
	for (int i = nums.size() - 1; i >= 0; i--) {
		int x = nums[i]; // �õ���ǰλ��
		for (int j = last; j < x; j++) // ö�ٺ�һλ����last��С��һֱ��x��
			res += f[i + 1][j]; // i + 1�Ǹ�����i���±�
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