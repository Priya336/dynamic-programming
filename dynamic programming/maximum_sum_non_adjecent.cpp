// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
 
int sequence(vector<int>s,int N){
    if(N<0){
        return 0;
    }
 int maxi;
  int ans1=sequence(s,N-1);
  int ans2=sequence(s,N-2)+s[N];
  maxi=max(ans1,ans2);
  return maxi;
}
int memo(vector<int>s,vector<int>dp,int N){
    if(N<0){
        return 0;
    }
    if(dp[N]!=-1){
        return dp[N];
    }
  int ans1=sequence(s,N-1);
  int ans2=sequence(s,N-2)+s[N];
  dp[N]=max(ans1,ans2);
  return dp[N];
}

 int tabulation(vector<int>s){
     int N=s.size();
     vector<int>dp(N,0);
     dp[0]=s[0];
     for(int i=1;i<N;i++){
        int ans1=s[i]+dp[i-2];
        int ans2=dp[i-1];  
        cout<<ans1<<" "<<ans2<<endl;
        dp[i]=max(ans1,ans2);
      
     }
     
       
     return dp[N-1];
 }
int main() {
   int N;
   cin>>N;
   vector<int>s(N);
   for(int i=0;i<N;i++){
       cin>>s[i];
   }
//   vector<int>dp(N,-1);
//   int a= sequence(s,N-1);
//   cout<<a;
//   int b=memo(s,dp,N-1);
//   cout<<b;
   int c=tabulation(s);
   cout<<c;
    return 0;
}