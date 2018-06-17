//
// Created by Yi Zhang on 6/16/18.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stdio.h>
#include <ctype.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL) return false;
        int n=0; //length of the linked list
        ListNode* it=head;
        while (it){
            it=it->next;
            n++;
        }

        if (n==1) return true;
        if (n==2) {
            if (head->val == head->next->val) return true;
            return false;
        }
        if (n==3){
            if (head->val == head->next->next->val) return true;
            return false;
        }
        //go to the middle point
        it = head->next; //start from the second node;
        ListNode* temp1=head;
        ListNode* temp2=head;
        for (int i=1; i<=n/2-1; i++){
            temp1=it;
            it=it->next;
            temp1->next=temp2; // reverse...
            temp2=temp1;
        }
        head->next = NULL;

        ListNode* firsthalf=temp1;//last one of the first half
        ListNode* secondhalf;
        if (n%2){
            secondhalf=it->next;
        }else secondhalf=it;

        while (firsthalf){
            if (firsthalf->val!=secondhalf->val)
                return false;
            firsthalf=firsthalf->next;
            secondhalf=secondhalf->next;
        }

        return true;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);

        bool ret = Solution().isPalindrome(head);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}