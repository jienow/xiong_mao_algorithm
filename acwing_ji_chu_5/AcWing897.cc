/*
* 给定两个长度分别为 $N$ 和 $M$ 的字符串 $A$ 和 $B$，求既是 $A$ 的子序列又是 $B$ 的子序列的字符串长度最长是多少。

#### 输入格式

第一行包含两个整数 $N$ 和 $M$。

第二行包含一个长度为 $N$ 的字符串，表示字符串 $A$。

第三行包含一个长度为 $M$ 的字符串，表示字符串 $B$。

字符串均由小写字母构成。

#### 输出格式

输出一个整数，表示最大长度。

#### 数据范围

$1 \\le N,M \\le 1000$

#### 输入样例：

    4 5
    acbd
    abedc
    

#### 输出样例：

    3
*/

/*
* 集合：在a[1-i]和b[1-j]中子序列最大的长度
* 属性：最大值
* 状态计算：a[i]不选和b[j]不选,f[i-1][j-1]
*          a[i]不选和b[j]选,f[i-1][j]
*          a[i]选和b[j]不选,f[i][j-1]
*          a[i]选和b[j]选，f[i][j] = f[i-1][j-1] + 1 表示长度
*/

#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];
int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    for (int i = 1;i <= n;i ++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    cout << f[n][m] << endl;
    return 0;
}