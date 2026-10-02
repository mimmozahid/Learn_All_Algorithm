#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

vector<int> par, sz;

int dsu_find (int node)
{
    if (par[node] == -1)
        return node;

    int leader = dsu_find (par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union (int u, int v)
{
    int leader1 = dsu_find (u);
    int leader2 = dsu_find (v);

    if (sz[leader1] >= sz[leader2])
    {
        par[leader2] = leader1;
        sz[leader1] += sz[leader2];
    }
    else
    {
        par[leader2] = leader1;
        sz[leader2] += sz[leader1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, e, ans = 0;
    cin >> n >> e;

    par.assign(n+1, -1);
    sz.assign(n+1, 1);

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        if (dsu_find(a) == dsu_find(b))
            ans++;
        else
            dsu_union (a, b);
    }

    cout << ans << endl;
    
    return 0;
}