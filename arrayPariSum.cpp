//
// Created by Yi Zhang on 6/10/18.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //sort it first
        int sum=0;
        for (int i = 0; i< nums.size()-1; i++) {
            for (int j=0; j< nums.size()-i-1;  j++) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
            if ((nums.size()-i)%2 == 1) {
                sum += nums[nums.size()-i-1];
            }
        }

        sum+=nums[0];

        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout<<endl;
        //now it's sorted
        /*
        int sum = 0;
        for (int i=0; i<nums.size()-1; i++){
            sum = sum + nums[i];
            i++;
        }
         */
        return sum;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().arrayPairSum(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}