

#include "common.h"
#include <cassert>
#include <cstddef>
#include <iostream>
#include <sstream>
template <typename T> class Range {
public:
  Range(const T &start, const T &end) : _start(start), _end(end) {}
  bool contains(const T &val) const { return (_start <= val && val < _end); }
  T length() const { return _end - _start; }
  void print() {
    std::cout << '[' << _start << ';' << _end << ')';
  }

private:
  T _start;
  T _end;
};

void test_Range() {
  TEST(Range int, {
    Range<int> range(3, 10);
    std::stringstream ss;
    auto origcout = std::cout.rdbuf(ss.rdbuf());
    range.print();
    std::cout.rdbuf(origcout);
    assert(ss.str() == "[3;10)");

    assert(range.length() == 10-3);
    assert(range.contains(4));
    assert(!range.contains(10));
  });
  TEST(Range double, {
    Range<double> range(3.3, 10.1);
    // range.print();
    std::stringstream ss;
    auto origcout = std::cout.rdbuf(ss.rdbuf());
    range.print();
    std::cout.rdbuf(origcout);
    assert(ss.str() == "[3.3;10.1)");
    assert(range.length() == 10.1-3.3);
    assert(range.contains(4.4));
    assert(!range.contains(10.1));
  });
  TEST(Range char, {
    Range<char> range('a', 'f');
    // range.print();
    std::stringstream ss;
    auto origcout = std::cout.rdbuf(ss.rdbuf());
    range.print();
    std::cout.rdbuf(origcout);
    assert(ss.str() == "[a;f)");
    assert(range.length() == 'f'-'a');
    assert(range.contains('b'));
    assert(!range.contains('z'));
  });
}

int main() {
  test_Range();
}
