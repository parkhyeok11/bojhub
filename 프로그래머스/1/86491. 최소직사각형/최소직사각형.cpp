#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int x=0;
    int y=0;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0]<sizes[i][1]){
            int temp=sizes[i][0];
            sizes[i][0]=sizes[i][1];
            sizes[i][1]=temp;
        }
    x=(sizes[i][0]>x)? sizes[i][0]:x;
    y=(sizes[i][1]>y)? sizes[i][1]:y;
    }
    answer= x*y;
    return answer;
}