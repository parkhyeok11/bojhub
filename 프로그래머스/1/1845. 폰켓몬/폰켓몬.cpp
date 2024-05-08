#include<iostream>
#include <vector>
using namespace std;

int solution(vector<int> nums)
{   
    int answer = 0;
    int a=0;
    int num[200000]={0,};
    vector<int> check;
    int temp;
    for(int i=0;i<nums.size();i++){
        temp=nums[i];
        
        if(num[temp]<1){
        num[temp]++;
        check.push_back(temp);
        }
        
    }
    
    for(int i=0;i<check.size();i++){
        if(num[check[i]]>0) a++;
    }
    
    if((nums.size()/2)>a) answer=a;
    else answer=nums.size()/2;
    
    return answer;
}