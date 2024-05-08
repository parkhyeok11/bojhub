#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int depth;
int visit[101] = { 0, };
vector<int> dfsv;

void play(int i, vector<int> cards) {
    if (!visit[i]) {
        visit[i] = 1;
        depth = depth + 1;
        play(cards[i - 1], cards);
    }
}

int solution(vector<int> cards) {
    int answer = 0;
    int len = cards.size();

    if (len < 2) return 0;

    for (int i = 0; i < len; i++) {
        if (!visit[i + 1]) {
            depth = 1;
            visit[i + 1] = 1;
            play(cards[i], cards);
            dfsv.push_back(depth);
        }
    }
    sort(dfsv.begin(), dfsv.end(), greater<>());
    if (dfsv.size() < 2) return 0;
    answer = dfsv[0] * dfsv[1];
    return answer;
}