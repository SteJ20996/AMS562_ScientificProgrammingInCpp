# README for hw4

> The homework 4 contains 3 files: array.cpp, array.hpp, and main.cpp. The goal of this homework is to implement array.hpp and create array.cpp to realize all member functions mentioned in array.hpp.

###array.hpp

>What I need to do in this file is implementing its constructors, destructor, member functions, and free functions declared therein.

1. This part frees the memory to overwrite the implicit destructor. (line 27~30)
`~Array(){ delete[] _data; this->_size = 0;}`

2. Implement addition (line 81~88) and substraction (line 91~98) function to return a new array, these mainly determine the size of output should be equals to the smaller size if sizes of two input array are not the same.

3. Accessing operators (line 106~111), resize the arrays don't share the same length (line 114~118).

4. Finally, implement operator+ and operator- to add or substract two arrays. (line120~126)

###array.cpp