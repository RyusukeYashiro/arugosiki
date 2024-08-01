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

int main(void)
{
    int n , m; cin >> n >> m;
    vector<vector<int>> Graph(n);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    vector<int> dist(n , -1);
    queue<int> hold;
    vector<vector<int>> nodes(n);
    
    dist[0] = 0;
    hold.push(0);
    nodes[0].push_back(0);

    while(!hold.empty())
    {
        int v = hold.front();
        hold.pop();
        for(int nv : Graph[v])
        {
            if(dist[nv] == -1)
            {
                dist[nv] = dist[v] + 1;
                hold.push(nv);
                nodes[dist[nv]].push_back(nv);
            }
        }
    }
    for(int k = 0; k < n; k++)
    {
        sort(nodes[k].begin() , nodes[k].end());
        for(int v : nodes[k])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return (0);
}