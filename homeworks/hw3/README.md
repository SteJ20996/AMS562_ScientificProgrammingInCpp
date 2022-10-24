## README for hw3

> The homework 3 contains two parts.
> * Part I: Determine the difference between true derivative value and both finite difference method and center-difference method.
> * Part II: Determine minimal and maximal arc length of corresponding points on an unit sphere.

#### Part I

1. Sanity check whether argument count, argc, is provided. If not, exit the program and tell user which error was made.
`if(argc!=2){std::cout << "Need only one h value" << std::endl;return -1;}`.

2. After getting the value of input h, by using 
`char* string_h = argv[1];`, 
check if input h is valid, 
`if(!(h=std::atof(string_h))){std::cout << "Invalid input h" << std::endl; return -1;}`, 
if h here not equals to the input value, return error, else if h is valid, print out the h for further reference.

3. Define y prime of sin(x) using finite difference method, 
`double yfd = (sin(pi_4+h)-sin(pi_4))/h;`, 
and also using center-difference method, 
`double ycd = (sin(pi_4+h)-sin(pi_4-h))/(2*h);`. 
Both methods are compared to true value of y prime of sin(x), cos(x), to determine error, 
`double e_yfd = cos(pi_4)-yfd;` and 
`double e_ycd = cos(pi_4)-ycd;`.

4. Finally, print out values and error made by each method.
Tips for running: First run program, then enter for example 
`./hw3_diff 1e-3` in the same directory as hw3_diff.cpp file, the answer will be shown.

Error for certain methods at certain h:

```
h value: finite diff, center-diff, (cos - finite diff), (cos - center-diff)
10^-1: 0.670603, 0.705929, 0.0365038, 0.00117792
10^-2: 0.703559, 0.707095, 0.00354729, 1.17851e-05
10^-3: 0.706753, 0.707107, 0.000353671, 1.17851e-07
10^-4: 0.707071, 0.707107, 3.53565e-05, 1.17859e-09
10^-16: 1.11022, 0.555112, -0.403116, 0.151995
```

#### Part II

1. The same as in part I, sanity check whether argument count, argc, is provided. If not, exit the program and tell user which error was made.
`if(argc!=2){std::cout << "Need only one argument" << std::endl;return -1;}`.

2. Define upper bound and lower bound for all random arc, and set iteration number N the same as the user input in.
`double ub = 0;`
`double lb = std::numeric_limits<double>::infinity();`
`int N = std::atof(argv[1]);`
Here if N <= 1, exit program, because need at least two points to compare max and min arc length.

3. Set three float pointers
`float *x = nullptr, *y = nullptr, *z = nullptr;`
and allocate memory for each pointer
`x = new float [N];`
`y = new float [N];`
`z = new float [N];`

4. Create two strings ma and mi to storage point coordinates corresponding to max and min arc length. Then set up a for loop, for every iteration, not reach N, use void function genPointsOnUnitSphere below this main function, to generate random points on unit sphere. Since the second iteration, calculate arc length between this point to the original point (x[0],y[0],z[0]), update upper bound and lower bound when reach conditions.

```
for(int i = 0; i < N; i++){ // exact N iterations
    genPointsOnUnitSphere(N, x, y, z);
    if(i >= 1){
        double arc = acos(x[i] * x[0] + y[i] * y[0] + z[i] * z[0]);
        if(ub < arc){
          ma = floatToString(x[i], y[i], z[i]);
          ub = arc;
        }
        if(lb > arc){
          mi = floatToString(x[i], y[i], z[i]);
          lb = arc;
        }
    }
}
```

5. After the for loop, print out N number, max&min point coordinate and max&min arc length.

```
std::cout << "When iteration count is: " << N << std::endl;
std::cout << "The first point is: " << floatToString(x[0], y[0], z[0]) << std::endl;
std::cout << "The max-arc point is: " << ma << std::endl;
std::cout << "The min-arc point is: " << mi << std::endl;
std::cout << "Max arc is: " << ub << std::endl;
std::cout << "Min arc is: " << lb << std::endl;
```

6. delete memory and exit program.

```
delete [] x;
delete [] y;
delete [] z;
```

6. Tips for running: First run program, then enter for example 
`./hw3_arc 20` in the same directory as hw3_arc.cpp file, the answer will be shown.
Because outputs are totally random, here is one output of running:

```
When iteration count is: 20
The first point is: (-0.323602, 0.897656, 0.299159)
The max-arc point is: (0.135285, -0.989109, -0.057972)
The min-arc point is: (-0.547060, 0.835078, 0.058053)
Max arc is: 2.82085
Min arc is: 0.336217
```