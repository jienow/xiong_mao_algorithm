#include <iostream>
using namespace std;
const int N = 10010;
int f[N], w[N];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i];
	// f[i][j] ��ʾǰi�����֣���Ϊj�ķ��������
	f[0] = 1;
	for (int i = 1; i <= n; i++) { // ѡ���һ����Ʒ
		for (int j = m; j >= w[i]; j--) // 
			f[j] += f[j - w[i]]; // j-w[i]�Ǹ����־����Ǹ�λ�ü��ϵ�ǰ�����ֵ���j
	}
	cout << f[m] << endl;
	return 0;
}