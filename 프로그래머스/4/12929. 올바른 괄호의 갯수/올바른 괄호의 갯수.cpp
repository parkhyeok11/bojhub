#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int an[15]={0,};
    an[0]=1;
    an[1]=1;
    an[2]=2;
    an[3]=5;
    
  for(int i = 4; i<=n; i++){ 
        for(int j=1; j<=i; j++){
            an[i] += an[i-j] * an[j-1]; 
        }
  }
    answer=an[n];
    return answer;
}