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

bool ans;
bool vaild (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs (int si, int sj)
{
    if (mat[si][sj] == 'B')
    {
        ans = true;
        return;
    }
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (vaild(ci, cj) && !vis[ci][cj] && (mat[ci][cj] == '.' || mat[ci][cj] == 'B'))
            dfs (ci, cj);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int si,sj; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
            {
                si = i, sj = j;
            }
        }
    }
    ans = false;
    dfs (si, sj);
    // cout << si << " " << sj << endl;
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}