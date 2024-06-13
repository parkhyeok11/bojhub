#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int si = 0, sj = 0;
    int max_i = park.size();
    int max_j = park[0].size();

    // 출발 지점 'S' 찾기
    bool found = false;
    for (int i = 0; i < max_i && !found; i++) {
        for (int j = 0; j < max_j; j++) {
            if (park[i][j] == 'S') {
                si = i;
                sj = j;
                found = true;
                break;
            }
        }
    }

    // 경로를 따라 이동
    for (const string& route : routes) {
        char direction = route[0];
        int steps = route[2] - '0'; // 문자에서 정수로 변환

        // 이동이 가능한지 확인
        bool canMove = true;
        int new_si = si, new_sj = sj;
        for (int step = 0; step < steps; step++) {
            if (direction == 'N') new_si--;
            else if (direction == 'S') new_si++;
            else if (direction == 'E') new_sj++;
            else if (direction == 'W') new_sj--;

            // 새로운 위치가 유효한지 확인
            if (new_si < 0 || new_si >= max_i || new_sj < 0 || new_sj >= max_j || park[new_si][new_sj] == 'X') {
                canMove = false;
                break;
            }
        }

        // 유효하다면 이동
        if (canMove) {
            si = new_si;
            sj = new_sj;
        }
    }

    answer.push_back(si);
    answer.push_back(sj);
    return answer;
}