#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<int>x_direction = {1,-1,0,0};
vector<int>y_direction = {0,0,-1,1};

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
    int que;
    int ans;

    cin >> que;
    for(int i = 0; i < que; i++)
    {
        int x,y;
        ans = 0;
        cin >> x >> y;
        for(int d = 0; d < 4; d++)
        {
            int nx = x + x_direction[d];
            int ny = y + y_direction[d];
            if(0 <= nx && nx < h && 0 <= ny && ny < w)
                ans += grid[nx][ny];
        }
        cout << ans << endl;  
    }
    return (0);
}