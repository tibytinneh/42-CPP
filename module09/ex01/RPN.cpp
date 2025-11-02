#include "RPN.hpp"
#include <sstream>
#include <cctype>

RPN::RPN() : _stack() {}
RPN::RPN(const RPN &o) : _stack(o._stack) {}
RPN &RPN::operator=(const RPN &o)
{
    if (this != &o)
        _stack = o._stack;
    return *this;
}
RPN::~RPN() {}

//    • Your program must be able to handle operations with these tokens: "+ - / *".
bool RPN::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool RPN::execOperator(long long a, long long b, char op, long long &o)
{

    switch (op)
    {
    case '+':
        o = a + b;
        return true;
    case '-':
        o = a - b;
        return true;
    case '*':
        o = a * b;
        return true;
    case '/':
        if (b == 0)
            return false;
        o = a / b;
        return true;
    }
    return false;
}

bool RPN::evaluate(const std::string &s, long long &result)
{
    // reset stack state
    _stack = std::stack<long long>();

    // tokenize by spaces
    std::istringstream iss(s);
    std::string token;

    long long rhs;
    long long lhs;
    long long r;
    while (iss >> token)
    {
        // validate token size and isdigit
        if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            _stack.push(static_cast<long long>(token[0] - '0'));
            continue;
        }

        // validate token size and isoperator
        if (token.size() == 1 && isOperator(token[0]))
        {
            if (_stack.size() < 2)
                return false;
            rhs = _stack.top();
            _stack.pop();
            lhs = _stack.top();
            _stack.pop();
            if (!execOperator(lhs, rhs, token[0], r))
                return false;
            _stack.push(r);
            continue;
        }
        return false;
    }
    if (_stack.size() != 1)
        return false;
    result = _stack.top();
    return true;
}