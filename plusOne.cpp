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
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int floatover = 0;

        if(digits[size-1]+1==10) {
            digits[size-1] = 0;
            floatover = 1;
        } else {
            digits[size-1]+=1;
            return digits;
        }
        if (floatover>0) {
            for (int i = size - 2; i >= 0; i--) {
                if(digits[i]+floatover==10) {
                    digits[i]=0;
                    floatover=1;
                } else {
                    digits[i]+=floatover;
                    floatover = 0;
                }
            }
        }
        if (floatover==0) return digits;
        else {
            vector <int> newdigits;
            newdigits.push_back(1);
            vector <int>::iterator it = newdigits.begin();
            newdigits.insert(it+1, digits.begin(), digits.end());
            return newdigits;
        }

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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);

        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}