/*
本文系「人工智能安全」（微信公众号）原创，转载请联系本文作者（同博客作者）。
欢迎你转发分享至朋友圈，并给予「关注、星标、点赞」三连支持。互相欣赏，互相批判。
我是一名有诗人气质的网络安全工程师
期待与你的思想交流碰撞出智慧的花火
水木清华
2020-04-16
矩阵乘法
*/
#include <iostream>
using namespace std;
//矩阵乘法的函数接口
int MatrixMultiplication (int x, int y, int z) {
    int number; //矩阵元素
    //用数组来存储矩阵
    int A[x][y]; //矩阵 A
    int B[y][z]; //矩阵 B
    int ans[x][z]; //矩阵 C
    //输入矩阵 A
    for (int i = 0; i < x; i++) {
        for (int k = 0; k < y; k++) {
            cin >> number;
            A[i][k] = number;
        }
    }
    //输入矩阵 B
    for (int k = 0; k < y; k++) {
        for (int j = 0; j < z; j++) {
            cin >> number;
            B[k][j] = number;
        }
    }
    //计算矩阵 C
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            ans[i][j] = 0; //初始化矩阵 C 的每个元素，置为 0。若缺少这个，有些测试示例不通过。
            for (int k = 0; k < y; k++) {
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    //输出矩阵 C
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl; //换行，输出矩阵的下一行元素
    }
    return 0;
}
//主函数
int main() {
    int inputx1;
    int inputy1x2;
    int inputy2;
    while (cin >> inputx1 >> inputy1x2 >> inputy2) {
        MatrixMultiplication(inputx1, inputy1x2, inputy2);
    }
    return 0;
}