/*
* С��������nԪǮȫ���������飬��ļ۸�Ϊ10Ԫ��20Ԫ��50Ԫ��100Ԫ��

��С���ж��������鷽������ÿ����ɹ���౾��

#### �����ʽ

һ������ n�������ܹ�Ǯ����

#### �����ʽ

һ������������ѡ�񷽰�������

#### ���ݷ�Χ

$0 \\le n \\le 1000$

#### ��������1��

	20


#### �������1��

	2


#### ��������2��

	15


#### �������2��

	0


#### ��������3��

	0


#### �������3��

	1
*/

#include <iostream>
#include <array>
using namespace std;
const int N = 1010;
array<int, N> f;
array<int, 4> v{ 10,20,50,100 };
int n;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	f[0] = 1;
	for (int i = 0; i < 4; ++i)
		for (int j = v[i]; j <= n; ++j)
			f[j] += f[j - v[i]];
	cout << f[n] << endl;

	return 0;
}