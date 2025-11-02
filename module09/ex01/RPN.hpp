#pragma once
#include <stack>
#include <string>

class RPN
{

public:
    /*OCF*/
    RPN();
    RPN(const RPN &o);
    RPN &operator=(const RPN &o);
    ~RPN();

    // evaluate RPN
    bool evaluate(const std::string &s, long long &result);

private:
    std::stack<long long> _stack;

    static bool isOperator(char c);
    static bool execOperator(long long a, long long b, char op, long long &o);
};
