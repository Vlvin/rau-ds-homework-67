

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
int evaluateRPN(const std::vector<std::string> &ops) {
  std::stack<int> st;
  for (auto &op : ops) {
    if (op.empty())
      throw std::invalid_argument("empty string");
    if (op.front() == '+') {
      if (st.size() < 2)
        throw std::invalid_argument("operation is binary");
      int a = st.top();
      st.pop();
      int b = st.top();
      st.top() = a + b;
    } else if (op.front() == '-') {
      if (st.size() < 2)
        throw std::invalid_argument("operation is binary");
      int a = st.top();
      st.pop();
      int b = st.top();
      st.top() = a - b;
    } else if (op.front() == '*') {
      if (st.size() < 2)
        throw std::invalid_argument("operation is binary");
      int a = st.top();
      st.pop();
      int b = st.top();
      st.top() = a * b;
    } else if (op.front() == '/') {
      if (st.size() < 2)
        throw std::invalid_argument("operation is binary");
      int a = st.top();
      st.pop();
      int b = st.top();
      if (b != 0)
        throw std::invalid_argument("division by zero");
      st.top() = a / b;
    } else {
      st.push(std::atoi(op.c_str()));
    }
  }
  if (st.size() != 1)
    throw std::invalid_argument("invalid expression");
  return st.top();
}

void test_evaluateRPN() {
  { // normal
    std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
    assert(evaluateRPN(expr) == 9);
  }
  { // just number
    std::vector<std::string> expr = {"2"};
    assert(evaluateRPN(expr) == 2);
  }
  { // division by zero
    bool has_dbz_err = false;
    try {
      std::vector<std::string> expr = {"2", "0", "/"};
      evaluateRPN(expr);
    } catch (std::invalid_argument &e) {
      assert(std::strcmp(e.what(), "division by zero") == 0);
      has_dbz_err = true;
    }
    assert(has_dbz_err == true);
  }
  { // not enough operands
    bool has_noe_err = false;
    try {
      std::vector<std::string> expr = {"2", "+"};
      evaluateRPN(expr);
    } catch (std::invalid_argument &) {
      has_noe_err = true;
    }
    assert(has_noe_err == true);
  }
}

int main() { test_evaluateRPN(); }
