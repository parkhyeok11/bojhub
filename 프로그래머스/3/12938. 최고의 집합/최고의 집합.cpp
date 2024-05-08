#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int point =s/n;
    if(point<1){
        answer.push_back(-1);
        return answer;
    }
    int temp=s%n;
    answer.assign(n,point);
    for(int i=answer.size()-1;i>=0&&temp>0;i--){
        answer[i]++;
        temp--;
    }
    return answer;
}