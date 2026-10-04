

#include "common.h"
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <stdexcept>
template <typename T, size_t M, size_t N> class Matrix {
public:
  constexpr static size_t ROWS = M;
  constexpr static size_t COLS = N;
  Matrix() {}
  Matrix(const std::initializer_list<std::initializer_list<T>> &list) {
    int i = 0;
    for (auto &row : list) {
      int j = 0;
      for (auto &elem : row) {
        validate(i, j);
        data[i][j] = elem;
        j++;
      }
      i++;
    }
  }
  void set(int row, int col, const T &value) {
    validate(row, col);
    data[row][col] = value;
  }
  T &get(int row, int col) {
    validate(row, col);
    return data[row][col];
  }
  const T &get(int row, int col) const {
    validate(row, col);
    return data[row][col];
  }
  void print() {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        std::cout << data[i][j] << ' ';
      }
      std::cout << std::endl;
    }
  }
  Matrix<T, M, N> operator+(const Matrix<T, M, N> &other) const {
    Matrix<T, M, N> ret;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        ret.set(i, j, get(i, j) + other.get(i, j));
      }
    }
    return ret;
  }

private:
  void validate(int row, int col) const {
    if (row < 0 || M <= row || col < 0 || N <= col)
      throw std::invalid_argument("Matrix has size " + std::to_string(N) + "x" +
                                  std::to_string(M));
  }
  T data[M][N];
};

void test_Matrix() {
  TEST(Matrix int, {
    Matrix<int, 3, 4> mat({
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
    });
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, mat.print());
      assert(ss.str() == "1 2 3 4 \n"
                         "1 2 3 4 \n"
                         "1 2 3 4 \n");
    }
    // mat.print();
    Matrix<int, 3, 4> mat2({
        {5, 6, 7, 8},
        {5, 6, 7, 8},
        {5, 6, 7, 8},
    });
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, mat2.print());
      assert(ss.str() == "5 6 7 8 \n"
                         "5 6 7 8 \n"
                         "5 6 7 8 \n");
    }
    // mat2.print();
    // (mat + mat2).print();
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, (mat + mat2).print());
      assert(ss.str() == "6 8 10 12 \n"
                         "6 8 10 12 \n"
                         "6 8 10 12 \n");
    }
  });
  TEST(Matrix double, {
    Matrix<double, 3, 4> mat({
        {1.1, 2.2, 3.3, 4.4},
        {1.1, 2.2, 3.3, 4.4},
        {1.1, 2.2, 3.3, 4.4},
    });
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, mat.print());
      assert(ss.str() == "1.1 2.2 3.3 4.4 \n"
                         "1.1 2.2 3.3 4.4 \n"
                         "1.1 2.2 3.3 4.4 \n");
    }
    Matrix<double, 3, 4> mat2({
        {5.5, 6.6, 7.7, 8.8},
        {5.5, 6.6, 7.7, 8.8},
        {5.5, 6.6, 7.7, 8.8},
    });
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, mat2.print());
      assert(ss.str() == "5.5 6.6 7.7 8.8 \n"
                         "5.5 6.6 7.7 8.8 \n"
                         "5.5 6.6 7.7 8.8 \n");
    }
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, (mat + mat2).print());
      assert(ss.str() == "6.6 8.8 11 13.2 \n"
                         "6.6 8.8 11 13.2 \n"
                         "6.6 8.8 11 13.2 \n");
    }
  });
  TEST(Matrix string, {
    Matrix<std::string, 3, 4> mat({
        {"1.1", "2.2", "3.3", "4.4"},
        {"1.1", "2.2", "3.3", "4.4"},
        {"1.1", "2.2", "3.3", "4.4"},
    });
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, mat.print());
      assert(ss.str() == "1.1 2.2 3.3 4.4 \n"
                         "1.1 2.2 3.3 4.4 \n"
                         "1.1 2.2 3.3 4.4 \n");
    }

    Matrix<std::string, 3, 4> mat2({
        {"5.5", "6.6", "7.7", "8.8"},
        {"5.5", "6.6", "7.7", "8.8"},
        {"5.5", "6.6", "7.7", "8.8"},
    });
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, mat2.print());
      assert(ss.str() == "5.5 6.6 7.7 8.8 \n"
                         "5.5 6.6 7.7 8.8 \n"
                         "5.5 6.6 7.7 8.8 \n");
    }
    {
      std::stringstream ss;
      CAPTURE_COUT(ss, (mat + mat2).print());
      assert(ss.str() == "1.15.5 2.26.6 3.37.7 4.48.8 \n"
                         "1.15.5 2.26.6 3.37.7 4.48.8 \n"
                         "1.15.5 2.26.6 3.37.7 4.48.8 \n");
    }
  });
}

int main() { test_Matrix(); }
