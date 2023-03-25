#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int N,M,etop;

struct Edge
{
    int u,v,len;
    Edge *next;
}epool[10001];

struct Node
{
    Edge *first;
}nodes[10001];

void addEdge(int u, int v, int len = 0){
    epool[etop].u = u;
    epool[etop].v = v;
    epool[etop].len = len;
    epool[etop].next = nodes[u].first;
    nodes[u].first = &epool[etop];
    ++etop;
}


//一般搜索
bool discovered[10001];
stack<int> F;   //dfs
//queue<int> F; //bfs
void search(){
    F.push(1);
    discovered[1] = true;
    while (!F.empty())
    {
        int id = F.top();           //dfs
        //int id = F.front();       //bfs
        
        F.pop();
        cout<<id<<" ; ";

        //遍历 所有出边
        Edge* e = nodes[id].first;
        while (e != nullptr)
        {
            if(!discovered[e->v]){
                F.push((*e).v);     //e->v
                discovered[e->v] = true;
            }
            e = e->next;
        }
    }
}


//递归dfs
bool visited[10001];
void DFS(int id){
    visited[id] = true;
    cout<<id<<" ; ";
    Edge* e = nodes[id].first;
    while (e !=nullptr)
    {
        if (!visited[e->v])
            DFS((*e).v);
        e = e->next;
    }
}


void test01(){
    int i,u,v,len;
    cin>>N>>M;
    for (i = 0; i <= M; ++i)
    {
        cin>>u>>v>>len;
        addEdge(u,v,len);
        //addEdge(v,u,len);         //无向图
    }
    
    DFS(1);     //使用dfs 递归，int id 初始化为1
    search();   //一般 深度广度便利搜索函数

//便利ID号 出边
//    int id;
//    Edge *e = nodes[id].first;
//    while (e != nullptr){
        /* code */
//        e = e->next;
        //or: e = (*e).v;
//    }  

    
}



int main(){
    test01();
}