#include<bits/stdc++.h>
using namespace std;

typedef struct Job{
    int id;
    int dl;
    int profit;
} Job;

void solve(vector<Job>& vec,int n){
    sort(vec.begin(),vec.end(),[](Job j1,Job j2){
        return j1.dl>j2.dl;
    });
    for(int i=0;i<n;i++){
        cout<<vec[i].id<<" "<<vec[i].dl<<" "<<vec[i].profit<<endl;
    }
    int count=0;
    int i=0;
    int gmax=0;
    while(i<n){
        int j=i+1;
        int curr_max=vec[i].profit;
        while(j<n && (vec[j].dl==vec[i].dl)){
            curr_max=max(vec[j].profit,curr_max);
            cout<<"j "<<j<<" "<<vec[j].profit<<endl;
            j++;
        }
        gmax+=curr_max;
        count++;
        i=j;
    }
    cout<<count<<" "<<gmax<<endl;
    
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<Job> vec;
        for(int i=0;i<n;i++){
            int id,dl,profit;
            cin>>id;
            cin>>dl;
            cin>>profit;
            vec.push_back({id,dl,profit});
        }
        solve(vec,n);
    }
}