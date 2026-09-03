#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid(100, vector<char>(100));
vector<vector<bool>> vis(100, vector<bool>(100, false));
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool valid (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs (int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid (ci, cj) && !vis[ci][cj])
            dfs (ci, cj);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    
    int si, sj;
    cin >> si >> sj;
    dfs (si, sj);
    
    return 0;
}