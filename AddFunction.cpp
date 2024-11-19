#include <string>
#include <algorithm>
#include "AddFunction.h"

std::string add(const std::string& a, const std::string& b);
std::string subtract(const std::string& a, const std::string& b);

// Function to add two numbers represented as strings
std::string add(const std::string& a, const std::string& b) {
    if (a.empty()) return b;
    if (b.empty()) return a;

    bool isNegativeA = (a[0] == '-');
    bool isNegativeB = (b[0] == '-');

    // Handle cases with negative numbers
    if (isNegativeA && isNegativeB) {
        return "-" + add(a.substr(1), b.substr(1));
    } else if (isNegativeA) {
        return subtract(b, a.substr(1));
    } else if (isNegativeB) {
        return subtract(a, b.substr(1));
    }

    // Perform addition
    std::string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i--] - '0' : 0;
        int digitB = (j >= 0) ? b[j--] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

// Function to subtract two numbers represented as strings
std::string subtract(const std::string& a, const std::string& b) {
    // Assumes a >= b for simplicity
    std::string result;
    bool isNegative = false;

    // Handle negative result case
    if (a < b) {
        isNegative = true;
        return "-" + subtract(b, a);
    }

    int i = a.size() - 1, j = b.size() - 1;
    int borrow = 0;

    while (i >= 0 || j >= 0) {
        int digitA = (i >= 0) ? a[i--] - '0' : 0;
        int digitB = (j >= 0) ? b[j--] - '0' : 0;
        int diff = digitA - digitB - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back(diff + '0');
    }

    // Remove leading zeros
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());
    return (isNegative ? "-" : "") + result;
}
