#include<iostream>
#include<vector>
using namespace std;
/* 
DFS
每次进入一个点，将其加入临时路径数组中，
把该位改成0表示不能进入，然后依次搜索该位上、右、下、左四个方向的点，
如果搜索的这个点可以进入则路径进入，
如果四个方向都没有可以走的路表示此路不通，回溯——删去路径最后一个，重置该位为0. 
找到横纵坐标都等于矩阵最后一位则表示找到路径，复制现有路径然后返回。
 */
vector<pair<int, int>> ans;
void dfs(vector<vector<int>>& matrix, int n, int m, int i, int j,
         vector<pair<int, int>>& paths) {
    paths.push_back(make_pair(i, j)); //记入路径
    matrix[i][j] = 1; //经过部分设置为1，表示后续不能经过
    if (i == n - 1 && j == m - 1) { //到达终点
        ans = paths;
        return;
    }
    //四个方向搜索
    if (i + 1 < n && matrix[i + 1][j] == 0)
        dfs(matrix, n, m, i + 1, j, paths);
    if (j + 1 < m && matrix[i][j + 1] == 0)
        dfs(matrix, n, m, i, j + 1, paths);
    if (i - 1 >= 0 && matrix[i - 1][j] == 0)
        dfs(matrix, n, m, i - 1, j, paths);
    if (j - 1 >= 0 && matrix[i][j - 1] == 0)
        dfs(matrix, n, m, i, j - 1, paths);
    paths.pop_back(); //回溯
    matrix[i][j] = 0;
}
int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int> > matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) //输入迷宫矩阵
                cin >> matrix[i][j];
        vector<pair<int, int> > paths; //记录临时路径
        dfs(matrix, n, m, 0, 0, paths); //dfs遍历矩阵
        for (int i = 0; i < ans.size(); i++) //输出路径
            cout << "(" << ans[i].first << "," << ans[i].second << ")" << endl;
    }
    return 0;
}
