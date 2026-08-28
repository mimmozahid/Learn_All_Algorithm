#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void bfs (int src, vector<vector<int>>& adj_list, vector<bool>& v, vector<int>& level, vector<int>& parent)
{
    queue<int> q;
    q.push(src);
    v[src] = true;
    level[src] = 1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        
        for (auto child : adj_list[par])
        {
            if (!v[child])
            {
                q.push(child);
                v[child] = true;
                level[child] = level[par]+1;
                parent[child] = par;
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(n+1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    vector<int> level(n+1, -1), parent(n+1, -1);

    bfs (1, adj_list, vis, level, parent);

    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << level[n] << endl;
    vector<int> path;
    
    int vertex = n;
    while (vertex != -1)
    {
        path.push_back(vertex);
        vertex = parent[vertex];
    }

    reverse(path.begin(), path.end());
    for (auto x : path)
        cout << x << " ";
    cout << endl;
    
    return 0;
}