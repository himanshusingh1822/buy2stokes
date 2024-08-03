#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edge(n);
   for(int i=0;i<n;i++){
        int follower,following,timee;
        cin >> follower >> following >> timee;
        edge[i].push_back(follower);
        edge[i].push_back(following);
        edge[i].push_back(timee);
   }
   int a,b;
   cin >> a >> b;
   vector<pair<int,int>> p1,p2;
   int ans = INT_MAX;
   for(int i=0;i<n;i++){
       if(edge[i][0] == a && edge[i][1] == b){
           ans = edge[i][2];
       }
       if(edge[i][0] == a){
           p1.push_back({edge[i][1],edge[i][2]});
       }
       if(edge[i][1] == b){
           p2.push_back({edge[i][0],edge[i][2]});
       }
   }
   for(int i=0;i<p1.size();i++){
       for(int j=0;j<p2.size();j++){
           if(p1[i].first == p2[j].first){
               ans = min(ans,p1[i].second + p2[j].second);
           }
       }
   }
   cout << ans;

    return 0;
}
