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
long s, g;
void foo(){
 
    const long long int n=1000000;
    bool ar[n+1];
    memset(ar,0,sizeof(bool) *(n+1));
    ar[1]=1;
    ar[0]=1;
    for(int i =4;i<=n;i+=2){
        ar[i]=1;
    }
    for(int i =3;i<=sqrt(n);i++){
        if(ar[i]==0){
            for(int j=2*i;j<=n;j+=i){
                ar[j]=1;
            }
        }
    }
    int ssum=0;
    for(int i=11;i<=n;i++){
        if(ar[i]==0){
           
            vector <int> v;
            v.clear();
            int flag = 0;
            int temp=i;
            while(temp){
                int p=temp%10;

                if((p)==0 || ar[temp]==1){
                  
                    flag=1;
                }

                v.push_back(p);
                temp/=10;
            }
            temp=0;
            if(flag==0){
              
                int power=1;
                for (int j = 0; j <v.size(); j++)
                {
                    
                    temp += power*  v[j];
                  
                    power*=10;
                    if(ar[temp]==1){
                        flag=1;
                    }
                }
                
               
            }
            
            if(flag==0){
                cout<<i<<endl;
                ssum+=i;
            }

        }
    }
    cout<<ssum<<endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    foo();
    return 0;
}