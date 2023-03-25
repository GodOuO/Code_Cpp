#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#if 0

从R依次中取出R<i>，对I进行处理，找到满足条件的I：
I整数对应的数字需要连续包含R<i>对应的数字。
比如R<i>为23，I为231，那么I包含了R<i>，条件满足 。

按R<i>从小到大的顺序:
(1)先输出R<i>；
(2)再输出满足条件的I的个数；
(3)然后输出满足条件的I在I序列中的位置索引(从0开始)；
(4)最后再输出I。

附加条件：
(1)R<i>需要从小到大排序。相同的R<i>只需要输出索引小的以及满足条件的I，索引大的需要过滤掉
(2)如果没有满足条件的I，对应的R<i>不用输出
(3)最后需要在输出序列的第一个整数位置记录后续整数序列的个数(
    不包含“个数”本身)


序列I：15, 123, 456, 786, 453, 46, 7, 5, 3, 665, 453456, 745, 456, 786, 453,
123
（第一个15表明后续有15个整数）
序列R：5, 6, 3, 6, 3, 0
（第一个5表明后续有5个整数）
ps:
6, 3, 6, 3, 0 -> 0, 3, 6 ->(没有0) 3, 6

输出：30, 3, 6, 0, 123, 3, 453, 7, 3, 9, 453456, 13, 453, 14, 123, 6, 7, 1,
456, 2, 786, 4, 46, 8, 665, 9, 453456, 11, 456, 12, 786
ps:
共计输出30个数字，
符合3的有6个，输出键值对<loc, value>,
符合6的有7个，输出键值对<loc, value>

/*
用有序哈希表map实现，
输入的 R序列 直接进入哈希表，会自动排序去重，后续遍历哈希表就可以了。
将数字转换成字符串，利用字符串的find函数查找是否出现过，
然后所有的待输入的信息我们可以添加到字符串末尾，
也可以在其前面添加数量信息及数字
 */

#endif


int main() {
    int Ilen, Rlen; //记录序列I和序列R的大小
    while (cin >> Ilen) {
        vector<int> I(Ilen);
        for (int i = 0; i < Ilen; i++)
            cin >> I[i]; //输入n个整数序列I
        cin >> Rlen; //整数序列R的长度
        map<int, int> R;
        for (int i = 0; i < Rlen;
                i++) { //哈希表记录序列R，直接去重加排序
            int t;
            cin >> t;
            R[t] = 1;
        }
        int total = 0;
        string ans = ""; //以字符串的形式输出
        for (auto iter = R.begin(); iter != R.end(); iter++) {
            int count = 0;
            string temp = ""; //记录这一轮的R[i]有多少匹配的
            for (int i = 0; i < Ilen; i++) {
                if (to_string(I[i]).find(to_string(iter->first)) !=
                        string::npos) { //找到出现数字
                    count++; //数量加1
                    temp += to_string(i) + ' ' + to_string(I[i]) + ' '; //添加索引和该数字
                }
            }
            if (count !=
                    0) { //如果有出现连续的R[i]，添加头部的R[i]及后面有多少个数中出现了
                ans += to_string(iter->first) + ' ' + to_string(count) + ' ' + temp;
                total += (2 * count + 2); //补充后面增加了多少数
            }
        }
        ans = to_string(total) + ' ' + ans; //添加总个数
        cout << ans << endl;
    }
    return 0;
}