#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

bool cycle;
int n, e;
vector<vector<int>> adj_list(100);
vector<bool> vis;
vector<int> parent;

void bfs (int src)
{
    queue<int> q;
    q.push (src);
    vis[src] = true;

    while (!q.empty ())
    {
        int par = q.front();
        q.pop();

        for (auto child : adj_list[par])
        {
            if (vis[child] && parent[par] != child)
                cycle = true;

            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vis.assign(n, false);
    parent.assign (n, -1);

    cycle = false;

    bfs (0);

    if (cycle) cout << "Cycle Detect" << endl;
    else cout << "No Cycle" << endl;
    
    return 0;
}