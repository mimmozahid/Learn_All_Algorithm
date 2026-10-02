#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int n, m;
vector<vector<int>> mat;
vector<vector<bool>> vis;
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
vector<vector<int>> level;

bool valid (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs (int si, int sj)
{
    queue <pair<int, int>> q;
    q.push ({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty ())
    {
        auto par = q.front();
        q.pop ();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid (ci, cj) && !vis[ci][cj])
            {
                q.push ({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

void solve ()
{
    cin >> n >> m;
    mat.assign(n, vector<int>(m, 0));
    vis.assign(n, vector<bool>(m, false));
    level.assign (n, vector<int>(m, -1));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    bfs (si, sj);

    cout << level[di][dj] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--)
        solve ();

    return 0;
}

