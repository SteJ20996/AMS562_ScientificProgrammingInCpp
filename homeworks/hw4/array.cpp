#include "array.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>

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
    for (unsigned int i = 0; i < this->_size ; i++){
        this->_data[i] = v;
    }
}

void Array::copy(const Array &rhs){
    if (this->_size != rhs._size){
        Array::resize(rhs._size);
    }
    for(unsigned int i = 0; i < rhs._size; i++){
        this->_data[i] = rhs._data[i];
    }
}

void Array::resize(unsigned new_size, bool prsv){
    double *new_data = nullptr;
    new_data = new double[new_size];
    int mi = std::min(this->_size,new_size);
    if(prsv){
        for(int i = 0;i < mi; i++){
            new_data[i] = this->_data[i];
        }
        Array::~Array();
        this->_size = new_size;
        this->_data = new_data;
    }
}

double Array::norm() const{
    double norm = 0;
    for(unsigned int i = 0; i < this->_size; i++){
        norm = norm + this->_data[i] * this->_data[i];
    }
    return pow(norm,0.5);
}

double Array::sum() const{
    double sum = 0;
    for(unsigned int i = 0; i < this->_size; i++){
        sum = sum + this->_data[i];
    }
    return sum;
}

double Array::max() const{
    double ma = this->_data[0];
    for(unsigned int i = 1;i < this->_size; i++){
        ma = std::max(ma,this->_data[i]);
    }
    return ma;
}

double Array::min() const{
    double mi = this->_data[0];
    for(unsigned int i = 1; i < this->_size; i++){
        mi = std::min(mi,this->_data[i]);
    }
    return mi;
}

double Array::dot(const Array &rhs) const{
    double prod = 0;
    for(unsigned int i = 0; i < this->_size; i++){
        prod = prod + this->_data[i] + rhs._data[i];
    }
    return prod;
}

void Array::print() const{
    std::cout << "Size of the array is: " << Array::size() << std::endl;
    std::cout << "The array's norm is: " << Array::norm() << std::endl;
    std::cout << "The array's sum is: " << Array::sum() << std::endl;
    std::cout << "The Maximum value of the array is: " << Array::max() << std::endl;
    std::cout << "The Minimum value of the array is: " << Array::min() << std::endl;
}