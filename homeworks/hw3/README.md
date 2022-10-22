## README for hw3

> The homework 3 contains two parts.
> * Part I: Determine the difference between true derivative value and both finite difference method and center-difference method.
> * Part II: Determine minimal and maximal arc length of corresponding points on an unit sphere.

#### Part I
1. Sanity check whether argument count, argc, is provided. If not, exit the program and tell user which error was made.
`if(argc!=2){std::cout << "Need only one h value" << std::endl;return -1;}`
2. After getting the value of input h, by using `char* string_h = argv[1];`, check if input h is valid, `if (!(h=std::atof(string_h))){std::cout << "Invalid input h" << std::endl; return -1;}`, if h here not equals to the input value, return error, else if h is valid, print out the h for further reference.
3. Define y prime of sin(x) using finite difference method, `double yfd = (sin(pi_4+h)-sin(pi_4))/h;`, and also using center-difference method, `double ycd = (sin(pi_4+h)-sin(pi_4-h))/(2*h);`. Both methods are compared to true value of y prime of sin(x), cos(x), to determine error, `double e_yfd = cos(pi_4)-yfd;` and `double e_ycd = cos(pi_4)-ycd;`.
4. Finally, print out error made by each method.
Error for certain method:
| h value | finite diff | center-diff |   |   |
|---------|-------------|-------------|---|---|
| 10^-1   | 1           | 2           |   |   |
| 10^-2   | 3           | 4           |   |   |
| 10^-3   | 5           | 6           |   |   |