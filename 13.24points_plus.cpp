#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

#if 0 
给出四张扑克牌的牌面，将其当成数字，询问能否通过加减乘除得到24，除法是整除，给出算术式
牌面2到10分别对应数字2到10，然后J、Q、K、A分别代表11、12、13、1
遇到大小王joker、JOKER要输出ERROR
运算中数字的顺序不定，但是不能包含括号
如有多个解输出一个即可，如无解输出NONE

/* 
用两个哈希表做到字符串到数字的映射，
通过哈希表可以将牌面字符串转换成数字，再将数字转换成牌面字符串。

对于输入的字符串先检查有无大小王，没有再转成数字，然后计算。
计算的时候先排成最小的递增序，然后使用next_permutation枚举这四个数字的所有可能的顺序情况，
对于每个顺序再枚举中间3个运算符的所有情况，然后将数字数组和运算符数组依次进行计算，
如果结果等于24，则可以输出，否则继续找。我们也要准备一个bool型flag用于记录是否找到输出了，
每个控制循环的地方都要加flag控制，避免输出之后还在继续找导致输出多个解。
 */
#endif

unordered_map<string, int> CardtoNum = {{"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, 
{"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}}; //输入的字符映射到数字
unordered_map<int, string> NumtoCard = {{1, "A"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, 
{7, "7"}, {8, "8"}, {9, "9"}, {10, "10"}, {11, "J"}, {12, "Q"}, {13, "K"}}; //返回的数字映射到字符
const vector<char> Op = {'+', '-', '*', '/'};
 
int cal(int a, int b, int op){ //运算
    if(op == 0) 
        return a + b;
    else if (op == 1) 
        return a - b;
    else if (op == 2) 
        return a * b;
    else
        return a / b;
}

bool cal24(vector<int>& a, vector<int>& op){ //这个数字顺序和符号顺序下能够达到24
    vector<int> b(a);
    for(int i = 0; i < 3; i++)
        b[i + 1] = cal(b[i], b[i + 1], op[i]);
    if (b[3] == 24) 
        return true;
    else 
        return false;
}
bool check(vector<int>& nums){
    bool flag = false;
    vector<int> op(4);
    sort(nums.begin(), nums.end());
    do {
        for(int i = 0; i < 4 && !flag; i++){ //枚举三个符号的所有情况
            op[0] = i;
            for(int j = 0; j < 4 && !flag; j++) {
                op[1] = j;
                for(int k = 0; k < 4 && !flag; k++) {
                    op[2] = k;
                    if (cal24(nums, op)) { //符合条件就输出
                        for(int m = 0; m < 3; m++)
                            cout << NumtoCard[nums[m]] << Op[op[m]];
                        cout <<  NumtoCard[nums[3]]  << endl;
                        flag = true; //找到了，准备跳出所有循环
                    }
                }
            }
        }
    } while(next_permutation(nums.begin(), nums.end()) && !flag); //枚举所有的数字顺序
    return flag;
}
 
int main() {
    vector<string> s(4);
    cin >> s[0] >> s[1] >> s[2] >> s[3]; //输入4个字符串
    vector<int> nums(4);
    for(int i = 0; i < 4; i++) { 
        if(s[i] == "joker" || s[i] == "JOKER"){ //遇到大小王
            cout << "ERROR" << endl;
            return 0;
        }
        nums[i] = CardtoNum[s[i]]; //字符串转数字
    }
    if(!check(nums)) //找不到
        cout << "NONE" << endl;
    return 0;
}
