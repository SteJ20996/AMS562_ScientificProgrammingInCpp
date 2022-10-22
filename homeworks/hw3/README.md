## README for hw3

> The homework 3 contains two parts.
> * Part I: Determine the difference between true derivative value and both finite difference method and center-difference method.
> * Part II: Determine minimal and maximal arc length of corresponding points on an unit sphere.

#### Part I
1. Sanity check whether argument count, argc, is provided. If not, exit the program and tell user which error was made.
`if(argc!=2){std::cout << "Need only one h value" << std::endl;return -1;}`
2. After getting the value of input h, by using `char* string_h = argv[1];`, check if input h is valid