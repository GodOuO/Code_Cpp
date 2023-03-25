#include<iostream>
#include<vector>
using namespace std;

/* 
dp与len，len起着方法一dp数组的作用，
dp[i]记录以 i结尾的最大递增字符字串，
对于每次循环，从后找到比它大的数字，加入dp，
若出现第一个不必dp中最后一位数大的，则需要使用二分查找，
对剩下部分找第一个大于dp中最后一位的，再将其加入。
 */

int biSearch(int x, vector<int>& dp){  //二分查找函数
    int left = 0, right = dp.size(), mid;
    while(left <= right){
        mid = (right + left) / 2;
        if(dp[mid] >= x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
int lis(vector<int>& arr) {
    vector<int> len; //设置数组长度大小的动态规划辅助数组
    vector<int> dp;//用于二分划分的辅助数组
    dp.push_back(arr[0]);
    len.push_back(1);
    for(int i = 1; i < arr.size(); i++){
         if(arr[i] > dp[dp.size() - 1]) { 
             dp.push_back(arr[i]);
             len.push_back(dp.size());
         }
         else{
             int t = biSearch(arr[i], dp); //二分查找，找到第一个大于arr[i]的dp位置
             dp[t] = arr[i];
             len.push_back(t + 1);
        }
    }
    return dp.size();
}

int main(){
    int n;
    while(cin >> n){
        vector<int> arr(n);
        for(int i = 0; i < n; i++) //输入
            cin >> arr[i];
        cout << lis(arr) << endl; //计算最长递增子序列长度
    }
    return 0;
}
