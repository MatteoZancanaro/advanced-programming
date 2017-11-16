#include <iostream>
#include <memory>  //smart pointers
#include <ap_error.h>

template <typename num>
class Matrix {
 public:
  Matrix(const int r, const int c) // Here is the constructor for the class Matrix.
      : rows{r}, cols{c}, _size{r * c}, elem{new num[_size]} {}

  num* operator[](const int i) noexcept { return &elem[i * cols]; }
  const num* operator[](const int i) const noexcept { return &elem[i * cols]; } // Both are needed, otherwise when we call the operator the compiler is not sure nothing is gonna be changed. This operator has to be applyed to a pointer of the num type and it is used because the matrix is defined as a long vector fo the rows are defined by dividing it into parts containing the right number of columns.

  // template <typename other_num>
  // friend class Matrix<other_num>;

  Matrix(const Matrix& m) // Here is the constructor for the copy semantic: we are overloading the constructor so if the input is an address it will copy the matrix, else if the input is composed by two integers it creates one new.
      : rows{m.rows}, cols{m.cols}, _size{m._size}, elem{new num[_size]} {
    if (m.moved)
      AP_error("cannot construct a Matrix from a moved one\n");
    for (int i = 0; i < _size; ++i)
      new (&elem[i]) num{m.elem[i]}; // This command is used for not built-in types. If inside the matrix we just want to put doubles, integers, boolean or whatelse, we can just write elem[i]=m.elem[i]. In case of not built-in types, as for example a struct, it is not doable because we first have to create a new struct of the same type (new) on the allocated space and then fill it with the desired element.
  }

  Matrix& operator=(const Matrix& m) {
<<<<<<< Updated upstream
    if (&m != this) {
      if (m.moved)
        AP_error("better not to copy from an already moved matrix\n");

      if (moved) {
        rows = m.rows;
        cols = m.cols;
        _size = m._size;
        elem.reset(new num[_size]);
        moved = false;
      }
      // check sizes
      for (int i = 0; i < _size; ++i)
        elem[i] = m.elem[i];
    }
    return *this;
=======
    // check sizes
    for (int i = 0; i < _size; ++i)
      elem[i] = m.elem[i];
    return *this; // This is a pointer to itself
>>>>>>> Stashed changes
  }

  Matrix(Matrix&& m)
      : rows{std::move(m.rows)},
        cols{std::move(m.cols)},
        _size{std::move(m._size)},
        elem{std::move(m.elem)} {
    m.moved = true;
    m.rows = m.cols = m._size = 0;
  }

  Matrix& operator=(Matrix&& m) {
    if (m.moved)
      AP_error("better not to copy from an already moved matrix\n");
    rows = std::move(m.rows);
    cols = std::move(m.cols);
    _size = std::move(m._size);
    elem = std::move(m.elem);
    m.moved = true;
    m.rows = m.cols = m._size = 0;
    return *this;
  }

  num& at(const int i, const int j) {
    range_check(i, j);
    return (*this)[i][j]; // At the first [] the input is a pointer of num type. Then this operator gives back a pointer to the first element of the right row. So the second [] has a different input and for this reason the default [] is used.
  }

  const num& at(const int i, const int j) const {
    range_check(i, j);
    //return elem[i * cols + j]; // It is the same
    return (*this)[i][j];
  }

  num& operator()(const int i, const int j) {
#ifndef NDEBUG
    return at(i, j);
#else
    return (*this)[i][j];
#endif
  }

  const num& operator()(const int i, const int j) const {
#ifndef NDEBUG
    return at(i, j);
#else
    return (*this)[i][j];
#endif
  }

  // num& operator[](int i) { return elem[i]; }
  // const num& operator[](int i) const { return elem[i]; }

  int row() const noexcept { return rows; }
  int col() const noexcept { return cols; }
  int size() const noexcept { return _size; }

 private:
  void range_check(const int i, const int j) const;
  int rows;
  int cols;
  int _size;
  std::unique_ptr<num[]> elem;

  // this boolean is set to true when another Maxtrix calls a move
  // ctor or assignment from this Matrix.
  bool moved = false;
};

template <typename num>
void Matrix<num>::range_check(const int i, const int j) const {
  if (i >= rows || j >= cols)
    AP_error("out of bound!!\n", i, j, rows, cols);
}

template <typename num>
std::ostream& operator<<(std::ostream& os, const Matrix<num>& m) {
  for (auto i = 0; i < m.row(); ++i) {
    for (auto j = 0; j < m.col(); ++j)
      os << m(i, j) << " ";
    os << std::endl;
  }
  return os;
}

int main() {
  try {
    Matrix<int> m{3, 3};
    Matrix<int> md{m};

    // int c=m.size();
    // while (c--)
    //   m[c] = c;

    int c = 0;
    for (auto i = 0; i < m.row(); ++i)
      for (auto j = 0; j < m.col(); ++j)
        m(i, j) = c++;

    md = m;

    md = md;

    std::cout << md << std::endl;

    Matrix<int> m2{std::move(m)};

    std::cout << m2 << std::endl;

    m = md;
    std::cout << m << std::endl;

    m = std::move(m2);
    md = m2;  // an exception will be thrown

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
