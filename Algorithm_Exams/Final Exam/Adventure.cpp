#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int n, w;
const int mxN = 1005;
vector<int> wi, v;
vector<vector<int>> dp;


int knapsack (int i, int mx_w)
{
    if (i < 0 || mx_w <= 0)
        return 0;

    if (dp[i][mx_w] != -1)
        return dp[i][mx_w];
    
    if (wi[i] <= mx_w)
    {
        int op1 = knapsack (i-1, mx_w - wi[i]) + v[i];
        int op2 = knapsack (i-1, mx_w);

        return dp[i][mx_w] = max (op1, op2);
    }
    else
    {
        return dp[i][mx_w] = knapsack (i-1, mx_w);
    }
}

void solve (int tc)
{
    cin >> n >> w;
    wi.assign (n, 0);
    v.assign (n, 0);
    dp.assign (n+1, vector<int>(w+1, -1));

    for (int i = 0; i < n; i++) cin >> wi[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    
    cout << knapsack (n-1, w) << endl;
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

