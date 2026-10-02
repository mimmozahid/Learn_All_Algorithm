#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int n, m;
vector<vector<char>> mat;
vector<vector<bool>> vis;
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool valid (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int dfs (int si, int sj)
{
    int a = 1;
    vis[si][sj] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid (ci, cj) && !vis[ci][cj] && mat[ci][cj] == '.')
        {
            a += dfs (ci, cj);
        }
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    mat.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] == '.')
            {
                ans = min (ans, dfs (i, j));
            }
        }
    }
    
    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
    
    return 0;
}