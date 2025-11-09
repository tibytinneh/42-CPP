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

/**
 * Check whether a character is a supported operator.
 *
 * Supported operators: '+', '-', '*', '/'.
 *
 * @param {char} c - character to test
 * @return {bool} true when c is a supported operator
 */
bool RPN::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

/**
 * Execute binary operator on two operands.
 *
 * Performs (a op b). For division, returns false on division by zero.
 *
 * @param {long long} a - left operand
 * @param {long long} b - right operand
 * @param {char} op - operator char ('+','-','*','/')
 * @param {long long&} o - out parameter receiving result
 * @return {bool} true on success, false on error (e.g. div by zero or unknown op)
 */
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

/**
 * Evaluate a space-separated RPN expression.
 *
 * Tokens are decimal single-digit operands or single-char operators.
 * The function resets internal stack, processes tokens left-to-right,
 * and leaves the final result in `result` when successful.
 *
 * @param {const std::string&} s - input expression (tokens separated by spaces)
 * @param {long long&} result - receives computed value on success
 * @return {bool} true on successful evaluation, false on error (invalid token, stack underflow, div by zero, leftover items)
 */
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