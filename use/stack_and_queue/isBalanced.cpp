

#include <cassert>
#include <stack>
#include <string>
bool isBalanced(const std::string &str) {
  std::stack<char> parens;
  for (char ch : str) {
    if (ch == '(') {
      parens.push(ch);
    } else if (ch == '{') {
      parens.push(ch);
    } else if (ch == '[') {
      parens.push(ch);
    } else {
      if (ch == ')') {
        if (parens.top() != '(')
          return false;
      } else if (ch == ']') {
        if (parens.top() != '[')
          return false;
      } else if (ch == '}') {
        if (parens.top() != '{')
          return false;
      }
      parens.pop();
    }
  }
  return parens.empty();
}

void test_isBalanced() {
  { // normal
    assert(isBalanced("{([])}") == true);
    assert(isBalanced("{}()[]") == true);
    assert(isBalanced("([]){}") == true);
  }
  { // empty
    assert(isBalanced("") == true);
  }
  { // unbalanced
    assert(isBalanced("{}{(})") == false);
    assert(isBalanced("{{(})}") == false);
    assert(isBalanced("{}{})") == false);
    assert(isBalanced("({}{}") == false);
  }
}

int main() { test_isBalanced(); }
