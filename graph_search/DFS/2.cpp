#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <cstdio>
#include <cstring>
#include <climits>
#include <tuple>
#include <numeric>
#include <sstream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define mp map<int, int>
#define mpl map<long long, long long>
#define vv vector<vector<int>>

void dfs(vector<vector<int>> &graph , vector<bool> &seen , int v)
{
    seen[v] = true;
    for(auto next_v : graph[v])
    {
        if(seen[next_v]) continue;
        dfs(graph , seen , next_v);
    }
}

int main(void){

    //頂点と辺の数
    int n , m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    //その頂点が検索済みなのかどうかを判定する配列
    vector<bool> seen(n , false);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // 頂点を０にしてスタートとしたときの探索
    dfs(graph , seen ,  0);
    
    for(int i = 0; i < n; i++)
    {
       if(!seen[i])
       {
            cout << "No" << endl;
            return (0);
       }
    }
    cout << "Yes" << endl;
}