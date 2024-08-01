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
    int n , m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> dist( n , -1);
    queue<int> hold;

    dist[0] = 0;
    hold.push(0);

    int mx = 0;
    while(!hold.empty())
    {
        int v = hold.front();
        hold.pop();
        for(int nv : graph[v])
        {
            if(dist[nv] == -1)
            {
                dist[nv] = dist[v] + 1;
                hold.push(nv);
                if(dist[nv] > mx) mx = dist[nv];
            }
        }
    }
    cout << mx << endl;
}