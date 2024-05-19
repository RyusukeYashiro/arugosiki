#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int x_direction[] = {1,-1,0,0,-1,-1,1,1};
int y_direction[] = {0,0,-1,1,-1,1,-1,1};

// 自身が死んでいるかつ x=3 ならば生きたマスとなる。
// 自身が生きているかつ x=2 or 3 ならば生き続ける。
// 自身が生きているかつ x≤1 ならば過疎により死滅する。
// 自身が生きているかつ x≥4 ならば過密により死滅する。

int ft_count_dedline(int i , int j,int n, vector<vector<int>> *grid)
{
    int count;

    count = 0;
    for(int d = 0; d < 8; d++)
    {
        int nx = i + x_direction[d];
        int ny = j + y_direction[d];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if((*grid)[nx][ny] == 1)
            count++;   
    }
    return (count);
}

void ft_case_deal(int i, int j,vector<vector<int>> *grid , int dead_line)
{
    if((*grid)[i][j] == 0 && dead_line == 3)
        (*grid)[i][j] = 1;
    else if((*grid)[i][j]== 1 && ((dead_line == 2) || (dead_line == 3)))
        (*grid)[i][j] = 1;
    else if((*grid)[i][j] == 1 && dead_line <= 1)
        (*grid)[i][j] = 0;
    else if((*grid)[i][j] == 1 && dead_line >= 4)
        (*grid)[i][j] = 0;
}

void ft_solove_life_game(vector<vector<int>> *grid , int n , int x)
{
    int dead_line;
    int step;

    dead_line = 0;
    step = 0;
    while(x > 0)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int dead_line = ft_count_dedline(i , j , n, grid);
                ft_case_deal(i , j , grid , dead_line);
            }
        }
        x--;;  
    }
}
int main(void)
{
    int n,x;

    cin >> n >> x;
    vector<vector<int>> grid(n, vector<int>(n,0));
    vector<vector<char>> ans(n , vector<char>(n , '.'));

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
        {
            if(s[j] == '#')
                grid[i][j] = 1;
            else 
                grid[i][j] = 0;
        }
    }
    ft_solove_life_game(&grid , n , x);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1)
                ans[i][j] = '#';
            cout << ans[i][j];
        }
        cout << endl;
    }
}
