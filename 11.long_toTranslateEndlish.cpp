#include<iostream>
using namespace std;

/*
数字在英语读法中三位数字看成一整体，后面再加一个计数单位。而相同部分的英语读法相同，
由此我们可以想到利用递归将大数字分为几个三位的数字，
再拼接在一起即可。
 */


int n;
string a[] = {"a0", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}; //20以内的单词表
string b[] = {"b0", "b1", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}; //整十单词表
const string hun = "hundred";
const string tho = "thousand";
const string mil = "million";
const string bil = "billion"; //连接词表

string engn(int n) {
    if (n < 20)
        return a[n];//若n小于20直接从表中输出
    else if (n < 100) {
        if (n % 10 == 0) //若n能被10整除
            return b[n / 10]; //从整十表中输出
        else
            return b[n / 10] + " " + engn(n % 10); //分别计算十位和个位
    } else if (n < 1000) {
        if (n % 100 == 0)
            return a[n / 100] + " " + hun; //同理，若整百直接输出数字加百
        else
            return engn(n / 100) + " " + hun + " and " + engn(n %
                    100); //分别计算百位，十位和个位
    } else if (n < 1000000) { //对于一百万以下的数字同理处理
        if (n % 1000 == 0)
            return engn(n / 1000) + " " + tho;
        else
            return engn(n / 1000) + " " + tho + " " + engn(n % 1000);
    } else {
        if (n % 1000000 == 0)
            return engn(n / 1000000) + " " + mil;
        else
            return engn(n / 1000000)/*百万位上*/ + " " + mil + " " + engn(
                       n / 1000 % 1000)/*百万位到千位*/ + " " + tho + " " + engn(
                       n % 1000); /*千位到个位*/
    }
    return "err";
}

int main() {
    while (cin >> n) {
        string ans = engn(n);
        cout << ans << endl;
    }
    return 0;
}