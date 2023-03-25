#include <iostream>
#include <string>
using namespace std;

/* 
当歌曲数小于等于4时：
特殊向上翻页，移动光标到最后一首歌；
特殊向上翻页，移动光标到第一首歌；
一般向上翻页，光标向上移动一格；
一般向下翻页，光标向下移动一格；

当歌曲数大于4时：
特殊向上翻页，光标移动到最后一首歌，最后一页第一首歌为n-3；
特殊向下翻页，光标移动到第一首歌，第一页第一首歌为1；
一般向上翻页，光标向上移一格，当前页第一首歌和光标位置相同；
一般向下翻页，光标向下移一格，当前页第一首歌位置也向下移一格； 
*/


int main(){
    int inputNum;
    string com;
    while(cin >> inputNum >> com){
        int num = 1;
        int first = 1;      // first：当前屏幕显示页的第一首歌曲的编号
        // 歌曲总数不超过4时，不需翻页
        if(inputNum <= 4) {
            for(int i = 0; i < com.size(); i++){
                // 特殊向上翻页
                if(num == 1 && com[i] == 'U'){
                    num = inputNum; 
                // 特殊向下翻页
                }else if(num == inputNum && com[i] == 'D'){
                    num = 1;
                }else if(com[i] == 'U'){
                    num--;
                }else{
                    num++; 
                }
            }
            for(int i = 1; i <= inputNum - 1; i++){//输出当前页
                cout << i << ' ';
            }
            cout << inputNum << endl << num << endl;
        }else{// 歌曲总数大于4时，需要翻页
            for(int i = 0; i < com.size(); i++){
                // 特殊向上翻页
                if(num == 1 && com[i] == 'U') {
                    first = inputNum-3;
                    num = inputNum;
                }else if(num == inputNum && com[i] == 'D') {// 特殊向下翻页
                    first = 1;
                    num = 1;
                }else if(num == first && com[i] == 'U')//一般向上翻页
                {
                    first--;
                    num--;
                }else if(num == first + 3 && com[i] == 'D')//一般向下翻页
                {
                    first++;
                    num++;
                }else if(com[i] == 'U'){//其他情况，不翻页，只移动光标
                    num--;
                }else{
                    num++;
                }
            }
            for(int i = first; i < first + 3; i++){//输出当前页面
                cout << i << ' ';
            }
            cout << first + 3 << endl << num << endl;
        }
    }
    return 0;
}


