#include<iostream>
#include<string>
using namespace std;
/* 
滑动窗口的思想，
首先用一个长度为n的窗口覆盖字符串前n部分子串，
统计这里的CG数量，并暂时作为最大值。
然后窗口右移，
如果左边出去的是CG那么窗口内的CG数量减少一个，
如果右边进来的是CG那么窗口内的CG数量增加一个，
每次滑动都统计窗口内的CG数量，与临时最大值比较，记录下最大窗口的起始下标。

窗口右端抵达字符串末尾时结束，根据下标用substr函数输出字符串含CG最高的子串。 
*/

int main(){
    string s;
    int inputLen;
    while(cin >> s >> inputLen){
        int len = s.length();
        int resindex = 0, max = 0;
        int count = 0;
        for(int i = 0; i < inputLen; i++) //录入最前面的窗口
            if(s[i] == 'C' || s[i] == 'G')
                count++;
        max = count; //录下第一个窗口的CG数量作为最大
        int left = 1, right = inputLen; //从录入窗口的左右点右移一位开始
        while(right < len){ //直到右窗口结束
            if(s[left - 1] == 'C' || s[left - 1] == 'G') //窗口左边出去的是CG
                count--;
            if(s[right] == 'C' || s[right] == 'G') //窗口右边进来的是CG
                count++;
            if(count > max){ //更新，取最大值
                max = count;
                resindex = left;
            }
            left++;
            right++;
        }
        cout << s.substr(resindex, inputLen) << endl; //根据下标和n输出
    }
    return 0;
}
