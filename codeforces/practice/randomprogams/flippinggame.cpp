#include <bits/stdc++.h>
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

void solve();

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
#ifdef _DEBUG
    int tt = clock();
#endif

    solve();

#ifdef _DEBUG
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
#endif
}

void solve()
{
    int n;
    cin >>n;
    int ar[n];
    int dp[n+1][2];
    memset(dp,0,sizeof(int) *(n+1) *2) ;

    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int count1=0,count2=0;
    for (int i = 1; i <=n ; i++)
    {
        if(ar[i-1]==1){
            count2++;
            dp[i][0]=count1;
            dp[i][1] = count2;
        }else{
            count1++;
            dp[i][0] = count1;
            dp[i][1] = count2;
        }
    }
    int m=0;
    for(int i =1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int g=dp[i-1][1]+dp[j][0]-dp[i-1][0]+dp[n][1]-dp[j][1];
            if(g>m){
                m=g;
            }
        }
    }
    cout<<m<<endl;
}