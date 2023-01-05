#include <iostream>
#include <string>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
int n, m, ne[N];
char q[N], s[M];
int main() {
	ios::sync_with_stdio(false);
	scanf("%d%s%d%s", &n, q + 1, &m, s + 1);

	for (int i = 2, j = 0; i <= n; i++) { // i表示的是主串，而j表示的是匹配串
		while (j /*如果j没有ne到初始点*/ && q[i] != q[j + 1]) j = ne[j]; // 回到ne点上
		if (q[i] == q[j + 1]) j++; // 如果相等那就到下一个点上
		ne[i] = j; // 读入ne值
	}

	for (int i = 2, j = 1; i <= m; i++) { // 两个串不一定非得同步增减
		while (j && s[i] != q[j + 1])j = ne[j];
		if (s[i] == q[j + 1]) j++;
		if (j == n) {
			cout << i - j << " ";
			j = ne[j];
		}
	}


	return 0;
}