/*
* 阿福是一名经验丰富的大盗。趁着月黑风高，阿福打算今晚洗劫一条街上的店铺。

这条街上一共有 $N$ 家店铺，每家店中都有一些现金。

阿福事先调查得知，只有当他同时洗劫了两家相邻的店铺时，街上的报警系统才会启动，然后警察就会蜂拥而至。

作为一向谨慎作案的大盗，阿福不愿意冒着被警察追捕的风险行窃。

他想知道，在不惊动警察的情况下，他今晚最多可以得到多少现金？

#### 输入格式

输入的第一行是一个整数 $T$，表示一共有 $T$ 组数据。

接下来的每组数据，第一行是一个整数 $N$ ，表示一共有 $N$ 家店铺。

第二行是 $N$ 个被空格分开的正整数，表示每一家店铺中的现金数量。

每家店铺中的现金数量均不超过1000。

#### 输出格式

对于每组数据，输出一行。

该行包含一个整数，表示阿福在不惊动警察的情况下可以得到的现金数量。

#### 数据范围

$1 \\le T \\le 50$,  
$1 \\le N \\le 10^5$

#### 输入样例：

    2
    3
    1 8 2
    4
    10 7 6 14
    

#### 输出样例：

    8
    24
    

#### 样例解释

对于第一组样例，阿福选择第2家店铺行窃，获得的现金数量为8。

对于第二组样例，阿福选择第1和4家店铺行窃，获得的现金数量为10+14=24。
*/


//#include <iostream>
//using namespace std;
//const int N = 20010, INF = 0x3f3f3f3f;
//int f[N][2];
//int w[N];
//int main() {
//    ios::sync_with_stdio(false);
//    int T; cin >> T;
//    while (T--) {
//        int n; cin >> n;
//        for (int i = 1; i <= n; i++) cin >> w[i];
//        f[0][0] = 0; f[0][1] = -INF;
//        for (int i = 1; i <= n; i++)
//        {
//            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
//            f[i][1] = f[i - 1][0] + w[i];
//        }
//        cout << max(f[n][0], f[n][1]) << endl;
//    }
//    return 0;
//}

#include <iostream>
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f;
int f[N][2];
int w[N];
int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> w[i];
        f[0][0] = 0; f[0][1] = -INF;
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + w[i];
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }
    return 0;
}