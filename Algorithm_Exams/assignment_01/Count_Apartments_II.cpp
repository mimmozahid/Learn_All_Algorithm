#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
int n, m;
vector<vector<char>> mat(1005, vector<char>(1005));
vector<vector<bool>> vis(1005, vector<bool>(1005, false));
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

vector<int> ans;
bool vaild (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int bfs (int si, int sj)
{
    int sz = 0;
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        sz++;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (vaild (ci, cj) && !vis[ci][cj] && mat[ci][cj] == '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }

    return sz;
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
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] == '.')
            {
                int a = bfs (i, j);
                ans.push_back(a);
            }
        }
        
    }
    
    if (ans.empty())
    {
        cout << 0 << endl;
        return 0;
    }
    sort (ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}