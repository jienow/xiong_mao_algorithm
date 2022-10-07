// #include <stdio.h>
// int mg[6][6] = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 1, 1}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};

// typedef struct
// {
//     int i;
//     int j;
//     int di;
// } Box;
// typedef struct
// {
//     Box data[16];
//     int top;
// } StType;
// void Initstack(StType*);
// bool StackEmpty(StType*);
// void Push(StType*, Box&);
// void GetTop(StType*, Box&);
// void Pop(StType*, Box&);
// void DestroyStack(StType*);

// int mgpath(int xi, int yi, int xe, int ye)
// {
//     Box path[16], e;
//     int i, j, di, i1, j1, k;
//     int find;
//     StType *st;
//     Initstack(st);
//     e.i = xi;
//     e.j = yi;
//     e.di = -1;
//     Push(st, e);
//     mg[xi][yi] = -1;
//     while (!StackEmpty(st))

//     {
//         GetTop(st, e);
//         i = e.i;
//         j = e.j;
//         di = e.di;
//         if (i == xe && j == ye)

//         {
//             printf("一条迷宫路径如下：\n");
//             k = 0;
//             while (!StackEmpty(st))

//             {
//                 Pop(st, e);
//                 path[k++] = e;
//             }
//             while (k > 0)

//             {
//                 printf("\t(%d,%d)", path[k - 1].i, path[k - 1].j);
//                 if ((k + 1) % 5 == 0)
//                     printf("\n");
//                 k--;
//             }
//             printf("\n");
//             DestroyStack(st);
//             return 1;
//         }
//         find = 0;
//         while (di < 4 && !find)

//         {
//             di++;
//             switch (di)

//             {
//             case 0:
//                 i1 = i - 1;
//                 j1 = j;
//                 break;
//             case 1:
//                 i1 = i;
//                 j1 = j + 1;
//                 break;
//             case 2:
//                 i1 = i + 1;
//                 j1 = j;
//                 break;
//             case 3:
//                 i1 = i;
//                 j1 = j - 1;
//                 break;
//             }
//             if (mg[i1][j1] == 0)
//                 find = 1;
//         }
//         if (find)

//         {
//             st->data[st->top].di = di;
//             e.i = i1;
//             e.j = j1;
//             e.di = -1;
//             Push(st, e);
//             mg[i1][j1] = -1;
//         }
//         else
//         {
//             Pop(st, e);
//             mg[e.i][e.j] = 0;
//         }
//     }
//     DestroyStack(st);
//     return 0;
// }
// int main()
// {
//     if (!mgpath(1, 1, 4, 4))
//         printf("该迷宫问题没有解");
//     return 1;
// }


#include <iostream>
using namespace std;
int main(){
    cout << "hello world" << endl;
    //cout << fmt::format("hello{}",42) << endl;
    cout << "hello world" << endl;
    return 0;
}