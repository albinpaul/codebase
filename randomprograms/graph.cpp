#include <bits/stdc++.h>

int solve();
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ::std::ios::sync_with_stdio(false);
    ::std::cin.tie(0);
    ::std::cout.tie(0);

    solve();
}

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll, ll> pii;

typedef vector<ll> vi;

#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()

#define read(x) scanf("%d", &x)
#define readl(x) scanf("%lld", &x)

int const MAXN = 505050;

vector<int> g[1 << 17];
int n, m;
int cnt[1 << 17], ans;

void dfs(int x, int p)
{
    cnt[x] = 1;
    for (int y : g[x])
    {
        if (y == p)
            continue;
        dfs(y, x);
        if (cnt[y] % 2 == 0)
        {
            ++ans;
            cnt[y] = 0;
        }
        cnt[x] += cnt[y];
    }
}

int solve()
{
    read(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        read(u);
        read(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans = 0;
    if (n & 1)
        ans = -1;
    else
        dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}