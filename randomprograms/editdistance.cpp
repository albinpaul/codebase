#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << endl
const double PI = 3.141592;
const int inf = (int)1.01e9;
const double eps = (1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;

void foo()
{
    /*
	Edit distance dynamic programming problem 
	  */
    string source, destination;
    cin >> source;
    cin >> destination;
    const int n = source.length();
    const int m = destination.length();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(int) * (m + 1) * (n + 1));

    // initialized the base conditions with the number of characters to be removed from a string if the other string is empty
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    // initialized the base conditions with the number of characters to be removed from a string if the other string is empty
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    /*
    Take each element and check with corresponding value in the other string if it is equal take the next value else take the 
    other value 
    */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (source[i - 1] == destination[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]);
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef debug
    freopen("input.txt", "r", stdin);
#endif
    foo();

    return 0;
}