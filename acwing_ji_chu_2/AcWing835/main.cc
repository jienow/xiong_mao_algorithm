#include <iostream>
using namespace std;
const int N = 2e5 + 20;
char str[N];
int son[N][26], cnt[N], idx;
/*
* son �� cnt������������Ͽ��Կ�����ƽ�е��������飬idxͬʱ��������������
*/
int n;
void insert(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		char u = str[i];
		if (!son[p][u]) son[p][u] = ++idx; // ����ֻ����++idx����Ϊ0������ͬʱҲ������û�б�ʹ�ã���idxһ��ʼ����0
		p = son[p][u];
	}
	cnt[p] ++;
}
int query(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		char u = str[i];
		if (!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		char op[2]; cin >> op >> str;
		if (op[0] == 'I') 
			insert(str);
		else {
			int a = query(str);
			cout << a << endl;
		}
	}
	return 0;
}