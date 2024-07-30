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
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        Graph[a].push_back(b);
    }

    for(int i = 0; i < n; i++)
    {
        sort(Graph[i].begin() , Graph[i].end());
        for(auto to : Graph[i])
            cout << to << " ";
        cout << endl;
    }
}