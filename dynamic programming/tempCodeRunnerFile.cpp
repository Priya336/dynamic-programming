// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int store(vector<int>v,vector<int>w,int W,int N){
    if(N==0 ){
        if( w[0]<=W){
        return v[0];}
        else{
            return 0;
        }
    }
 

  int incl=0;
  if(w[N]<=W){
      incl=store(v,w,W-w[N],N-1)+v[N];
  }
 int excl=store(v,w,W,N-1);
   int maxi=max(incl,excl);
   return maxi;
        
}

int memo(vector<vector<int>>dp,vector<int>v,vector<int>w,int W,int N){
    if(N==0){
        if(W<=w[0]){
            return v[0];
        }
        else{
            return 0;
        }
    }
    if(dp[N][W]!=-1){
        return dp[N][W];
    }
    int incl=0;
    if(w[N]<=W){
      incl=memo(dp,v,w,W-w[N],N-1)+v[N];
  }
 int excl=memo(dp,v,w,W,N-1);
 dp[N][W]=max(incl,excl);
 return dp[N][W];
}

int tabulation(vector<int>v,vector<int>w,int N,int W){
vector<vector<int>>dp(N+1,vector<int>(W+1));
//base case 
    
            for(int i=w[0];i<=W;i++){
                 if(w[0]<=W){
            dp[0][i]=v[0];
            }
            else{
                dp[0][i]=0;
            }  
        }
        for(int i=1;i<=N;i++){
         for(int j=0;j<=W;j++){
            int incl=0;
            if(w[i]<=j ){
                incl=dp[i-1][j-w[i]]+v[i];
            }
            int excl=dp[i-1][j];
            dp[i][j]=max(incl,excl);
         }
        }
    
        return dp[N][W];
    }

//space optimization
int space(vector<int>v,vector<int>w,int N,int W){
    vector<int>curr(W+1);
    vector<int>prev(W+1);
    for(int i=w[0];i<=W;i++){
if(w[0]<=W){
    prev[i]=v[0];
}
else{
    prev[i]=0;
}
    }
        for(int i=1;i<=N;i++){
         for(int j=0;j<=W;j++){
            int incl=0;