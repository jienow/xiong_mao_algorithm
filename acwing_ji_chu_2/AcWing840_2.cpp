/*
维护一个集合，支持如下几种操作：

1.  `I x`，插入一个数 $x$；
2.  `Q x`，询问数 $x$ 是否在集合中出现过；

现在要进行 $N$ 次操作，对于每个询问操作输出对应的结果。

#### 输入格式

第一行包含整数 $N$，表示操作数量。

接下来 $N$ 行，每行包含一个操作指令，操作指令为 `I x`，`Q x` 中的一种。

#### 输出格式

对于每个询问指令 `Q x`，输出一个询问结果，如果 $x$ 在集合中出现过，则输出 `Yes`，否则输出 `No`。

每个结果占一行。

#### 数据范围

$1 \\le N \\le 10^5$  
$\-10^9 \\le x \\le 10^9$

#### 输入样例：

    5
    I 1
    I 2
    I 3
    Q 2
    Q 5
    

#### 输出样例：

    Yes
    No
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, null = 0x3f3f3f3f;
int h[N];
int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x){
        k++;
        if (k == N)
            k = 0;
    }
    return k;
}
int main() {
    int n;
    scanf("%d", &n);
    memset(h, 0x3f, sizeof h);
    while(n--){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I')
            h[find(x)] = x;
        else {
            if (h[find(x)] == x)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}