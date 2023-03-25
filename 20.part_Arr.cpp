#include<iostream>
#include<vector>
using namespace std;

#if 0
输入int型数组，询问该数组能否分成两组，
使得两组中各元素加起来的和相等，
并且，所有5的倍数必须在其中一个组中，
所有3的倍数在另一个组中（不包括5的倍数），
不是5的倍数也不是3的倍数能放在任意一组，

可以将数组分为空数组，能满足以上条件，输出true；不满足时输出false。

/* 
我们将5的倍数的数累加（记为第一组），3的倍数的数累加（记为第二组），剩余的数加入数组中。然后我们可以递归处理剩余的数。

对于剩余的数，每次我们可以选择将其加入第一组或者是第二组，
加入第一组我们可以记为加，
加入第二组我们可以记为减，
直到递归到最后我们对数组剩余中这些数的累加减和等于最初5的倍数和3的倍数的和他们的差的绝对值，
说明剩余的数是可以填补这个空缺的。
 */

#endif


bool judge(int i, vector<int>& arr, int sum1, int sum2){ //剩余的数组中组合出等于3和5和之差的
    if(i == arr.size())
        return abs(sum1) == sum2;
    else //加放一边，减放另一边
        return judge(i + 1, arr, sum1 + arr[i], sum2) || judge(i + 1, arr, sum1 - arr[i], sum2);
}

int main(){
    int inputLen;
    while(cin >> inputLen){
        vector<int> arr;
        int sum3 = 0;
        int sum5 = 0;
        int rest = 0;
        for(int i = 0; i < inputLen; i++){ 
            int x;
            cin >> x;
            if(x % 5 == 0) //先求一个组的和
                sum5 += x;
            else if(x % 3 == 0) //再求另一个组的和
                sum3 += x;
            else{
                arr.push_back(x); //剩余的加入数组并求和
            }
        }
        if(judge(0, arr, 0, abs(sum5 - sum3)))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
