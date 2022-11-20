#include "array.hpp"
#include <iostream>

Array::Array(){
    this->_size = 0;
    this->_data = NULL;
}

Array::Array(const Array &other){
    this->_data = new double[this->_size];
    this->_size = other._size;
    for (unsigned int i = 0; i < this->_size ; i++){
    this->_data[i] = other._data[i];
    }
}

Array::Array(unsigned n, double v){
    this->_size = n;
    this->_data = new double[this->_size];
    for (unsigned int i = 0;i < this->_size ; i++){
    this->_data[i] = v;
    }
}

void Array::copy(const Array &rhs){}

void Array::resize(unsigned new_size, bool prsv){}

double Array::norm() const{}

double Array::sum() const{}

double Array::max() const{}

double Array::min() const{}

double Array::dot(const Array &rhs) const{}

void Array::print() const{}