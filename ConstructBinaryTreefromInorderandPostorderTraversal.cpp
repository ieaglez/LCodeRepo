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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // start from the last item in postorder
        // then constructure left tree using the vector left to the last time in inorder
        // then constructure right tree using
        // TreeNode* root = new TreeNode(stoi(item));

        if (inorder.size() == 0 || postorder.size()==0) return NULL;

        int root_val = postorder.back();
        TreeNode* root = new TreeNode(root_val);

        vector<int> lInorder;
        vector<int> rInorder;

        int temp_lrInorder = 0;
        for (vector<int>::iterator it = inorder.begin(); it!= inorder.end(); ++it){
            if (*it==root_val) {
                temp_lrInorder = 1;
            }
            else if (temp_lrInorder == 0) {
                lInorder.push_back(*it);
            } else
            {
                rInorder.push_back(*it);
            }
        }

        vector<int> lPostOrder;
        vector<int> rPostOrder;
        for (vector<int>::iterator it = postorder.begin(); it!=postorder.end(); ++it){
            if (*it!=root_val) {
                int lor = 1; //0 left, 1 right
                for (vector<int>::iterator iit=lInorder.begin(); iit!=lInorder.end();++iit){
                    if (*it==*iit)
                    {
                        lor = 0;
                        break;
                    }
                }

                if (lor>0) //right
                {
                    rPostOrder.push_back(*it);
                } else
                {
                    lPostOrder.push_back(*it);
                }
            }
        }

        //build left tree
        root->left = buildTree(lInorder, lPostOrder);

        //build right tree
        root->right = buildTree(rInorder, rPostOrder);

        return root;
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> inorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> postorder = stringToIntegerVector(line);

        TreeNode* ret = Solution().buildTree(inorder, postorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}