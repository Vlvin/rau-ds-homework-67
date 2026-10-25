

#include <cassert>
#include <stack>
#include <string>
void reverseString(std::string &str) {
  std::stack<char> ststr;
  for (int i = 0; i < str.size(); i++) {
    ststr.push(str[i]);
  }
  for (int i = 0; ststr.size() != 0 && i < str.size(); i++) {
    str[i] = ststr.top();
    ststr.pop();
  }
}

void test_reverseString() {
  { // non-empty
    std::string even = "123456";
    reverseString(even);
    assert(even == "654321");
    std::string odd = "12345";
    reverseString(odd);
    assert(odd == "54321");
    std::string palyndrome = "12321";
    reverseString(palyndrome);
    assert(palyndrome == "12321");
  }
  { // empty
    std::string str = "";
    reverseString(str);
    assert(str == "");
  }
}

int main() {
  test_reverseString();
}
