#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 
用正统的链表做法。构建链表，然后依次将结点插入。
插入的时候遍历链表找到插入结点的前序结点（因为表中元素互异），
断开前序结点与后序结点的连接，插入结点连接后续结点，前序结点连接插入结点。
后续直接遍历链表输出，当遇到要删除的结点值时不输出即可。 
*/

struct node{ //链表结点
    int val;
    struct node* next = NULL;
};

int main(){
    int n, val;
    while(cin >> n >> val){
        node* head = new node; //头结点
        head->val = val;
        for(int i = 1; i < n; i++){
            int pre, cur;
            cin >> cur >> pre;
            node* p = new node; //添加这个结点
            p->val = cur;
            node* q = head;
            while(q->val != pre) //找到前序结点
                q = q->next;
            p->next = q->next; //断开
            q->next = p; //插入
        }
        int remove;
        cin >> remove;
        node* p = head;
        while(p != NULL){
            if(p->val != remove) //不输出remove，其他都输出
                cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    return 0;
}
