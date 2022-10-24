/*
* 给定一个长度为 $N$ 的数列，求数值严格单调递增的子序列的长度最长是多少。

#### 输入格式

第一行包含整数 $N$。

第二行包含 $N$ 个整数，表示完整序列。

#### 输出格式

输出一个整数，表示最大长度。

#### 数据范围

$1 \\le N \\le 100000$，  
$\-10^9 \\le 数列中的数 \\le 10^9$

#### 输入样例：

    7
    3 1 2 1 8 5 6
    

#### 输出样例：

    4
*/

/*
* 二刷
* 这道题目如果只从代码的角度来看的话，他是创建了一个又一个分支
* 1.如果从一开始就没有更换，而是一直往后排，就是一整个分支的样子
* 2.如果从中间发现了在某一个阶段有更优的解法，就会将这个解法放到那个阶段上面
*   从而创建了一个分支,这个分支一定是更优的，因为它更小
* 3.因为我们求的是整个子序列‘单调递增’的‘最长’的那个,所以只会更新那个阶段/分支
* 后面的不会更新就是因为当前阶段是后出现的.
*/
#include <iostream>
using namespace std;
const int N = 100010;
int a[N], q[N];
int n;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1>> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    cout << len << endl;
	return 0;
}