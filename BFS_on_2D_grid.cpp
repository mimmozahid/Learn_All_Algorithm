#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid(100, vector<char>(100));
vector<vector<bool>> vis(100, vector<bool>(100, false));
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
vector<vector<int>> level (100, vector<int> (100, -1));

bool valid (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs (int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    
    while (!q.empty ())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        // cout << par_i << " " << par_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid (ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j]+1;
            }
        }
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
    
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    bfs (si, sj);

    cout << "Shortest Path " << level[di][dj] << endl;
    
    return 0;
}