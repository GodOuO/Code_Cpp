#include<iostream>
#include<vector>
using namespace std;

/* 用递归的方式搜索，每次完整4个数字送入递归函数，
使用其中一个数字添加运算符进行运算，就将数组中去掉这个数字，然后继续递归，
最后判断数组为空时结果是否等于24. 

需要注意，因为要回溯，所以不能直接去掉原数组中的数字，而是拷贝一份备份来去除。 */


bool check(vector<double> nums, double result){ //递归检查能否组成24
    if(nums.empty()) //数组为空，判断等不等于24
        return result == 24;
    for(int i = 0; i < nums.size(); i++){ //遍历剩下的数字
        vector<double> rest(nums);
        rest.erase(rest.begin() + i); //删去使用的数字
        if(check(rest, result + nums[i]) //分别 进行加减乘除4种运算
          || check(rest, result - nums[i])
          || check(rest, result * nums[i])
          || check(rest, result / nums[i]))
            return true;
    }
    return false;
}

int main(){
    vector<double> nums(4); 
    while(cin >> nums[0] >> nums[1] >> nums[2] >> nums[3]){ //输入4个数字
        if(check(nums, 0))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
