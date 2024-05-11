#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int begin = 0;
    int end = 0;
    int find = 0;

    for (int j = 0; j < commands.size(); j++) {
        vector<int> temp;
        begin = commands[j][0];
        end = commands[j][1];
        find = commands[j][2];

        for (int i = begin - 1; i < end; i++) {
            temp.push_back(array[i]);
        }

        sort(temp.begin(), temp.end());
        answer.push_back(temp[find - 1]);
    }
    return answer;
}