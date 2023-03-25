#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<stdio.h>

using namespace std;

/* 
非数字的字符替换成某个特定字符，例如‘.’，
再使用strtok()方法将其进行分隔，最后挑选出最长的数字子串。
 */


int main()
{
    char s[200];
    vector<string> num;
    while (cin>>s)
    {
        //替换
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i]<'0' || '9'<s[i]) s[i] = '.';
        }
        int maxm = 0;
        const char *p = ".";
        char *split;
        //使用strtok分割字符串
        split = strtok(s, p);
        while (split)
        {
            //判断子串的长度
            if (strlen(split)==maxm)
                num.push_back(string(split));
            if (strlen(split)>maxm)
            {
                maxm = strlen(split);
                num.clear();
                num.push_back(string(split));
            }
            split = strtok(NULL, p);
        }
        for (int i=0;i<num.size();i++)
            cout<<num[i];
        cout<<','<<maxm<<endl;
    }
    return 0;
}
