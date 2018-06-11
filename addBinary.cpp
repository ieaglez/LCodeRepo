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
    string addBinary(string a, string b) {
        int sizeA = a.length();
        int sizeB = b.length();

        int longerAB = (sizeA>sizeB?0:1); //0 a is longer, 1 b is longer;

        int itA = sizeA-1;
        int itB = sizeB-1;
        int addone = 0;
        string newstring;
        for (int i=max(sizeA, sizeB)-1; i>abs(sizeA-sizeB)-1; i--){
            if (addone>0){ //add one from the last calc
                if (a[itA]==b[itB]) {
                    newstring.insert(0, "1");
                    if (a[itA] == '1') {
                        addone = 1;
                    } else {
                        addone = 0;
                    }
                } else {
                    newstring.insert(0,"0");
                    addone=1;
                }
            } else{
                if (a[itA] == b[itB]) {
                    newstring.insert(0,"0");
                    if (a[itA]=='1'){
                        addone=1;
                    } else {
                        addone = 0;
                    }
                } else {
                    newstring.insert(0,"1");
                    addone=0;
                }
            }
            itA--;
            itB--;
        }

        if (longerAB >0) {//b is longer
            for (int i=(sizeB-sizeA)-1; i>=0; i--){
                if (addone>0){
                    if (b[i] == '1'){
                        addone=1;
                        newstring.insert(0,"0");
                    } else {
                        newstring.insert(0,"1");
                        addone=0;
                    }
                } else{
                    if (b[i]=='1') {
                        newstring.insert(0, "1");
                    }
                    else newstring.insert(0, "0");
                }
            }
        } else {//a is longer
            for (int i=(sizeA-sizeB)-1; i>=0; i--){
                if (addone>0){
                    if (a[i] == '1'){
                        addone=1;
                        newstring.insert(0,"0");
                    } else {
                        newstring.insert(0,"1");
                        addone=0;
                    }
                } else{
                    if (a[i]=='1') {
                        newstring.insert(0, "1");
                    }
                    else newstring.insert(0, "0");
                }
            }
        }
        if (addone>0) newstring.insert(0,"1");
        return newstring;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}