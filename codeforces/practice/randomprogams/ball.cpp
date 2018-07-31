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
string s;
cin >> s;
int n;
int ar[s.length()+1];
memset(ar,0,sizeof(int) * (s.length()+1));
for(int i =0;i<s.length();i++){
    ar[i+1]=(s[i]==s[i+1])+ar[i];
}
// for (int i = 0; i < s.length(); i++)
// {
//   cout<<ar[i]<<" ";
// }cout<<endl;
cin >> n;
while(n--){
    int l,r;
    cin >> l >> r;
    cout<<ar[r-1]-ar[l-1]<<endl;
}


}