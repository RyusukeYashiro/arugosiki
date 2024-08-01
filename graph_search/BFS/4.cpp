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

using node = pair<int , int>;
vector<int> dxs = {1 , 0 , -1 , 0};
vector<int> dys = {0 , 1 , 0 , -1};

int main(void){
    int h , w; cin >> h >> w;
    int x , y , gx , gy;
    cin >> x >> y >> gx >> gy;
    vector<string>graph(h);
    for(int i = 0; i < h; i++)
    {
        cin >> graph[i];
    }
    vector<vector<int>> dist(h , vector<int>(w , -1));

    queue<node> que;
    dist[x][y] = 0;
    que.push(node(x , y));

    while(!que.empty())
    {
        auto [xq , yq] = que.front();
        que.pop();

        for(int d = 0; d < 4; d++)
        {
            int dx = xq + dxs[d];
            int dy = yq + dys[d];

            if(dx < 0 || dx >= h || dy < 0 || dy >= w || graph[dx][dy] == 'B') continue; 

            if(dist[dx][dy] != -1) continue;

            dist[dx][dy] = dist[xq][yq] + 1;
            que.push(node(dx , dy));
        }
    }

    cout << dist[gx][gy] << endl;
}