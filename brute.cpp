#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll k, C;
        cin >> n >> m >> k >> C;

        vector<vector<ll>> h(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> h[i][j];

        int best_s = 0;
        int count = 0;
        ll min_cost = LLONG_MAX;

        for (int s = 1; s <= min(n, m); s++) {
            int local_count = 0;
            ll local_min_cost = LLONG_MAX;
            for (int i = 0; i + s <= n; i++) {
                for (int j = 0; j + s <= m; j++) {
                    bool all_ge_k = true;
                    ll cost = 0;
                    for (int x = 0; x < s && all_ge_k; x++) {
                        for (int y = 0; y < s && all_ge_k; y++) {
                            ll val = h[i + x][j + y];
                            cost += val;
                            if (val < k)
                                all_ge_k = false;
                        }
                    }
                    if (all_ge_k && cost <= C) {
                        local_count++;
                        local_min_cost = min(local_min_cost, cost);
                    }
                }
            }

            if (local_count > 0) {
                best_s = s;
                count = local_count;
                min_cost = local_min_cost;
            }
        }

        if (best_s == 0) {
            cout << "0 0 0\n";
        } else {
            cout << best_s << " " << count << " " << min_cost << "\n";
        }
    }

    return 0;
}
