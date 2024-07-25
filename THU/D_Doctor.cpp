//
// Created by HUAWEI on 2024/7/21.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node{
    int me;
    int num=0;
    vector<int> connect;
    int people;
    map<int,int> my_map;
};

void write(int a,const vector<vector<int>>& vec,node& now,int n,vector<map<int,int>>& m){
    if(now.num=a=1&&now.me!=1){
        now.my_map
    }
}

int main(){
    int n;
    cin>>n;
    node arr[n+1];
    for(int i=1;i<=n;i++){
        arr[i].me=i;
        cin>>arr[i].people;
    }
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        arr[a].connect.push_back(b);
        arr[a].num++;
        arr[b].connect.push_back(a);
        arr[b].num++;
    }

}