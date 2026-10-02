#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int n, m;
vector<vector<char>> mat (1009, vector<char> (1009));
vector<vector<bool>> vis;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<vector<pair<int, int>>> parent;

bool valid (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

bool flg = false;

void bfs(int si, int sj)
{
    queue <pair<int, int>> q;
    q.push ({si, sj});
    vis[si][sj] = true;

    while (!q.empty ())
    {
        auto par = q.front();
        q.pop ();
        int par_i = par.first;
        int par_j = par.second;

        if (mat[par_i][par_j] == 'D')
        {
            int ai = par_i, aj = par_j;

            while (!(ai == si && aj == sj))
            {
                if (mat[ai][aj] == '.')
                    mat[ai][aj] =  'X';
                
                auto ch = parent[ai][aj];
                ai = ch.first;
                aj = ch.second;
            }
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid (ci, cj) && !vis[ci][cj] && (mat[ci][cj] == '.' || mat[ci][cj] == 'D'))
            {
                q.push ({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
}

void solve ()
{
    cin >> n >> m;
    vis.assign(n, vector<bool>(m, false));
    parent.assign (n, vector<pair<int, int>> (m));

    int si, sj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];

            if (mat[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
        }
    }
    
    bfs (si, sj);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--)
        solve ();

    return 0;
}

