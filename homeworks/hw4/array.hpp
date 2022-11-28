#ifndef _ARRAY_HPP
#define _ARRAY_HPP

#include <iostream>
#include <algorithm>

class Array {
  public:
  // default constructor
  // overwrite this one to set data and size to
  // empty status
  Array();

  // copy constructor
  // we want to perform a deep copy so that
  // each Array will own its own
  // data and copies the values of the "other"
  // hint: you need a for/while loop here
  Array(const Array &other);

  // constructor with array size and
  // the default initialization value
  explicit Array(unsigned n, double v = 0.0);

  // we want to overwrite the implicit destructor
  // so that the memory is freed!
  ~Array(){
    delete[] _data;
    this->_size = 0;
  }

  // get the length of array
  unsigned size() const{
    return this->_size;
  };

  // get the data pointer of array
  double *data(){
    return _data;
  };

  // get read-only pointer of array
  const double *data() const;

  // given a rhs Array, copy its value
  // make sure the sizes are same
  void copy(const Array &rhs);

  // reference entry "index" of the data
  double &at(unsigned index){
    return this->_data[index];
  }

  // read-only reference entry "index" of the data
  const double &at(unsigned index) const{
    return this->_data[index];
  }

  // resize the array
  // require memory allocation and deallocation
  // prsv is a flag that indicates if the user
  // wants to preserve the old values
  //
  // pseudo code:
  //   create new_data (dynamically) with size new_size
  //   if presv:
  //      copy _data to new_data with size = min(new_size, _size)
  //   free the old memory (_data)
  //   copy new_data pointer to _data
  void resize(unsigned new_size, bool prsv = true);

  // some math functions
  // L-2 norm, sum, maximum/minimum, and dot (inner) products
  double norm() const;
  double sum() const;
  double max() const;
  double min() const;
  double dot(const Array &rhs) const;

  // addition: this+rhs, return a new array
  Array add(const Array &rhs) const{
    unsigned n = std::min(this->_size, rhs.size());
    Array v(n);  // make a copy of rhs
    for(unsigned int i = 0; i < n; i++){
      v._data[i] = this->_data[i] + rhs._data[i];
    }
    return v;
  };

  // subtraction: this-rhs, return a new array
  Array sub(const Array &rhs) const{
    unsigned n = std::min(this->_size, rhs.size());
    Array v(n);  // make a copy of rhs
    for(unsigned int i = 0; i < n; i++){
      v._data[i] = this->_data[i] - rhs._data[i];
    }
    return v;
  };

  // do some terminal printing
  void print() const;

  // operators

  // accessing operator
  double &      operator[](const unsigned index);
  const double &operator[](const unsigned index) const{
    return this->at(index);
  }

  // assignment, hint call resize if other and "this" have difference sizes
  Array &operator=(const Array &other){
    resize(other.size());
    copy(other);
    return *this;
  }

  // addition of two arrays
  friend Array operator+(const Array &lhs, const Array &rhs){
    return lhs.add(rhs);
  }

  // subtraction of two arrays
  friend Array operator-(const Array &lhs, const Array &rhs){
    return lhs.sub(rhs);
  }
 private:
  double * _data;  ///< data pointer
  unsigned _size;  ///< length of the array
};

// free functions

#endif