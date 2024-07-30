#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define mp map<int, int>
#define mpl map<long long, long long>
#define vv vector<vector<int>>

int main(void){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> Graph(n);
    int mx = -1;
    int mx_index = -1;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        int gsize = Graph[i].size();
        if(gsize > mx)
        {
            mx = Graph[i].size();
            mx_index = i;
        }
    }
    sort(Graph[mx_index].begin() , Graph[mx_index].end());
    for(auto v : Graph[mx_index])
    {
        cout << v << " ";
    }
    cout << endl;
}