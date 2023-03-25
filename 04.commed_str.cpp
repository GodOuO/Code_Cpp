#include<iostream>
#include<string>
#include<vector>
using namespace std;

#if 0
输入一行命令，命令参数之间按照空格分开，需输出命令单独的各个参数
引号包含的参数中间有空格，不用解析为多个参数，只解析引号之间的
引号不会嵌套
输出不能包含引号
参数不定长
进阶要求：时间复杂度O(n)，空间复杂度O(n)

/* 
采取字符串截取的方法，就不使用临时字符串变量了，但还是需要记录是否在引号中。

首先，如果遇到引号，
要判断是否在引号中，如果不在，则是第一个引号，
如果在则是第二个引号，

第二个引号就将这串字符串开始到引号前的子串加入数组，
然后新的子串开始位置从引号后一个位置开始。

如果遇到空格且不在引号中的情况，
需要将子串截取加入数组，但是要提前判断是否是空子串（引号和空格相连的时候就会出现空子串）。

最后需要判断是否是字符串最后一个位置，要将最后一个参数字符串加入。
 */
#endif


int main(){
    string input;
    while(getline(cin, input)){
        vector<string> ans;
        int p = 0;
        bool flag = false; //记录是否进入引号中
        for(int i = 0; i < input.length(); i++){
            if(input[i] == '\"'){ //遇到引号
                if(!flag) //第一个引号
                    flag = true;
                else{ //第二个引号
                    flag = false;
                    ans.push_back(input.substr(p, i - p)); //截取字符串加入
                }
                p = i + 1;
            } else if(input[i] == ' ' && !flag){ //遇到引号外的空格
                if(i != p)  //非空字符串
                    ans.push_back(input.substr(p, i - p)); //截取字符串加入
                p = i + 1;
            } else if(i == input.length() - 1) //最后一个参数字符串
                ans.push_back(input.substr(p, i - p + 1));
        }
        cout << ans.size() << endl; //输出参数个数
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << endl;
    }
    return 0;
}
