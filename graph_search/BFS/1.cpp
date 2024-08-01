#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define mp map<int, int>
#define mpl map<long long, long long>
#define vv vector<vector<int>>

int main(void){
    int n , m; cin >> n >> m;
    vector<vector<int>> Graph(n);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    //各頂点が何手目に検索されたか
    // -1は未到達
    vector<int> dist(n , -1);
    queue<int> que;

    dist[0] = 0;
    que.push(0);

    while(!que.empty())
    {
        // キューから頂点を取り除く
        int v = que.front();
        que.pop();

        // 頂点vから１手で行ける頂点next_vを検索
        for(auto next_v : Graph[v]) 
        {
            if(dist[next_v] != -1)
            {
                continue;
            }

            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}