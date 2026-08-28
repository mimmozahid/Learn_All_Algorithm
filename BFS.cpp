#include <bits/stdc++.h>
using namespace std;

void bfs (int src, int n, vector<vector<int>>& adj_list, vector<bool>& vis)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << " ";

        for (auto child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
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
    vector<vector<int>> adj_list(n);
    vector<bool> vis(n+9, false);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    bfs (0, n, adj_list, vis);
    
    return 0;
}