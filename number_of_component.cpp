#include <bits/stdc++.h>
using namespace std;

void dfs (int src, vector<vector<int>>& adj_list, vector<bool>& vis)
{
    // cout << src << " ";
    vis[src] = true;

    for (auto child : adj_list[src])
    {
        if (!vis[child])
            dfs (child, adj_list, vis);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(n);
    vector<bool> vis(n, false);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(0, adj_list, vis);
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}