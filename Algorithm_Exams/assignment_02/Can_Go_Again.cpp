//! not pass hidden test case...

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mxN = 1e5 + 9;
vector<pair<ll, ll>> adj_list[mxN];
vector<ll> dis(mxN, LLONG_MAX);
vector<ll> parent(mxN, -1);

struct Edge 
{
    ll u, v, w;
};

void dijkstra (ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();
        ll par_node = par.second;
        ll par_dis = par.first;

        if (par_dis > dis[par_node]) continue;

        for (auto child : adj_list[par_node])
        {
            ll child_node = child.first;
            ll child_dis = child.second;

            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                parent[child_node] = par_node;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, e;
    cin >> n >> e;

    vector<Edge> edge_list(e);
    for (auto &ed : edge_list)
        cin >> ed.u >> ed.v >> ed.w;
        
    vector<ll> h(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        bool changed = false;
        for (auto &ed : edge_list)
        {
            if (h[ed.u] + ed.w < h[ed.v])
            {
                h[ed.v] = h[ed.u] + ed.w;
                changed = true;
            }
        }
        if (!changed) break;
        if (i == n)
        {
            cout << "Negative Cycle Detected\n";
            return 0;
        }
    }
    
    for (auto &ed : edge_list)
        adj_list[ed.u].push_back({ed.v, ed.w + h[ed.u] - h[ed.v]});

    ll src, q;
    cin >> src >> q;

    dijkstra(src);

    while (q--)
    {
        ll d;
        cin >> d;
        if (dis[d] == LLONG_MAX)
            cout << "Not Possible\n";
        else
            cout << (dis[d] - h[src]) + h[d] << "\n";
    }

    return 0;
}