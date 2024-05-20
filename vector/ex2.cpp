#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<int>x_direction = {1,-1,0,0,0};
vector<int>y_direction = {0,0,-1,1,0};

int main(void)
{
    int h,w; 
    int sum_black;

    cin >> h >> w;
    sum_black = 0;
    vector<vector<int>>grid(h,vector<int>(w , 0));
    for(int i = 0; i < h; i++)
    {
        string s; 
        cin >> s;
        for(int j = 0; j < w; j++)
        {
            if(s[j] == '#')
            {
                sum_black++;
                grid[i][j] = 1;
            }
            else
                grid[i][j] = 0;
        }
    }

    int q;
    
    cin >> q;
    for(int i=0; i < q; i++)
    {
        int type;
        cin >> type;
        if(type == 0)
        {
            int p,q;
            cin >> p >> q;
            for(int d = 0; d < 5 ; d++)
            {
                int nx = p + x_direction[d];
                int ny = q + y_direction[d];

                if(nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                if(grid[nx][ny] == 0)
                {
                    grid[nx][ny] = 1;
                    sum_black++;
                }
                else if(grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 0;
                    sum_black--;
                }
            }
        }
        else if(type == 1)
            cout << sum_black << endl;
    }
    return (0);
}

