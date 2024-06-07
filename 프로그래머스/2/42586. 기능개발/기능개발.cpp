#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int dayOfend[100]={0,};
    int day = -1;
    for (int i = 0; i < progresses.size(); i++) {
        while (progresses[i] + (day * speeds[i]) < 100) {
            day++;
        }
        dayOfend[day]++;
    }
    for (int i = 0; i <= day; i++) {
        if (dayOfend[i] > 0) answer.push_back(dayOfend[i]);
    }
    return answer;
}