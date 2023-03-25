#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#if 0
自左向右求出最长递增子序列的最优值dp数组，
自右向左求出最长递减子序列的最优值dp数组，
两者对位相加-1，
其中的最大值，就是整个合唱队留在场上的人数的最大值，因此也就是出列的最小值。 
#endif

int main(){
    int n, tmp;
    int i, j;
    vector<int> heights;
    // 输入
    while(cin >> n){
        for(i = 0; i < n; i++){
            cin >> tmp;
            heights.push_back(tmp);
        }
        // 设置两个dp数组
        vector<int> dp_h(n, 1), dp_t(n, 1);
        // 正序遍历
        for(i = 0; i < n; i++){
            for(j = 0; j < i; j++){
                if(heights[i] > heights[j]){
                    dp_h[i] = max(dp_h[i], dp_h[j] + 1);
                }
            }
        }
        // 逆序遍历
        for(i = n-1; i >= 0; i--){
            for(j = n-1; j > i; j--){
                if(heights[i] > heights[j]){
                    dp_t[i] = max(dp_t[i], dp_t[j] + 1);
                }
            }
        }
        // 求和得到最长先增后减子序列的长度
        int maxNum = 0;
        for(i = 0; i < n; i++){
            if(dp_t[i] + dp_h[i] - 1 > maxNum)
                maxNum = dp_t[i] + dp_h[i] - 1;
        }
        // 输出
        cout << n - maxNum << endl;
        // 清除vector，以供下一轮使用
        heights.clear();
    }
    return 0;
}
