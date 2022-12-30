/*
*	depth 代表的深度，代表了题目的答案，就是一共有多少种方案
*   u     代表了当前的数组的位置
*   su    代表了当前递增数组的长度
*   du    代表了当前递减数组的长度
*/

#include <iostream>
using namespace std;
const int N = 55;
int up[N], down[N], w[N];
int n;
bool dfs(int depth, int u, int su, int du) {
	if (su + du > depth) return false; // 如果两个长度大于depth
	if (u > n) return true; // 是否遍历全部
	
	bool flag = false;// flag 判定是否找到了，如果没找到，那就会新开一个
	for (int i = 1; i <= su; i++)
		if (up[i] > w[u])  // 找到第一个大于当前数字的递增数组
		{
			int t = up[i]; // 替换并且 继续递归
			up[i] = w[u];
			if (dfs(depth, u + 1, su, du)) return true;
			up[i] = t; // 变回原来
			flag = true; 
			break; // 找到后退出来
		}
	if (!flag) { // 新加一行
		up[su + 1] = w[u];
		if (dfs(depth, u + 1, su + 1, du)) return true;
	}
	
	flag = false; // 同上
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
		for (int i = 1; i <= n; i++) cin >> w[i]; // 读入数字，这里的开头1或0与递归的1或0相对应，但与su,du无关
												  // 如果du 与su，du,su只代表长度，与up\down组内数字如何摆放无关
		int depth = 0;
		while (!dfs(depth, 1, 0, 0)) depth++;
		cout << depth << endl;
	}
	return 0;
}