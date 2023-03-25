#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

#if 0
以“最短唯一匹配原则”匹配命令：

若只输入一字串，则只匹配一个关键字的命令行。
若只输入一字串，但本条命令有两个关键字，则匹配失败。
若输入两字串，则先匹配第一关键字，如果有匹配但不唯一，继续匹配第二关键字，如果仍不唯一，匹配失败。
若输入两字串，则先匹配第一关键字，如果有匹配但不唯一，继续匹配第二关键字，如果唯一，匹配成功。
若输入两字串，第一关键字匹配成功，则匹配第二关键字，若无匹配，失败。
若匹配失败，打印“unknown command”

/* 
直接把他们这几个字符串存到一个vector里面，
然后我们每次分别比较前面一个和后面一个，
最后判断有几个对应上，然后输出答案
 */
#endif


string s, s1 = "", s2 = "";
// s为输入的字符串
vector<pair<string, string>> a;
unordered_map<string, string> mp;
// a为我们的前后字符串
// mp为我们对应的输出的答案

void init() {
    a.push_back({"reset", "board"});
    a.push_back({"board", "add"});
    a.push_back({"board", "delete"});
    a.push_back({"reboot", "backplane"});
    a.push_back({"backplane", "abort"});
    mp["reset board"] = "board fault";
    mp["board add"] = "where to add";
    mp["board delete"] = "no board at all";
    mp["reboot backplane"] = "impossible";
    mp["backplane abort"] = "install first";
}
// 初始化操作，把我们的前后的和我们的对应的输出的答案存储起来

void solve() {
    bool flag = false;
    for (auto &it : s) {
        if (it == ' ') {
            flag = true;
            continue;
        }
        flag ? s2 += it : s1 += it;
    }
    // 这个是判断什么时候存入s1，什么时候存入s2
    if (s2 == "") {
        string tmp = "reset";
        if (tmp.find(s1) == 0) {
            // 这个是判断我们是不是第一个匹配的位置是0
            cout << "reset what\n";
            return;
        }
        cout << "unknown command\n";
        return;
    }
    // 上面是对单指令进行的一个操作
    string tmp = "";
    int cnt = 0;
    for (auto &[u, v] : a) {
        if (u.find(s1) == 0) {
            if (v.find(s2) == 0) {
                tmp = u + " " + v;
                cnt++;
            }
        }
        // 如果两个都是匹配了成功，那么我们存储下来，然后次数+1
    }
    if (cnt == 1) {
        cout << mp[tmp] << "\n";
        return;
    }
    // 如果次数是一次直接输出，否则输出不知道
    cout << "unknown command\n";
    return;
}

int main() {
    init();
    while(getline(cin, s)) {
        // 整行输入
        s1 = s2 = "";
        solve();
    }
}
