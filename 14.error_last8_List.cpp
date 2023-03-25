#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#if 0
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号，及相同错误出现的次数
记录最多8条错误记录，循环记录，最后只用输出最后出现的八条错误记录
对相同的错误记录只记录一条，但是错误计数增加，最后一个斜杠后面的带后缀名的部分
（保留最后16位）和行号完全匹配的记录才做算是”相同“的错误记录
输入的文件可能带路径，记录文件名称不能带路径，
超过16个字符的文件名称，只记录文件的最后有效16个字符
循环记录时，只以第一次出现的顺序为准，后面重复的不会更新它的出现时间，仍以第一次为准。
如果个超过8条的错误中第一条出现了它，最后一条也是它，不应该输出，以它是第一条出现的为准

/* 
哈希表来代替上述暴力查找，省去不少时间。
同时，方法一中嵌套的pair过多，我们可以将输入的行号也看成是字符串，
将文件名+空间+行号，这样组成一个新的字符串看成哈希表的key值，
而这个key值出现的次数即为哈希表的value值。
这样我们每次只需要检查哈希表中没有出现过这一串key值就可以，
添加新的key也要将其纳入res数组中，同时循环储存，最后输出的时候也是查哈希表找到出现次数。
 */
#endif

string getfilename(string filepath){ //题取文件名
    string res = "";
    for(int i = filepath.length() - 1; i >= 0; i--){ //逆向查找到第一个斜杠
        if(filepath[i] ==  '\\')
            break;
        res = filepath[i] + res; //将字符加到字符串前面
    }
    if(res.length() > 16) //长度大于16的时候，截取后16位
        res = res.substr(res.length() - 16, 16);
    return  res;
}

int main(){
    string filepath, num; //把路径和行号都当成字符串
    unordered_map<string, int> mp;
    vector<string> res(8, "");
    int index = 0; //记录下标
    while(cin >> filepath >> num){
        string file = getfilename(filepath);
        string key = file + " " + num;
        if(mp.find(key) == mp.end()){ //没有出现过，需要添加到哈希表中
            mp[key] = 1;
            res[index] = key;
            index = (index + 1) % 8; //循环记录
        }else
            mp[key]++; //遇到相同的错误，计数增加
    }
    for(int i = 0; i < 8; i++){
        if(res[index] != "") //只输出有记录的，防止不足8个
            cout << res[index] << " " << mp[res[index]] << endl;
        index = (index + 1) % 8;
    }
    return 0;
}
