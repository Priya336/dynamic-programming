#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&v,int i,int j){
    if(j==i+1){
        return 0;
    }
    int mini=INT_MAX;
    for(int k=i+1;k<j;k++){
        mini=min(((v[i]*v[j])*v[k])+solve(v,i,k)+solve(v,k,j),mini);
    }
    
    return mini;
}
int memo(vector<int>&v,int i,int j,vector<vector<int>>dp){
     if(j==i+1){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i+1;k<j;k++){
       dp[i][j]=min(((v[i]*v[j])*v[k])+solve(v,i,k)+solve(v,k,j),mini);
    }
    
    return dp[i][j];
}
int tabulation(vector<int>v){
    int N=v.size();
  vector<vector<int>>dp(N,vector<int>(N,0));
   for(int i=N-1;i>=0;i--){
    for(int j=i+2;j<N;j++){
       int mini=INT_MAX;
    for(int k=i+1;k<j;k++){
       dp[i][j]=min(((v[i]*v[j])*v[k])+dp[i][k]+dp[k][j],mini);
    }
    }
   }
   return dp[0][N-1];
}
int main(){
    int N;
    cin>>N;
    vector<int>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    // int ans=solve(v,0,N-1);
    // cout<<ans;
    // vector<vector<int>>dp(N,vector<int>(N,-1));
    // int ans=memo(v,0,N-1,dp);
    // cout<<ans;
    int ans=tabulation(v);
    cout<<ans;
    return 0;
}