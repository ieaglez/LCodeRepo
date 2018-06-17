//
// Created by Yi Zhang on 6/15/18.
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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result=0;
        unordered_map<int, int> hashmap;


        for (int i=0;i<A.size();i++){
            for (int j=0; j<B.size(); j++){
                if (hashmap.count(A[i]+B[j])>0) hashmap[A[i]+B[j]]++;
                else hashmap[A[i]+B[j]]=1;
            }
        }

        for (int k=0; k<C.size(); k++){
            for (int l=0; l<D.size(); l++){
                if(hashmap.count(-(C[k]+D[l]))>0){
                    result+=hashmap[-(C[k]+D[l])];
                }
            }
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> C = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> D = stringToIntegerVector(line);

        int ret = Solution().fourSumCount(A, B, C, D);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}