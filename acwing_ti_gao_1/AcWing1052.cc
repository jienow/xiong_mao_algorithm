/*
* 你现在需要设计一个密码 $S$，$S$ 需要满足：

*   $S$ 的长度是 $N$；
*   $S$ 只包含小写英文字母；
*   $S$ 不包含子串 $T$；

例如：$abc$ 和 $abcde$ 是 $abcde$ 的子串，$abd$ 不是 $abcde$ 的子串。

请问共有多少种不同的密码满足要求？

由于答案会非常大，请输出答案模 $10^9+7$ 的余数。

#### 输入格式

第一行输入整数N，表示密码的长度。

第二行输入字符串T，T中只包含小写字母。

#### 输出格式

输出一个**正整数**，表示总方案数模 $10^9+7$ 后的结果。

#### 数据范围

$1 \\le N \\le 50$,  
$1 \\le |T| \\le N$，$|T|$是$T$的长度。

#### 输入样例1：

    2
    a
    

#### 输出样例1：

    625
    

#### 输入样例2：

    4
    cbc
    

#### 输出样例2：

    456924
*/



#include <iostream> 
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55, mod = 1e9 + 7;

int n, m;
int f[N][N];
int nxt[N];
char str[N];

int main() {
    cin >> n;
    scanf("%s", str + 1);
    
    m = strlen(str + 1);
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && str[i] != str[j + 1]) j = nxt[j];
        if (str[i] == str[j + 1]) j++;
        nxt[i] = j;
    }

    f[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (char k = 'a'; k <= 'z'; k++)
            {
                int u = j;
                while (u && k != str[u + 1]) u = nxt[u];
                if (k == str[u + 1]) u++;
                if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
            }

    int res = 0;
    for (int i = 0; i < m; i++)
        res = (res + f[n][i]) % mod;
    cout << res << endl;

	return 0;
}