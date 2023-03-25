#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/* 
若两个字符相等，即str1[i-1] == str2[j-1]，
则在这一个位置的编辑距离和上一个字符相同，因此对应的数组dp[i][j]=dp[i-1][j-1]；

若两个字符不相等，可删除str1[i-1]这个字符，则dp[i][j] = 1 + dp[i-1][j]；

删除str2[j-1]这个字符，则dp[i][j] = 1 + dp[i][j-1]；

修改str1[i-1]使它与str2[i-1]相等，则dp[i][j] = 1 + dp[i-1][j-1]。
 */

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        for (int i = 1; i <= str2.size(); i++) dp[0][i] = i;//str1从0个字符变成str2的i个字符需要i个插入操作
        for (int i = 1; i <= str1.size(); i++) dp[i][0] = i;//str1从i个字符变成str2的0个字符也需要i个删除操作
        for(int i=1;i<=str1.size();i++){
            for (int j = 1; j <= str2.size(); j++) {
                int op1 = dp[i-1][j] + 1;//删除字符str1[i-1]
                int op2 = dp[i][j-1] + 1;//删除字符str2[j-1]
                int op3 = dp[i-1][j-1];//替换操作
                if(str1[i-1] != str2[j-1]){
                    op3++;
                }
                dp[i][j] = min(min(op1, op2), op3);//替换操作和删除操作取最小
            }
        }
        cout << dp[str1.size()][str2.size()] << endl;
    }
}
