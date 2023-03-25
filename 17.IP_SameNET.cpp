#include<iostream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;

#if 0

利用子网掩码可以判断两台主机是否在同一子网中。
若两台主机的IP地址分别与它们的子网掩码进行逻辑“与”运算（按位与/AND）后的结果相同，
则说明这两台主机在同一子网中。

示例：
I P 地址　 192.168.0.1
子网掩码　 255.255.255.0

转化为二进制进行运算：
I P 地址　  11000000.10101000.00000000.00000001
子网掩码　11111111.11111111.11111111.00000000
AND运算   11000000.10101000.00000000.00000000

转化为十进制后为：
192.168.0.0

I P 地址　 192.168.0.254
子网掩码　 255.255.255.0
转化为二进制进行运算：

I P 地址　11000000.10101000.00000000.11111110
子网掩码  11111111.11111111.11111111.00000000
AND运算  11000000.10101000.00000000.00000000

转化为十进制后为：
192.168.0.0

通过以上对两台计算机IP地址与子网掩码的AND运算后，我们可以看到它运算结果是一样的。
均为192.168.0.0，所以这二台计算机可视为是同一子网络。

输入一个子网掩码以及两个ip地址，判断这两个ip地址是否是一个子网络。
若IP地址或子网掩码格式非法则输出1，若IP1与IP2属于同一子网络输出0，
若IP1与IP2不属于同一子网络输出2。

/* 
IP地址的字符串格式，我们可以使用字符串流输入输出，来获取数字，
而不需要遍历字符串然后拆分，我们只需要在流输出的时候用一个char型变量接收那个点即可。
然后遍历得到的每个数字，依次检查是否合法范围内，再将其转化成长整数。

这里流输出就默认了最后一个数后面没有其他字符了，正好题目中也没有这种案例。
对于掩码我们也可以用正则表达式直接匹配，而不用移位找有没有01混在一起。
 */
#endif



bool isLegal(string s, unsigned int& binum){ //检查掩码或者IP地址的数字部分是否合法，并将合法的转换为长整数
    int point = 0; //统计点的个数
    unsigned int num[4] = {0, 0, 0, 0}; //记录四个数字
    stringstream ss;
    ss << s;
    char c;
    ss >> num[0] >> c >> num[1] >> c >> num[2] >> c >> num[3]; //直接用字符串流输出数字中间的点用字符变量接受
    for(int i = 0; i < 4; i++){ //检查数字是否合法
        if(num[i] < 0 || num[i] > 255)
            return false;
    }
    binum = num[0] << 24 | num[1] << 16 | num[2] << 8 | num[3]; //位运算组装
    return true;
}

bool isMask(string mask){ //单独检查掩码是否是先1后0
    if(mask == "0.0.0.0" || mask == "255.255.255.255") //全0全1不合法
        return false;
    string re = "^((0|128|192|224|240|248|252|254)\.0\.0\.0|255\.(0|128|192|224|240|248|252|254)\.0\.0|255\.255\.(0|128|192|224|240|248|252|254)\.0|255\.255\.255\.(0|128|192|224|240|248|252|254|255))$";
    regex pattern(re);
    if(regex_match(mask, pattern)) //正则表达式匹配正确的掩码
        return true;
    else
        return false;
}
int main(){
    string mask, ip1, ip2;
    while(cin >> mask >> ip1 >> ip2){
        unsigned int bi_mask = 0;
        unsigned int bi_ip1 = 0;
        unsigned int bi_ip2 = 0;
        //判断是否合法
        if(!isLegal(mask, bi_mask) || !isLegal(ip1, bi_ip1) || !isLegal(ip2, bi_ip2) || !isMask(mask)){
            cout << 1 << endl;
            continue;
        }
        if((bi_mask & bi_ip1) == (bi_mask & bi_ip2)) //比较是否同一个子网
            cout << 0 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
