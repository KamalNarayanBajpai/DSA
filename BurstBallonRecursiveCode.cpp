#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int rec(vector<int>&num,int i,int j){
        if(i+1>=j)return 0;
        int maxi = -1e9;
        for(int k=i+1;k<j;k++){
            int cost = num[i]*num[k]*num[j];
              maxi = max(maxi, cost + rec(num,i,k)+rec(num,k,j));
        } 
        return maxi;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return rec(nums,0,nums.size()-1);
    }
};
int main(){
    Solution s;
    vector<int> num  ={3,1,5,8};
    cout<<s.maxCoins(num);
    return 0;
}