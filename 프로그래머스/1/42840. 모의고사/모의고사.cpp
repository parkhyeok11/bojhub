#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int temp[3] = { 0, };
    int on = 0;
    int tw = 0;
    int th = 0;
    int one[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    int two[16] = { 2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5 };
    int three[20] = { 3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5 };

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[on]) temp[0]++;
        if (answers[i] == two[tw]) temp[1]++;
        if (answers[i] == three[th]) temp[2]++;
        on++;
        tw++;
        th++;
        if (on > 9) on = 0;
        if (tw > 15) tw = 0;
        if (th > 19) th = 0;
    }

    if (temp[0] >= temp[1] && temp[0] >= temp[2]) {
        answer.push_back(1);
    }
    if (temp[1] >= temp[0] && temp[1] >= temp[2]) {
        answer.push_back(2);
    }
    if (temp[2] >= temp[0] && temp[2] >= temp[1]) {
        answer.push_back(3);
    }

    return answer;
}