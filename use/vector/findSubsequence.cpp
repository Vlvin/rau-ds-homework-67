

#include <cassert>
#include <vector>
bool validate_subsequence(const std::vector<int> &seq, int index,
                          const std::vector<int> &subseq) {
  if (seq.size() - index < subseq.size())
    return false;
  for (int i = 0; i < subseq.size(); i++) {
    if (subseq[i] != seq[index + i])
      return false;
  }
  return true;
}

int findSubsequence(std::vector<int> &seq, std::vector<int> &subseq) {
  if (seq.size() == 0 && subseq.size() == 0) // technically contains
    return 0;
  for (int i = 0; i < seq.size() - subseq.size(); i++) {
    if (validate_subsequence(seq, i, subseq))
      return i;
  }
  return -1;
}

void test_findSubsequence() {

  { // normal has subsequence
    std::vector<int> seq = {1, 2, 3, 4, 5};
    std::vector<int> subseq = {1, 2, 3};
    int sub = findSubsequence(seq, subseq);
    assert(sub == 0);
  }
  { // normal has no subsequence
    std::vector<int> seq = {1, 2, 3, 4, 5};
    std::vector<int> subseq = {3, 2, 1};
    int sub = findSubsequence(seq, subseq);
    assert(sub == -1);
  }
  { // normal has subsequence prefix at the end
    std::vector<int> seq = {1, 2, 3, 4, 5};
    std::vector<int> subseq = {4, 5, 6};
    int sub = findSubsequence(seq, subseq);
    assert(sub == -1);
  }
  { // empty seq
    std::vector<int> seq = {};
    std::vector<int> subseq = {4, 5, 6};
    int sub = findSubsequence(seq, subseq);
    assert(sub == -1);
  }
  { // empty subseq
    std::vector<int> seq = {1, 2, 3, 4, 5};
    std::vector<int> subseq = {};
    int sub = findSubsequence(seq, subseq);
    assert(sub == 0);
  }
  { // empty seq and subseq
    std::vector<int> seq = {};
    std::vector<int> subseq = {};
    int sub = findSubsequence(seq, subseq);
    assert(sub == 0);
  }
}

int main() { test_findSubsequence(); }
