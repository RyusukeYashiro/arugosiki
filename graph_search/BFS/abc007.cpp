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
vector<int> dxs  = {1 , 0 , -1 ,0};
vector<int> dys = {0 , 1 , 0 , -1};


int main(void){
    int h , w , sx , sy , gx , gy;
    cin >> h >> w;
    cin >> sx >> sy;
    cin >> gx >> gy;
    sx-- , sy-- ,gx-- ,gy--;
    vector<string> hold(h);
    for(int i = 0; i < h; i++) cin >> hold[i];

    // 最小手目を入れとく箱
    vector<vector<int>> dist(h , vector<int> (w , -1));
    queue<node> que;

    dist[sx][sy] = 0;
    que.push(node(sx , sy));

    while(!que.empty())
    {
        auto [x , y] = que.front();
        que.pop();

        for(int d = 0; d < 4; d++)
        {
            int dx = x + dxs[d];
            int dy = y + dys[d];

            if(dx < 0 || dx >= h || dy < 0 || dy >= w || hold[dx][dy] == '#') continue;

            if(dist[dx][dy] != -1) continue;

            dist[dx][dy] = dist[x][y] + 1;
            que.push(node(dx , dy));
        }
    }
    cout << dist[gx][gy] << endl;
}