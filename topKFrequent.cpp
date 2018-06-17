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

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;

        for (int i=0; i< nums.size(); i++){
            if (hashmap.count(nums[i])>0){//
                hashmap[nums[i]]++;
            }else hashmap[nums[i]]=1;
        }


        vector<pair<int,int>> vecpairtemp;
        for (unordered_map<int,int>::iterator it=hashmap.begin(); it!=hashmap.end(); it++){
            vecpairtemp.push_back(make_pair(it->second, it->first));
        }


        sort(vecpairtemp.begin(), vecpairtemp.end());

        vector <int> result;
        for (int i=vecpairtemp.size()-1; i>vecpairtemp.size()-k-1; i--){
            result.push_back(vecpairtemp[i].second);
        }
        return result;
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

int stringToInteger(string input) {
    return stoi(input);
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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}