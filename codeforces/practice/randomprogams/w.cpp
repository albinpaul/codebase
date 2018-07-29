#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;

const int INF = 1e9;

const int MINV = 1;
const int MAXV = 10;
int t;
int n;
int ar[(long)1.2e7];
void insert(int index){
    
    while(index<=10000000){
        ar[index]+=1;
        //DBGV(index);
        index+=(index&(-index));
    }
}

int query(int index){
    int summ=0;
    while(index>0){
        summ+=ar[index];
        index-=(index&(-index));
    }
    return summ;
}
int main()
{
    int  t;
    cin >>t;
    while(t--){
        cin>>n;
        memset(ar,0,sizeof(ar));
        int count=0;

        for(int i=0;i<n;i++){
            long temp;
            cin>>temp;
            insert(temp);
           // sudo apt-get install docker-cecount+=i+1-query(temp);
        }


        cout<<count<<endl;
    }

    


}
/*
Product Class:Temperature
Product :Temperature_Room1,Temperature_Room2
Offer Catalog:Change_temperature
Offers:Decrease temperature by 1,increase temperature by 1
Campaign category: Rooms temperature 
Campaign:Room 1 Campaign
Broadcasts:Acs in room 1-12 Jul 2018 09:00 IST , Acs in room 1-12 Jul 2018 09:00 IST
*/