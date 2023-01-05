给定一个包含 $n$ 个点（编号为 $1 \\sim n$）的无向图，初始时图中没有边。

现在要进行 $m$ 个操作，操作共有三种：

1.  `C a b`，在点 $a$ 和点 $b$ 之间连一条边，$a$ 和 $b$ 可能相等；
2.  `Q1 a b`，询问点 $a$ 和点 $b$ 是否在同一个连通块中，$a$ 和 $b$ 可能相等；
3.  `Q2 a`，询问点 $a$ 所在连通块中点的数量；

#### 输入格式

第一行输入整数 $n$ 和 $m$。

接下来 $m$ 行，每行包含一个操作指令，指令为 `C a b`，`Q1 a b` 或 `Q2 a` 中的一种。

#### 输出格式

对于每个询问指令 `Q1 a b`，如果 $a$ 和 $b$ 在同一个连通块中，则输出 `Yes`，否则输出 `No`。

对于每个询问指令 `Q2 a`，输出一个整数表示点 $a$ 所在连通块中点的数量

每个结果占一行。

#### 数据范围

$1 \\le n,m \\le 10^5$

#### 输入样例：

    5 5
    C 1 2
    Q1 1 2
    Q2 1
    C 2 5
    Q2 5
    

#### 输出样例：

    Yes
    2
    3
1
No
No
Yes
1
1
No
1
1
Yes
2
1
1
1
1
Yes
1
1
1
No
1
No
No
Yes
1
1
2
1
No
1
No
1
1
1
No
1
No
No
1
Yes
1
Yes
No
Yes
1
2
No
1
1
2
1
6
Yes
No
1
1
No
Yes
1
1
2
4
Yes
No
No
2
3
1
1
No
No
No
No
6
Yes
1
Yes
2
Yes
No
1
Yes
4
No
2
1
4
2
No
1
2
2
2
No
No
No
No
Yes
Yes
Yes
2
4
1
Yes
No
1
2
No
No
No
No
2
2
Yes
No
3
Yes
18
1
8
2
No
6
8
No
Yes
1
No
No
20
Yes
29
No
No
1
8
7
