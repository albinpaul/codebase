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
    int n,m;
    cin>>n>>m;
    char ar [n][m];   
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
    int flag=1;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if (!(ar[i][j] == '.' || ar[i][j] == '*' )){
                int num=ar[i][j]-'0';
                int s=0;
                for(int k=-1;k<=1;k++){
                    for(int g=-1;g<=1;g++){
                        if (0 <= i + k && i + k < n  && 0 <= j + g && j + g < m  && (!((g==0)&& (k==0)))){
                            if (ar[i + k][j + g]=='*')
                            {
                                s+=1;
                            }
                        }
                    }
                }
                
                if(s!=num){
                    flag=0;
                    break;
                }
            }else if(ar[i][j]== '.'){
                int num=0;
                int s = 0;
                for (int k = -1; k <= 1; k++)
                {
                    for (int g = -1; g <= 1; g++)
                    {
                        if (0 <= i + k && i + k < n && 0 <= j + g && j + g < m && (!((g == 0) && (k == 0))))
                        {
                            if (ar[i + k][j + g] == '*')
                            {
                                s += 1;
                            }
                        }
                    }
                }

                if (s != num)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag==0)
        {
            break;
        }
    }

    if(flag==0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}