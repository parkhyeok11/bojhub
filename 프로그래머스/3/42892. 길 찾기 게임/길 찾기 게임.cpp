#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int x;
    int y;
    int idx;
};

// 비교 함수 수정: y 기준 내림차순, y가 같으면 x 기준 오름차순
bool cmp(Node a, Node b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y > b.y;
}

// 이진 트리 구성 함수 수정
void Make_Binary_Tree(Node* Root, Node* Child) {
    if (Child->x < Root->x) {
        if (Root->left == NULL) {
            Root->left = Child;
        } else {
            Make_Binary_Tree(Root->left, Child);
        }
    } else {
        if (Root->right == NULL) {
            Root->right = Child;
        } else {
            Make_Binary_Tree(Root->right, Child);
        }
    }
}

// 전위 순회
void preorder(Node* Root, vector<int>& answer) {
    if (Root == NULL) return;
    answer.push_back(Root->idx);
    preorder(Root->left, answer);
    preorder(Root->right, answer);
}

// 후위 순회
void postorder(Node* Root, vector<int>& answer) {
    if (Root == NULL) return;
    postorder(Root->left, answer);
    postorder(Root->right, answer);
    answer.push_back(Root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    // Node 벡터 생성 및 인덱스 저장
    vector<Node> tree;
    for (int i = 0; i < nodeinfo.size(); ++i) {
        tree.push_back({ NULL, NULL, nodeinfo[i][0], nodeinfo[i][1], i + 1 });
    }

    // 노드 정렬
    sort(tree.begin(), tree.end(), cmp);

    // 이진 트리 구성
    Node* Root = &tree[0];
    for (int i = 1; i < tree.size(); ++i) {
        Make_Binary_Tree(Root, &tree[i]);
    }

    // 전위 순회 및 후위 순회
    vector<int> pre;
    preorder(Root, pre);
    vector<int> post;
    postorder(Root, post);

    // 결과 저장
    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}
