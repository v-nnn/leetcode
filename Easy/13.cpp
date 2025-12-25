// 13. Roman to Integer

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> romNum;
        romNum['I'] = 1;
        romNum['V'] = 5;
        romNum['X'] = 10;
        romNum['L'] = 50;
        romNum['C'] = 100;
        romNum['D'] = 500;
        romNum['M'] = 1000;

        // if romNum[i] > romNum[i+1] num += romNum[i+1] - romNum[i];

        int strSize = s.length();
        int result = 0;

        for (int i = 0; i < strSize; i++) {
            if (i < strSize - 1 && romNum[i] < romNum[i+1]) {
                result += romNum[i+1] - romNum[i];
            }
            else {
                result += romNum[i];
            }
        }
        return result;
    }
};