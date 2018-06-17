//
// Created by Yi Zhang on 6/13/18.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>
#include <queue>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        bool result;
        unordered_set<int> hashset;
        int sum = n;
        hashset.insert(n);

        while(true){
            sum = calcSum(sum);
            if (sum==1) return true;
            if (hashset.count(sum)) return false;
            hashset.insert(sum);
        }
    }

    int calcSum(int n){
        vector <int> vec;
        while (n/10){
            vec.push_back(n%10);
            n=n/10;
        }
        vec.push_back(n%10);

        int calcsum = 0;
        for (int num:vec){
            calcsum+=pow(num,2);
        }
        return calcsum;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        bool ret = Solution().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}