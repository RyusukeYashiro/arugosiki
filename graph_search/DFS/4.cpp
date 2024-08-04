#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <cstdio>
#include <cstring>
#include <climits>
#include <tuple>
#include <numeric>
#include <sstream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define mp map<int, int>
#define mpl map<long long, long long>
#define vv vector<vector<int>>

//魂の個数

// テストケース例
// 8 8
// ..#.....
// .###.##.
// .###..#.
// ####....
// .#..###.
// .....###
// ....##.#
// .....##.

//上下左右を探索をする場所を既に保持しておく
vector<int> dxs = {0, 1, 0, -1};
vector<int> dys = {-1, 0, 1, 0};

int h, w;

void dfs(vector<string> &grid, vector<vector<bool>> &seen, int vx, int vy) {
    seen[vx][vy] = true;

    for (int i = 0; i < 4; i++) {
        int nx = vx + dxs[i];
        int ny = vy + dys[i];

        // 枠外チェック
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        // #ではない場合をスキップ
        if (grid[nx][ny] != '#') continue;
        // 既に訪れた場所をスキップ
        if (seen[nx][ny]) continue;

        dfs(grid, seen, nx, ny);
    }
}

int main(void) {
    cin >> h >> w;
    vector<string> grid(h);
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            //黒マスなら探索スタート。つながっている黒マスが塗られていく
            // そうしてi , jを進めて始められる箇所に出逢えば、それは新しい塊ということ
            if (grid[i][j] == '#' && !seen[i][j]) {
                dfs(grid, seen, i, j);
                count++;
            }
        }
    }

    cout << count << endl;
}