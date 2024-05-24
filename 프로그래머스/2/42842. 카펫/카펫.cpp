#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int temp=brown+yellow;
    int x=temp-1;
    for(x;x>0;x--){
        if(temp%x!=0)continue;
        
        int y=temp/x;
        int yell=(y-2)*(x-2);
        int bro=temp-yellow;
        
        if(yell==yellow&&bro==brown){
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
    }
    return answer;
}