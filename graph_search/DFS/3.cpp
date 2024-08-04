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

//連結成分の個数判定(dfsで実装)
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
    int n , m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> seen(n , false);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //全頂点が探索済みの状態になるまで探索を繰り返す
    // つまり探索をに入ることができたらそこの頂点から新しいグラフが始まるということを示している
    int count = 0;
    for(int v = 0; v < n; v++)
    {
        if(seen[v]) continue;
        dfs(graph , seen , v);
        count++;
    }
    cout << count << endl;
}