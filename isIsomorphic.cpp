//
// Created by Yi Zhang on 6/13/18.
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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> hashmap;
        vector<int> tempvecS;
        vector<int> tempvecT;

        for (int i=0; i<s.size(); i++){
            if (hashmap.count(s[i])){
                tempvecS.push_back(hashmap[s[i]]);
            } else{
                tempvecS.push_back(i);
                hashmap[s[i]]=i;
            }
        }

        hashmap.clear();

        for (int i=0; i<t.size(); i++){
            if (hashmap.count(t[i])){
                tempvecT.push_back(hashmap[t[i]]);
            } else{
                tempvecT.push_back(i);
                hashmap[t[i]]=i;
            }
        }

        if (tempvecT.size() != tempvecS.size()) return false;
        for (int i=0; i<tempvecT.size(); i++){
            if (tempvecT[i]!=tempvecS[i]) return false;
        }
        return true;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);

        bool ret = Solution().isIsomorphic(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}