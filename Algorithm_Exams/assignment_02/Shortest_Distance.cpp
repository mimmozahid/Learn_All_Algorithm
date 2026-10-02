#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const ll INF = LLONG_MAX;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;

    vector<vector<ll>> mat(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) mat[i][i] = 0;

    while (e--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        mat[a][b] = min(mat[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (mat[i][k] == INF) continue;
            for (int j = 1; j <= n; j++)
            {
                if (mat[k][j] == INF) continue;
                
                if (mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (mat[x][y] == INF) cout << -1 << '\n';
        else cout << mat[x][y] << '\n';
    }
    
    return 0;
}