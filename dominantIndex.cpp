//
// Created by Yi Zhang on 6/9/18.
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
    int dominantIndex(vector<int>& nums) {
        int largest=0;
        int secondlargest=0;
        int count = 0;
        int largestcount = 0;

        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            if(*it > largest)
            {
                secondlargest = largest;
                largest = *it;
                largestcount = count;
            } else if (*it > secondlargest){
                secondlargest = *it;
            }
            count++;
        }

        if (largest>=secondlargest*2) return largestcount;

        return -1;
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

        int ret = Solution().dominantIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}