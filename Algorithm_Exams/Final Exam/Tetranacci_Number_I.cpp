#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

vector<ll> dp;

ll tetra (int n)
{
    if (n == 1 || n == 0)
        return n;

    if (n == 2)
        return 1;
    if (n == 3)
        return 2;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = tetra (n-1) + tetra (n-2) + tetra (n-3) + tetra (n-4);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    dp.assign (n+9, -1);

    cout << tetra (n) << endl;
    
    return 0;
}
