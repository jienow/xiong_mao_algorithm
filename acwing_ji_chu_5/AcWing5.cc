/*
* �� $N$ ����Ʒ��һ�������� $V$ �ı�����

�� $i$ ����Ʒ����� $s\_i$ ����ÿ������� $v\_i$����ֵ�� $w\_i$��

��⽫��Щ��Ʒװ�뱳������ʹ��Ʒ����ܺͲ����������������Ҽ�ֵ�ܺ����
�������ֵ��

#### �����ʽ

��һ������������$N��V$���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���

�������� $N$ �У�ÿ���������� $v\_i, w\_i, s\_i$���ÿո�������ֱ��ʾ�� $i$ ����Ʒ���������ֵ��������

#### �����ʽ

���һ����������ʾ����ֵ��

#### ���ݷ�Χ

$0 \\lt N \\le 1000$
$0 \\lt V \\le 2000$
$0 \\lt v\_i, w\_i, s\_i \\le 2000$

##### ��ʾ��

���⿼����ر����Ķ������Ż�������

#### ��������

	4 5
	1 2 3
	2 4 1
	3 4 3
	4 5 2


#### ���������

	10
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1010;
struct Good {
	int v, w;
}g[N];
int f[N * 2];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	vector<Good> vec;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int v, w, s;
		cin >> v >> w >> s;
		for (int k = 1; k <= s; k++) {
			s -= k;
			vec.emplace_back(Good{ v * k,w * k });
		}
		if (s > 0)vec.emplace_back(Good{ v * s,w * s });
	}
	for (auto i : vec)
		for (int j = m; j >= i.v; --j)
			f[j] = max(f[j], f[j - i.v] + i.w);
	cout << f[m] << endl;
	return 0;
}