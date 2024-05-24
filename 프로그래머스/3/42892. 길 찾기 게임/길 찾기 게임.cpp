#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node* left, * right;
    int x;
    int y;
    int idx;
};

bool cmp(Node a, Node b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y > b.y;
}

void Make_Binary_Tree(Node* Root, Node* Child) {
    if (Child->x < Root->x) {
        if (Root->left == NULL) {
            Root->left = Child;
        }
        else {
            Make_Binary_Tree(Root->left, Child);
        }
    }
    else {
        if (Root->right == NULL) {
            Root->right = Child;
        }
        else {
            Make_Binary_Tree(Root->right, Child);
        }
    }
}

void preorder(Node* Root, vector<int>& answer) {
    if (Root == NULL) return;
    answer.push_back(Root->idx);
    preorder(Root->left, answer);
    preorder(Root->right, answer);
}

void postorder(Node* Root, vector<int>& answer) {
    if (Root == NULL) return;
    postorder(Root->left, answer);
    postorder(Root->right, answer);
    answer.push_back(Root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    // 인덱스를 기억하기 위해 (값, 인덱스) 쌍으로 저장
    vector<pair<vector<int>, int>> nodeinfo_with_index;
    for (int i = 0; i < nodeinfo.size(); ++i) {
        nodeinfo_with_index.push_back({ nodeinfo[i], i });
    }

    vector<Node> tree;

    for (const auto& node : nodeinfo_with_index) {
        int x = node.first[0];
        int y = node.first[1];
        int idx = node.second+1;
        tree.push_back({ NULL,NULL,x,y,idx });
    }
    sort(tree.begin(),tree.end(), cmp);
    Node* Root = &tree[0];
    for (int i = 1; i < tree.size(); i++) Make_Binary_Tree(Root, &tree[i]);
    vector<int> pre;
    preorder(Root, pre);
    vector<int> post;
    postorder(Root, post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}