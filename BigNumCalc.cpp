#include "BigNumCalc.h"

BigNumCalc::BigNumCalc(){};
BigNumCalc::~BigNumCalc(){};
std::list<int> BigNumCalc::buildBigNum(std::string numString){
    std::list<int> bigNumList;
    for (char c : numString) {
        bigNumList.push_back(c - '0');
    }
    return bigNumList;
};
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    std::list<int> result;
    int carry = 0;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    while (it1 != num1.rend() || it2 != num2.rend() || carry != 0) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
            it1++;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
            it2++;
        }
        carry = sum / 10;
        sum %= 10;
        result.push_front(sum);
    }
    return result;
};
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    std::list<int> result;
    int borrow = 0;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    while (it1 != num1.rend() || it2 != num2.rend() || borrow != 0) {
        int diff = borrow;
        if (it1 != num1.rend()) {
            diff += *it1;
            it1++;
        }
        if (it2 != num2.rend()) {
            diff -= *it2;
            it2++;
        }
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
    }
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }
    return result;
};

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
    std::list<int> result;
    int carry = 0;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    while (it1 != num1.rend() || carry != 0) {
        int prod = carry;
        if (it1 != num1.rend()) {
            prod += *it1 * *it2;
            it1++;
        }
        carry = prod / 10;
        prod %= 10;
        result.push_front(prod);
    }
    return result;
};
