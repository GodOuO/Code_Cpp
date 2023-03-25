#include<iostream>
#include<string>

using namespace std;
#if 0
一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4-joker JOKER。
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
基本规则：
（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

/* 
如果任意一方有王炸，直接输出王炸即可。
若没有王炸，且两副手牌长度相同，如果有大王，则输出大王。
否则用Value函数获得第一张牌面的值，比较两副牌第一个牌面的大小。
若没有王炸，且两幅手牌长度不同，如果有一方是炸弹，则输出炸弹，否则无法比较，输出ERROR。
 */

#endif


int getLen(string s)//得到出牌的张数
{
    int len = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') len++;
    }
    return len;
}

int Value(string s)//比较第一个牌面的大小
{
    int res;
    if (s[0] == '1') res = 10;
    else if (s[0] == '3') res = 3;
    else if (s[0] == '4') res = 4;
    else if (s[0] == '5') res = 5;
    else if (s[0] == '6') res = 6;
    else if (s[0] == '7') res = 7;
    else if (s[0] == '8') res = 8;
    else if (s[0] == '9') res = 9;
    else if (s[0] == 'J') res = 11;
    else if (s[0] == 'Q') res = 12;
    else if (s[0] == 'K') res = 13;
    else if (s[0] == 'A') res = 14;
    else if (s[0] == '2') res = 15;
    return res;
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        string s1 = str.substr(0, str.find('-'));//第一手牌
        string s2 = str.substr(str.find('-') + 1);//第二手牌
        int n1 = getLen(s1);//第一手牌的个数
        int n2 = getLen(s2);//第二手牌的个数
        string Joker = "joker JOKER";//王炸！

        if (s1 == Joker || s2 == Joker){//如果有一手牌是王炸则王炸最大
            cout << Joker << endl;
        }else if(n1 == n2){//两手牌张数相同时
            if(s1 == "JOKER" || s2 == "JOKER"){//大王最大
                cout<<"JOKER"<<endl;
                continue;
            }
            int v1 = Value(s1);
            int v2 = Value(s2);
            if(v1 > v2){//比较第一张牌的大小，输出更大的那个
                cout<<s1<<endl;
            }else{
                cout<<s2<<endl;
            }
        }else if(n1 == 4) cout<<s1<<endl;//若两手牌张数不同，炸弹最大
        else if(n2 == 4) cout<<s2<<endl;
        else cout<<"ERROR"<<endl;//手牌张数不同，也没有炸弹则无法比较
    }

    return 0;
}
