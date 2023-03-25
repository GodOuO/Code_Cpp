#include <iostream>
#include<cmath>

using namespace std;
/* 
初始化左右区间 l , r 。
        如果大于给定数，则 r = mid ；
        否则 l = mid 。

        最后，l 即为答案。 
*/



int main(){
    
    double x;
    cin >> x;
    
    double l=-20,r=20,mid;
    while(fabs(r-l)>0.001){//确保精度，保留一位小数
        mid=(l+r)/2;
        if(mid*mid*mid>=x)//如果大于给定数，则r=mid
            r=mid;
        else//否则l=mid
            l=mid;
    }
    printf("%.1f\n",l);
    return 0;
}