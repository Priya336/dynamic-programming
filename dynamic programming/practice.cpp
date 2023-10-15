#include<bits/stdc++.h>
using namespace std;
int temp(string s1,string s2){
    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
for(int i=s1.length()-1;i>=0;i--){
    for(int j=s2.length()-1;j>=0;j--){
        int ans=0;
       
       if(s1[i]==s2[j]){
      ans=1+dp[i+1][j+1]; 
}
else if(s1[i]!=s2[j]){
 ans= max(dp[i+1][j],dp[i][j+1]);
    }
    dp[i][j]=ans;
}
}
 return  dp[0][0];
}

int main(){
   string s1,s2;
   cin>>s1>>s2;
   int c=temp(s1,s2);
   cout<<c;
   return 0;
}