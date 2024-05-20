#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// O(H+W)になるため、前処理をしないと間に合わないため、
// 値を保持しておく配列を用意しておく
// そうするとO(HW) + O(1)でO(HW + Q)となる

int main(void)
{
    int h,w; 

    cin >> h >> w;
    vector<vector<int>>grid(h,vector<int>(w , 0));
    for(int i = 0; i < h; i++)
    {
        string s; 
        cin >> s;
        for(int j = 0; j < w; j++)
        {
            if(s[j] == '#')
                grid[i][j] = 1;
        }
    }

    vector<int>tate(w , 0);
    vector<int>yoko(h , 0);

    for(int j = 0; j < w; j++)
    {
        for(int i = 0; i < h; i++)
        {
            tate[j] += grid[i][j];
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            yoko[i] += grid[i][j];
        }
    }

    int q;

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int p,q;

        cin >> p >> q;
        int ans = yoko[p] + tate[q] - grid[p][q];
        cout << ans << endl;        
    }

}