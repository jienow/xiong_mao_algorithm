// ���д�ǰi����Ʒ��ѡ�����Ѳ�����V1,���Ѳ�����V2�������ѡ��
#include <iostream>
using namespace std;
const int N = 1010, M = 510;
int f[N][M];
int V1, V2, n;
int main() {
	cin >> V1 >> V2 >> n;
	for (int i = 1; i <= n; i++) {
		int v1, v2; cin >> v1 >> v2;
		// ������֮ǰ���޲�ͬ���������Լ���д�����ˣ���ţ�
		for (int j = V1; j >= v1; j--)
			for (int k = V2 - 1; k >= v2; k--) // k����������ĵ���������ֻ����V2-1
				f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
	}
	cout << f[V1][V2 - 1] << " ";
	int cost = V2 - 1;
	for (int k = V2 - 1; k >= 0; k--)
	{
		if (f[V1][V2 - 1] == f[V1][k]) // �ҵ��Ǹ������ȣ�����k��ͬ�ĵط�
			cost = min(cost,k); // ���ĵ���С��ʣ������
	}
	cout << V2 - cost << endl; // ��ȥ�Ǹ��õ�ʣ���
	return 0;
}