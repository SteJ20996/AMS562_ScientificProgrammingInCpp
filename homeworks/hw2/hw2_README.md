**This is the README file for homework 2.**

> Create a new branch called branch_hw2
> And hw2 is done in this branch

*Here are steps of this homework.*
1. Create a file called hw2_file.cpp, in order to code homework in it, using `touch hw2_file.cpp`.
2. Set up function main and three strings in it, name, dob(date of birth), and about_me. The user need to input these three information to go forward.
   `std::string name, dob, about_me;`
3. Friendly tips for user to input information, and store them by using  `std::getline`
    ```
    std::cout << "Please enter name...\n";
    std::getline(std::cin, name);
    std::cout << "Please enter date of birth (form of mm\\dd\\yyyy)...\n";
    std::getline(std::cin, dob);
    std::cout << "Please enter your brief bio...\n";
    std::getline(std::cin, about_me);
    ```
4. Finally, print out all information in certain form.

That's all for the homework 2.
