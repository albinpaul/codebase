#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout<< #x <<" is "<< x << endl
const unsigned long long  n=50000000;
int ar[n];
int memo[n];
int mm=0;


unsigned long long fun(unsigned long long t)
{        if(t>n){
		cout<<"outofbounds " << t <<endl;
                unsigned long long c;
		if(t%2==0 ){        
			c=fun(t/2)+1;
		}else{	
			c=fun((3*t)+1)+1;
		}

		return c;	

	}
	if(memo[t]==1){
		return ar[t];
	}
	if(t==1){return 1;}
	if(t%2==0 ){        
		ar[t]=fun(t/2)+1;
	}else{	
		ar[t]=fun((3*t)+1)+1;
	}
	memo[t]=1;
	return ar[t];
}
          2
long long foo(){

	memset(memo,0,sizeof(int)*n);
	memset(ar,0,sizeof(int)*n);
	ar[1]=1;
	int tt=1000000;
	for(long i=2;i<tt;i++){
		ar[i]=fun(i);			 4
	} 
	int g=0;                             
	for(long i=2;i<tt;i++){
		if(ar[i]>g){ g=ar[i];}			
	}                              
	return g;			
}

int main(){
	cin.tie(0);

memset(memo,0,sizeof(int)*n);
	cout<<foo()<<endl;
//cout<<fun(13)<<endl;
	cin.get();
return 0;
}