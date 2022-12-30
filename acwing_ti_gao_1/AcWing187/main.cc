/*
*	depth �������ȣ���������Ŀ�Ĵ𰸣�����һ���ж����ַ���
*   u     �����˵�ǰ�������λ��
*   su    �����˵�ǰ��������ĳ���
*   du    �����˵�ǰ�ݼ�����ĳ���
*/

#include <iostream>
using namespace std;
const int N = 55;
int up[N], down[N], w[N];
int n;
bool dfs(int depth, int u, int su, int du) {
	if (su + du > depth) return false; // ����������ȴ���depth
	if (u > n) return true; // �Ƿ����ȫ��
	
	bool flag = false;// flag �ж��Ƿ��ҵ��ˣ����û�ҵ����Ǿͻ��¿�һ��
	for (int i = 1; i <= su; i++)
		if (up[i] > w[u])  // �ҵ���һ�����ڵ�ǰ���ֵĵ�������
		{
			int t = up[i]; // �滻���� �����ݹ�
			up[i] = w[u];
			if (dfs(depth, u + 1, su, du)) return true;
			up[i] = t; // ���ԭ��
			flag = true; 
			break; // �ҵ����˳���
		}
	if (!flag) { // �¼�һ��
		up[su + 1] = w[u];
		if (dfs(depth, u + 1, su + 1, du)) return true;
	}
	
	flag = false; // ͬ��
	for (int i = 1; i <= du; i++)
		if (down[i] < w[u])
		{
			int t = down[i];
			down[i] = w[u];
			if (dfs(depth, u + 1, su, du)) return true;
			down[i] = t;
			flag = false;
			break;
		}
	if (!flag) {
		down[du + 1] = w[u];
		if (dfs(depth, u + 1, su, du + 1)) return true;
	}
	return false;
}
int main() {
	while (cin >> n, n) {
		for (int i = 1; i <= n; i++) cin >> w[i]; // �������֣�����Ŀ�ͷ1��0��ݹ��1��0���Ӧ������su,du�޹�
												  // ���du ��su��du,suֻ�����ȣ���up\down����������ΰڷ��޹�
		int depth = 0;
		while (!dfs(depth, 1, 0, 0)) depth++;
		cout << depth << endl;
	}
	return 0;
}