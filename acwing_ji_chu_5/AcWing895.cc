/*
* ����һ������Ϊ $N$ �����У�����ֵ�ϸ񵥵������������еĳ�����Ƕ��١�

#### �����ʽ

��һ�а������� $N$��

�ڶ��а��� $N$ ����������ʾ�������С�

#### �����ʽ

���һ����������ʾ��󳤶ȡ�

#### ���ݷ�Χ

$1 \\le N \\le 1000$��
$\-10^9 \\le �����е��� \\le 10^9$

#### ����������

	7
	3 1 2 1 8 5 6


#### ���������

	4
*
*/


#include <iostream>
using namespace std;
const int N = 1010;
int f[N], res[N];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		res[i] = 1;
	}
	int ans = 1;
	for (int i = 1; i  <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (f[i] > f[j]) {
				res[i] = max(res[j] + 1, res[i]);
				ans = max(ans, res[i]);
			}
	cout << ans;
	return 0;
}

//521