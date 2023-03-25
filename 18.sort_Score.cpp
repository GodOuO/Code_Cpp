#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#if 0
/*
stable_sort()和sort()的区别:

bool less_len(const string &str1, const string &str2){
        return str1.length() < str2.length();
}
    //"apples" 和 "winter" 就是相等的，如果在"apples" 出现在"winter"前面，
    用带stable的函数排序后，他们的次序一定不变，
    如果你使用的是不带"stable"的函数排序，"winter"有可能在"apples"的前面。
 */
#endif

struct user_scores {
    string name;
    int score;
};

bool score_compare1(user_scores a,
                    user_scores b) { //按成绩从低到高排序
    return a.score < b.score;
}

bool score_compare2(user_scores a,
                    user_scores b) { //按成绩从高到低排序
    return a.score > b.score;
}

int main() {
    int n, sort_way;
    while (cin >> n >> sort_way) {
        vector<user_scores> input_scores(n);
        for (int i = 0; i < n; i++) {
            cin >> input_scores[i].name >> input_scores[i].score;
        }
        if (sort_way == 1)
            stable_sort(input_scores.begin(), input_scores.end(), score_compare1);
        else if (sort_way == 0)
            stable_sort(input_scores.begin(), input_scores.end(), score_compare2);
        for (int i = 0; i < n; i++) {
            cout << input_scores[i].name << " " << input_scores[i].score << endl;
        }
    }
    return 0;
}