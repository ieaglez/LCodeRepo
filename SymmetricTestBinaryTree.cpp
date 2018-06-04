//
// Created by Yi Zhang on 6/3/18.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <stdio.h>
#include <ctype.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;

        vector<int> lmrResult = midOrderLeftTraversal(root);
        vector<int> rmlResult = midOrderRightTraversal(root);

        bool issymmetric = !compareVec(lmrResult, rmlResult);
        return issymmetric;
    }

    vector<int> midOrderLeftTraversal(TreeNode* root){
        vector<int> result;
        vector<int> leftSub;
        vector<int> rightSub;

        if (root) {

            leftSub = midOrderLeftTraversal(root->left);
            rightSub = midOrderLeftTraversal(root->right);

            result.insert(result.end(), leftSub.begin(), leftSub.end());
            result.push_back(root->val);
            result.insert(result.end(), rightSub.begin(), rightSub.end());
        }

        return result;

    }

    vector<int> midOrderRightTraversal(TreeNode* root){
        vector<int> result;
        vector<int> leftSub;
        vector<int> rightSub;

        if (root) {

            leftSub = midOrderRightTraversal(root->left);
            rightSub = midOrderRightTraversal(root->right);

            result.insert(result.end(), rightSub.begin(), rightSub.end());
            result.push_back(root->val);
            result.insert(result.end(), leftSub.begin(), leftSub.end());
        }

        return result;
    }

    bool compareVec(vector<int> left,  vector<int> right) {
        auto leftIt = left.begin();
        auto rightIt = right.begin();
        auto diff = 0;
        while (leftIt != left.end() && rightIt != right.end()) {
            if (*leftIt != *rightIt) {
                diff++;
            }
            leftIt++;
            rightIt++;
        }

        // Account for different length vector instances
        if (0 == diff && (leftIt != left.end() || rightIt != right.end())) {
            diff = 1;
        }

        return diff;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        bool ret = Solution().isSymmetric(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}