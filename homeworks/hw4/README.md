# README for hw4

> The homework 4 contains 3 files: array.hpp, array.cpp, and main.cpp. The goal of this homework is to implement array.hpp and create array.cpp to realize all member functions mentioned in array.hpp.

###array.hpp

> What I need to do in this file is implementing its constructors, destructor, member functions, and free functions declared therein.

1. This part frees the memory to overwrite the implicit destructor. (line 27-30)
`~Array(){ delete[] _data; this->_size = 0;}`

2. Implement addition (line 81-88) and substraction (line 91-98) function to return a new array, these mainly determine the size of output should be equals to the smaller size if sizes of two input array are not the same.

3. Accessing operators (line 106-111), resize the arrays don't share the same length (line 114-118).

4. Finally, implement operator+ and operator- to add or substract two arrays. (line120-128)

###array.cpp

> What I need to do in this file is realizing member functions in array.hpp.

1. All the functions in sequence are construct array, copy, resize, finding norm, sum, max and min of array, and doing dot product.

2. At the end, printout five properties of array.
```
Size of the array,
The array's norm,
The array's sum,
The maximum value of the array,
The minimum value of the array.
```

###main.cpp

> What I need to do in this file is creating a test function.

1. Set two array, v1 with size 200, v2 also with size 200 but its values are half of v1. Then calculate properties of v1, v2, v1+v2 and v1-v2.

2. Set v3 with size 150, and v4 with size 300, to test program in case of different sizes.

3. In the end, all properties are given true checked by me.

> Running tips: Download three files, input in terminal: `g++ main.cpp array.cpp`, then `./a.out`, all output of properties will be shown.