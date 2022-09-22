/*
输入一个 $n$ 行 $m$ 列的整数矩阵，再输入 $q$ 个操作，每个操作包含五个整数 $x\_1, y\_1, x\_2, y\_2, c$，其中 $(x\_1, y\_1)$ 和 $(x\_2, y\_2)$ 表示一个子矩阵的左上角坐标和右下角坐标。

每个操作都要将选中的子矩阵中的每个元素的值加上 $c$。

请你将进行完所有操作后的矩阵输出。

#### 输入格式

第一行包含整数 $n,m,q$。

接下来 $n$ 行，每行包含 $m$ 个整数，表示整数矩阵。

接下来 $q$ 行，每行包含 $5$ 个整数 $x\_1, y\_1, x\_2, y\_2, c$，表示一个操作。

#### 输出格式

共 $n$ 行，每行 $m$ 个整数，表示所有操作进行完毕后的最终矩阵。

#### 数据范围

$1 \\le n,m \\le 1000$,
$1 \\le q \\le 100000$,
$1 \\le x\_1 \\le x\_2 \\le n$,
$1 \\le y\_1 \\le y\_2 \\le m$,
$\-1000 \\le c \\le 1000$,
$\-1000 \\le 矩阵内元素的值 \\le 1000$

#### 输入样例：

    3 4 3
    1 2 2 1
    3 2 2 1
    1 1 1 1
    1 1 2 2 1
    1 3 2 3 2
    3 1 3 4 1


#### 输出样例：

    2 3 4 1
    4 3 4 1
    2 2 2 2
*/

//#include <iostream>
//using namespace std;
//const int N = 1010;
//int b[N][N], n, m, k;
//void insert(int x1,int y1,int x2,int y2,int num){
//    b[x1][y1] += num;
//    b[x2 + 1][y1] -= num;
//    b[x1][y1 + 1] -= num;
//    b[x2 + 1][y2 + 1] += num;
//}
//int main(){
//    cin >> n >> m >> k;
//    for (int i = 1; i <= n;i ++)
//        for (int j = 1; j <= m;j ++){
//            int num;
//            cin >> num;
//            insert(i, j, i, j, num);
//        }
//    while(k--){
//        int x1, x2, y1, y2, num;
//        cin >> x1 >> y1 >> x2 >> y2 >> num;
//        insert(x1, y1, x2, y2, num);
//    }
//    for (int i = 1; i <= n;i++){
//        for (int j = 1; j <= m;j++){
//            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
//            printf("%d ", b[i][j]);
//        }
//        puts("");
//    }
//    return 0;
//}

#include <iostream>
using namespace std;
const int N = 1010;
int b[N][N];
int n, m, k;
void insert(int x1,int y1,int x2,int y2,int num){
    b[x1][y1] += num;
    b[x2 + 1][y1] -= num;
    b[x1][y2 + 1] -= num;
    b[x2 + 1][y2 + 1] += num;
}
int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i ++)
        for (int j = 1; j <= m; j++){
            int num;
            cin >> num;
            insert(i, j, i, j, num);
        }
    while(k--){
        int x1, y1, x2, y2, num;
        cin >> x1 >> y1 >> x2 >> y2 >> num;
        insert(x1, y1, x2, y2, num);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m;j ++){
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ", b[i][j]);
        }
        puts("");
    }

        return 0;
}