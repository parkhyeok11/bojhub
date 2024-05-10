#include <string>
#include<iostream>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int time = 0;
    int hp = health;
    int count = 0;
    int asize = attacks.size();
    int i = 0;
    int atime = attacks[i][0];
    while (time <= attacks[asize - 1][0]) {
        if (hp < 1) break;
        if (time == atime) {
            hp = hp - attacks[i][1];
            i++;
            if (i < asize) {
                atime = attacks[i][0];
            }
            count = 0;
            time++;
            continue;
        }

        hp = hp + bandage[1];
        count++;
        if (count == bandage[0]) {
            hp = hp + bandage[2];
            count=0;
        }
        time++;

        if (hp > health) {
            hp = health;
        }

    }
    if (hp < 1) hp = -1;
    answer = hp;
    return answer;
}