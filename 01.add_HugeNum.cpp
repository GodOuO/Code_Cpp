#include<iostream>
using namespace std;

/*
自己实现十进制按位加
两个整数位数不一致，短的在前面补0
注意进位
*/

void biggerstr(string& a, string& b) {
    int m = a.length();
    int n = b.length();
    if (m < n) {
        string tmp = a;
        a = b;
        b = tmp;
    }
}
int main() {
    string input1;
    string input2;
    while (cin >> input1 >> input2) {
        biggerstr(input1, input2);//保证str1是更长的那个
        int m = input1.size();
        int n = input2.size();
        int jin = 0; //进位标志
        string ans ;
        for (int i = 0; i < (m - n);
                ++i)input2.insert(input2.begin(), '0'); //短的前面填0
        for (int i = m - 1; i >= 0; --i) {     //简单的十进制加法规则
            int tmp = input1[i] - '0' + input2[i] - '0' + jin;
            if (tmp >= 10) {
                jin = 1;
                tmp %= 10;
            } else {
                jin = 0;
            }
            ans.insert(ans.begin(), tmp + '0');
        }
        if (jin)ans.insert(ans.begin(), '1'); //注意进位
        cout << ans << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")