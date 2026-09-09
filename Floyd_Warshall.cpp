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

    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                mat[i][j] = 0;
            else
                mat[i][j] = INT_MAX;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        mat[a][b] = c;
    }
    
    //? Floyd-Warshall
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((mat[i][k] != INT_MAX && mat[k][j] != INT_MAX) && (mat[i][k] + mat[k][j] < mat[i][j]))
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == INT_MAX)
                cout << "I ";
            else
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}