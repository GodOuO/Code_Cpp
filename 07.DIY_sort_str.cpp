#include<iostream>
#include<string>
using namespace std;

#if 0
将输入多组测试字符串中的字符按如下规则排序后输出：
英文字母从 A 到 Z 排列，不区分大小写
同一个英文字母的大小写同时存在时，按照输入顺序排列
非英文字母的其它字符保持原来的位置

/* 
冒泡排序的思想，对字母之间交换顺序即可。

最多有字符串长度n轮交换，是最外层循环，
内层循环从从0开始，每次找到相邻的两个字母，比较大小，

如果位置相反则交换，一直到最后，像冒泡排序一样，
每次可以保证最后的那个元素顺序是正确的，依次往前确认最后的元素，直到第一个就排好了。

因为我们每次找的时候相邻的字母，跳过了其他字符，因此其他字符的位置不变。

比较字母的大小，我们采用字符分别减去大小写各自的A/a，
这样比较它们在字母表中的索引，即可比较不区分大小写的大小。
 */
#endif


bool ischar(char c){ //判断是否是字符
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int toint(char c){ //将大小写字母转为同样的数字起跑线
    return (c >= 'a' && c <= 'z') ? c - 'a' : c - 'A';
}
int main(){
    string s;
    while(getline(cin, s)){
        int next;
        for(int i = s.length() - 1; i > 0; i--){
            for(int j = 0; j < i; j++){
                if(ischar(s[j])){ //首先要是字母才可以交换位置
                    next = j + 1;
                    while(next <= i && !ischar(s[next]))
                        next++; //找到下一个字母
                    if(ischar(s[next]) && toint(s[j]) > toint(s[next])){
                        swap(s[j], s[next]); //交换
                    }
                }
            }
        }
        cout << s <<endl;
    }
    return 0;
}
