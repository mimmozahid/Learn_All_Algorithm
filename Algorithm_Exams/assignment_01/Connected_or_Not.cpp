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

    vector<pair<int, int>> edge_list;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }

    sort(edge_list.begin(), edge_list.end());

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        
        if (x == y)
            cout << "YES" << endl;
        else if (binary_search(edge_list.begin(), edge_list.end(), pair<int, int>{x, y}))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}