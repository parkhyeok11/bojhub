#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    int temp = 0;

    for (int i = 0; i < name.size(); i++) {
        m.insert({ name[i], yearning[i] });
    }

    for (int i = 0; i < photo.size(); i++) {
        for (int j = 0; j < photo[i].size(); j++) {
            if (m.find(photo[i][j]) == m.end());
            else temp += m.find(photo[i][j])->second;
        }
        answer.push_back(temp);
        temp = 0;
    }
    return answer;
}