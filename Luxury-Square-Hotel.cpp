#include <bits\stdc++.h>
using namespace std;
#define ll long long
#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr);


bool is_valid(int s,int n ,int m, ll C, vector<vector<int>>& dp, vector<vector<ll>>& sumH) 
{
    if (s == 0) return false;
    if (s > n || s > m) return false;

    for (int i = s; i <= n; i++) 
    {
        for (int j = s; j <= m; j++) 
        {
            if (dp[i][j] >= s) 
            {
                ll cost = sumH[i][j] - sumH[i - s][j] - sumH[i][j - s] + sumH[i - s][j - s];
                if (cost <= C)
                    return true;
            }
        }
    }
    return false;
}

        
int main() 
{
    fastIO

    int t;
    cin >> t;
    while (t--) 
    {
        int n, m;
        ll k, C;
        cin >> n >> m >> k >> C;

        vector<vector<ll>> h(n + 1, vector<ll>(m + 1));
        vector<vector<ll>> sumH(n + 1, vector<ll>(m + 1, 0));

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++) 
            {
                cin >> h[i][j];
                sumH[i][j] = h[i][j] + sumH[i - 1][j] + sumH[i][j - 1] - sumH[i - 1][j - 1];
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++) 
            {
                if (h[i][j] >= k) 
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }

        

        int lo = 0, hi = min(n, m), best_s = 0;
        while (lo <= hi) 
        {
            int mid = (lo + hi) / 2;
            if (is_valid(mid, n, m, C, dp, sumH)) 
            {
                best_s = mid;
                lo = mid + 1;
            } 
            else 
            {
                hi = mid - 1;
            }
        }

        if (best_s == 0) 
        {
            cout << "0 0 0\n";
            continue;
        }

        int count = 0;
        ll min_cost = LLONG_MAX;
        for (int i = best_s; i <= n; i++) 
        {
            for (int j = best_s; j <= m; j++) 
            {
                if (dp[i][j] >= best_s) 
                {
                    ll cost = sumH[i][j] - sumH[i - best_s][j] - sumH[i][j - best_s] + sumH[i - best_s][j - best_s];
                    if (cost <= C) 
                    {
                        count++;
                        min_cost = min(min_cost, cost);
                    }
                }
            }
        }

        cout << best_s << " " << count << " " << min_cost << "\n";
    }

    return 0;
}

