#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 



void solve (int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = -1, s_mx = -1;
    for (auto &x : v)
    {
        cin >> x;
        mx = max (x, mx);
    }

    for (auto x : v)
    {
        if (mx == x) continue;
        s_mx = max (x, s_mx);
    }

    int p = -1, q = -1;
    for (int i = 0; i < n; i++)
    {
        if (mx == v[i]) p = i;
        if (s_mx == v[i]) q = i;
    }
    
    if (p < q) cout << p << " " << q << endl;
    else cout << q << " " << p << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve (i);

    return 0;
}

