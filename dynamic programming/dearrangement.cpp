// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

//recursion
int dearr(int N){
    if(N==1){
        return 0;
    }
    if(N==2){
        return 1;
    }
    int total=(N-1)*(dearr(N-1)+dearr(N-2));
    return total;
}
//memo
int memo(int N,vector<int>dp){
    if(N==1){
        return 0;
    }
    if(N==2){
        return 1;
    }
    if(dp[N]!=-1){
        return dp[N];
    }
    dp[N]=(N-1)*(memo(N-2,dp)+memo(N-1,dp));
    return dp[N];
}

//tabultion
int tab(int N){
    vector<int>dp(N+1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<N+1;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[N];
}
//space 
int space(int N){
    int curr;
    int pre1=0;
    int pre2=1;
    for(int i=3;i<=N;i++){
        curr=(i-1)*(pre1+pre2);
        pre1=pre2;
        pre2=curr;
    }
    return curr;
}
int main() {
  int N;
  cin>>N;
  int ans=dearr(N);
  cout<<ans<<endl;
  vector<int>dp(N+1,-1);
  int b=memo(N,dp);
  cout<<b<<endl;
  int c= tab(N);
  cout<<c<<endl;
  int d=space(N);
  cout<<d<<endl;
    return 0;
}