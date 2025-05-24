#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char* argv[]) 
{
    registerGen(argc, argv, 1);a

    const int MAX_T   = 10;
    const int MAX_N   = 1000;
    const int MAX_M   = 1000;
    const int MAX_H   = 1000000;
    const ll  MAX_C   = 1LL * MAX_N * MAX_M * MAX_H;

    const double P_BIG = 0.2;

    ll cell_budget = 1LL * MAX_N * MAX_M;
    ll cells_used = 0;

    int T = rnd.next(1, MAX_T);
    if (rnd.next(0.0, 1.0) < P_BIG) 
    {
        T = 1;
    }
    cout << T << "\n";

    for (int tc = 0; tc < T; tc++) 
    {
        int n, m;

        if (T == 1 && rnd.next(0.0, 1.0) < P_BIG) 
        {
            n = m = MAX_N;
        } 
        else 
        {
            int remaining = T - tc;
            ll remain_cells = cell_budget - cells_used;
            ll max_cells_here = max<ll>(1, remain_cells - (remaining - 1));
            ll area_cap = min<ll>(1LL * MAX_N * MAX_M, max_cells_here);

            ll A = rnd.next(1LL, area_cap);

            n = min<ll>(MAX_N, A);
            m = (A + n - 1) / n;
            if (m > MAX_M) 
            {
                m = MAX_M;
                n = (A + m - 1) / m;
            }
        }

        cells_used += 1LL * n * m;

        ll k = rnd.next(1, MAX_H);
        ll C = rnd.next(1LL, MAX_C);

        cout << n << " " << m << " " << k << " " << C << "\n";

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                ll h = rnd.next(1, MAX_H);
                cout << h << (j + 1 < m ? ' ' : '\n');
            }
        }
    }

    return 0;
}
