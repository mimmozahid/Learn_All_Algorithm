#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(n);
    while (e--)
    {
        int a , b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        vector<int> ans;
        for (auto child : adj_list[x])
            ans.push_back(child);

        sort(ans.rbegin(), ans.rend());

        if (ans.empty())
        {
            cout << -1 << endl;
            continue;
        }
        for (auto p : ans) cout << p << " ";
        cout << endl;
    }
    
    
    return 0;
}