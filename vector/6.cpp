#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<int>x_direction = {1,-1,0,0,0};
vector<int>y_direction = {0,0,-1,1,0};




void ft_solve(vector<vector<int>>& grid , int h, int w)
{
    int q;

    cin >> q;
    for(int i = 0; i< q; i++)
    {
        int qv;
        int ans;
        int x,y;

        cin >> qv;
        cin >> x >> y;
        ans = 0;
        for(int d = 0; d < 5; d++)
        {
            int nx = x + x_direction[d];
            int ny = y + y_direction[d];
            if(0 > nx || nx >= h ||  0 > ny ||  ny >= w)
                continue;
            if(qv == 0)
            {
                if(grid[nx][ny] == 1)
                   grid[nx][ny] = 0;
                else 
                    grid[nx][ny] = 1; 
            }
            else if(qv == 1)
                ans += grid[nx][ny];
        }
        if(qv == 1)
            cout << ans << endl;
    }  
}


int main(void)
{
    int h,w;

    cin >> h >> w;
    vector<vector<int> > grid(h, vector<int>(w,0));
    for(int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < w; j++)
        {
            if(s[j] == '#')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }
    ft_solve(grid , h , w);
    return (0);
}