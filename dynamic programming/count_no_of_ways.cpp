// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>
// recursion 
int count(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int total=count(n-1)+count(n-2);
    return total;
}
//memorization
int memo(int n,vector<int>dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    
     dp[n]=memo(n-1,dp)+memo(n-2,dp);
    return dp[n];
        
}

//tabulation 
int tab(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main() {
   int stair;
   cin>>stair;
   //int a=count(stair);
   //cout<<a;
vector<int>dp(stair+1,-1);
int b=memo(stair,dp);
cout<<b;
int c=tab(stair);
cout<<c;
    return 0;
}