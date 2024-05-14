#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> ti;
    int ttemp = 1;
    ti.push(0);
    for (int i = 1; i < prices.size()-1; i++) {
        while (!ti.empty() && prices[ti.top()] > prices[i]) {
            answer[ti.top()] = i - ti.top();
            ti.pop();
        }
        ti.push(i);
    }

    while (!ti.empty()) {
        answer[ti.top()] = prices.size() - 1 - ti.top();
        ti.pop();
    }
    return answer;
}