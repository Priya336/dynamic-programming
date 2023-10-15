#include<bits/stdc++.h>
using namespace std;

int value(vector<int>days,vector<int>cost,int N){
    if(N<0){
        return INT_MAX;
    }
    if(N==0){
        return min(cost[0],min(cost[1],cost[2]));
    }

    int ans1=value(days,cost,N-1)+cost[0];
    int ans2=INT_MAX;
    for(int i=N;i>=0;i--){
     
        if(days[i]<=(days[N]-7) &&( days[N]-7>0)){
          ans2=value(days,cost,i)+cost[1];
          break;
        }
        else{
            if(days[N]-7<=0){
                ans2=cost[1];
                break;
            }
        }
    }
     int ans3=INT_MAX;
     for(int i=N;i>=0;i--){
        if(days[i]<=(days[N]-30) && days[N]-30>0){
          ans3=value(days,cost,i)+cost[2];
          break;
        }
         else{
            if(days[N]-30<=0){
                ans3=cost[2];
                break;
            }
        }
    }
    
    int ans=min(ans1,min(ans2,ans3));
    cout<<ans<<endl;
    return ans;
}
int memo(vector<int>days,vector<int>cost,vector<int>dp,int N){
      if(N<0){
        return INT_MAX;
    }
    if(N==0){
        return min(cost[0],min(cost[1],cost[2]));
    }
    if(dp[N]!=-1){
        return dp[N];
    }
    
    int ans1=value(days,cost,N-1)+cost[0];
    int ans2=INT_MAX;
    for(int i=N;i>=0;i--){
     
        if(days[i]<=(days[N]-7) &&( days[N]-7>0)){
          ans2=value(days,cost,i)+cost[1];
          break;
        }
        else{
            if(days[N]-7<=0){
                ans2=cost[1];
                break;
            }
        }
    }
     int ans3=INT_MAX;
     for(int i=N;i>=0;i--){
        if(days[i]<=(days[N]-30) && days[N]-30>0){
          ans3=value(days,cost,i)+cost[2];
          break;
        }
         else{
            if(days[N]-30<=0){
                ans3=cost[2];
                break;
            }
        }
    }
      dp[N]=min(ans1,min(ans2,ans3));
   
    return dp[N];
    
}

int tabulation(vector<int>days,vector<int>cost){
    int N=days.size();
    vector<int>dp(N);
    dp[0]=min(cost[0],min(cost[1],cost[2]));
    for(int j=1;j<N;j++){
         int ans1=dp[j-1]+cost[0];
    int ans2=INT_MAX;
    for(int i=j;i>=0;i--){
     
        if(days[i]<=(days[j]-7) &&( days[j]-7>0)){
          ans2=dp[i]+cost[1];
          break;
        }
        else{
            if(days[j]-7<=0){
                ans2=cost[1];
                break;
            }
        }
    }
     int ans3=INT_MAX;
     for(int i=j;i>=0;i--){
        if(days[i]<=(days[j]-30) && days[j]-30>0){
          ans3=dp[i]+cost[2];
          break;
        }
         else{
            if(days[j]-30<=0){
                ans3=cost[2];
                break;
            }
        }
    }
    dp[j]=min(ans1,min(ans2,ans3));
    }
    return dp[N-1];
}
int main(){
    int N;
     cin>>N;
     vector<int>days(N);
     vector<int>cost(3);
     for(int i=0;i<N;i++){
        cin>>days[i];
     }
     for(int i=0;i<3;i++){
        cin>>cost[i];
     }
    int a=value(days,cost,N-1);
     cout<<a;
     vector<int>dp(N,-1);
     int b=memo(days,cost,dp,N-1);
     cout<<b;
    return 0;
}