/*
给定一个浮点数 $n$，求它的三次方根。

#### 输入格式

共一行，包含一个浮点数 $n$。

#### 输出格式

共一行，包含一个浮点数，表示问题的解。

注意，结果保留 $6$ 位小数。

#### 数据范围

$\-10000 \\le n \\le 10000$

#### 输入样例：

    1000.00
    

#### 输出样例：

    10.000000
*/

#include <iostream>
using namespace  std;
int main(){
    double x;
    cin >> x;
    double l = -10000, r = 10000, mid = 0;
    while (r - l > 1e-8){
        mid = (l + r) / 2;
        if(mid*mid*mid >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%.6f", mid);
    return 0;
}
