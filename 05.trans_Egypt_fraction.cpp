#include<iostream>
#include<string>
using namespace std;

/* 
用递归来实现，只需要把更新后的分子分母送入递归函数即可。

递归的出口有两个：
一个是分子为1，可以直接输出，出递归；
一个是分母可以整除分子，也可以直接输出然后出递归。

我们再加一个优化，因为当 b%(a−1)=0时，有a/b=1/(b/(a−1))+1/b，
可以直接分解成两个，省去了上述一些继续分解的步骤，可以优化一些时间。
 */

void recursion(int a, int b){
    if(a == 1){
        cout << 1 << "/" << b << endl;
        return;
    }
    if(b % a == 0){ //去掉公因子
        recursion(1, b / a);
        return;
    }
    if(b % (a - 1) == 0){ //整除a-1的情况
        cout << 1 << "/" << b / (a - 1) << "+";
        recursion(1, b);
        return;
    }
    cout << 1 << "/" << b / a + 1 << "+";
    recursion(a - b % a, b * (b / a + 1)); //根据公式更新分子分母送入递归
}

int main(){
    int numerator, denominator; //分别是分子分母
    char op; //除号
    while(cin >> numerator >> op >> denominator){
       recursion(numerator, denominator);
    }
}
