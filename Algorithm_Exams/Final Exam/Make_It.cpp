#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e5+9;
int dp[mxN];

void f (int i)
{
    if (i >= mxN)
    {
        return;
    }
    if (dp[i] != -1)
    {
        return;
    }
    dp[i] = 1;
    
    f (i+3);
    f (i*2);
}

void solve (int tc)
{
    int n;
    cin >> n;

    if (dp[n] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset (dp, -1, sizeof(dp));
    f (1);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve (i);

    return 0;
}

