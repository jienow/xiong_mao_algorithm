/*
* �� $N$ ����Ʒ��һ�������� $V$ �ı�����

�� $i$ ����Ʒ����� $s\_i$ ����ÿ������� $v\_i$����ֵ�� $w\_i$��

��⽫��Щ��Ʒװ�뱳������ʹ��Ʒ����ܺͲ����������������Ҽ�ֵ�ܺ����  
�������ֵ��

#### �����ʽ

��һ������������$N��V$ $(0 \\lt N \\le 1000$, $0 \\lt V \\le 20000)$���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���

�������� $N$ �У�ÿ���������� $v\_i, w\_i, s\_i$���ÿո�������ֱ��ʾ�� $i$ ����Ʒ���������ֵ��������

#### �����ʽ

���һ����������ʾ����ֵ��

#### ���ݷ�Χ

$0 \\lt N \\le 1000$  
$0 \\lt V \\le 20000$  
$0 \\lt v\_i, w\_i, s\_i \\le 20000$

##### ��ʾ

���⿼����ر����ĵ��������Ż�������

#### ��������

    4 5
    1 2 3
    2 4 1
    3 4 3
    4 5 2
    

#### ���������

    10
*/

#include <iostream>
#include <cstring>
const int N = 21010;
using namespace std;
int dp[N], pre[N], q[N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		memcpy(pre, dp, sizeof dp);
		int v, w, s;
		cin >> v >> w >> s;
		for (int j = 0; j < v; j++) {
			int head = 0, tail = -1;
			for (int k = j; k <= m; k += v) {
				if (head <= tail && k - s * v > q[head])
					++head;
				while (head <= tail && pre[q[tail]] - (q[tail] - j) / v * w <= pre[k] - (k - j) / v * w)
					--tail;

				if (head <= tail)
					dp[k] = max(dp[k], pre[q[head]] + (k - q[head]) / v * w);

				q[++tail] = k;
			}
		}
	}
	cout << dp[m] << endl;
	return 0;
}