#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    stringstream ss;
    ss<<s;
    int a,b,c,d;
    a=b=c=d=-1;
    char i,j,k;
    ss>>a>>i>>b>>j>>c>>k>>d;
    int flag=0;
    if(a>=0&&a<=255&&i=='.'&&b>=0&&b<=255&&j=='.'&&c>=0&&c<=255&&k=='.'&&d>=0&&d<=255)
        flag=1;
    int count=0;
    for(int i=0;i<s.size()-1;i++){
        if((s[0]=='0'||s[0]=='+')&&s[1]>='1'&&s[1]<='9'){
            flag=0;
            break;
        }
        if(s[i]=='.'){
            if((s[i+1]=='0'||s[i+1]=='+')&&s[i+2]>='1'&&s[i+2]<='9'){
                flag=0;
                break;
            }
            count++;
        }
            
    }
    if(count!=3) flag=0;
    if(flag==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
