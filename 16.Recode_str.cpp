#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#if 0
第一步：将输入的两个字符串str1和str2进行前后合并。
如给定字符串 "dec" 和字符串 "fab" ， 合并后生成的字符串为
"decfab"

第二步：对合并后的字符串进行排序，要求为：
下标为奇数的字符和下标为偶数的字符分别从小到大排序。
这里的下标的意思是字符在字符串中的位置。注意排序后在新串中仍需要保持原来的奇偶性。
例如刚刚得到的字符串“decfab”，
分别对下标为偶数的字符'd'、'c'、'a'和下标为奇数的字符'e'、'f'、'b'进行排序
（生成 'a'、'c'、'd' 和 'b' 、'e' 、'f'），
再依次分别放回原串中的偶数位和奇数位，新字符串变为“abcedf”

第三步：对排序后的字符串中的'0'~'9'、'A'~'F'和'a'~'f'字符，需要进行转换操作。
转换规则如下：
对以上需要进行转换的字符所代表的十六进制用二进制表示并倒序，然后再转换成对应的十六进制大写字符
（注：字符 a~f 的十六进制对应十进制的10~15，大写同理）。
如字符 '4'，其二进制为 0100 ，则翻转后为 0010 ，也就是 2
。转换后的字符为 '2'。
如字符 ‘7’，其二进制为 0111 ，则翻转后为 1110
，对应的十进制是14，转换为十六进制的大写字母为 'E'。
如字符 'C'，代表的十进制是 12 ，其二进制为 1100
，则翻转后为 0011，也就是3。转换后的字符是 '3'。
根据这个转换规则，由第二步生成的字符串 “abcedf”
转换后会生成字符串 "5D37BF"。

/*
1.合并后的字符串按照奇偶位拆分后分别排序，
    排序后原合并字符串中的奇数位在新拼接的字符串中也只能是奇数位，
    原合并字符串中的偶数位在新拼接的字符串中也只能是偶数位；
2.反转的时候只处理十六进制样式的字符，其他字符保持不变；
 */
#endif


string merge(const string s1, const string s2) {
    string ans = s1 + s2;
    int size = ans.size();
    // 按奇偶拆分字符串，分别排序
    string even, odd;
    for (int i = 0; i < size; ++i) {
        i & 1 ? odd.push_back(ans[i]) : even.push_back(ans[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    ans.clear();
    for (int i = 0, p = 0, q = 0; i < size; ++i) {
        // 合并时按照原来的奇偶顺序排列
        i & 1 ? ans.push_back(odd[p++]) : ans.push_back(even[q++]);
    }
    return ans;
}

int to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    else if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

char reverse_bits(int val) {
    unsigned char m = 0x5;
    val = val >> 1 & m | (val & m) << 1;
    val = val >> 2 | val << 2;
    val %= 16;
    return val < 10 ? val + '0' : val - 10 + 'A';
}

int main() {
    string word1, word2;
    while (cin >> word1 >> word2) {
        string ans;
        for (const auto& c : merge(word1, word2)) {
            int r = to_int(c);
            // 只处理十六进制字符，其他直接添加
            if (r >= 0 && r <= 15)
                ans.push_back(reverse_bits(r));
            else ans.push_back(c);
        }
        cout << ans << endl;
    }
    return 0;
}