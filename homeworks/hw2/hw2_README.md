**This is the README file for homework 2.**

> Create a new branch called branch_hw2, and hw2 is done in this branch.

*Here are steps of this homework.*
1. Create a file called hw2_file.cpp, in order to code homework in it, using `touch hw2_file.cpp`.
2. Set up function main and three strings in it, name, dob(date of birth), and about_me. The user need to input these three information to go forward.
   `std::string name, dob, about_me;`
3. Friendly tips for user to input information, using `std::cout`, and store them by using  `std::getline(std::cin, ___)`
    Entering name:
    ```
    std::cout << "Please enter name...\n";
    std::getline(std::cin, name);
    ```
    Entering date of birth:
    ```
    std::cout << "Please enter date of birth (form of mm\\dd\\yyyy)...\n";
    std::getline(std::cin, dob);
    ```
    Entering brief biography:
    ```
    std::cout << "Please enter your brief bio...\n";
    std::getline(std::cin, about_me);
    ```
4. Then design the output page, by using `std::cout std::endl`.
    ```
    std::cout << "AMS562 hw2 Personal Information Collector: " << name << "\n";
    std::cout << "\t" << "DOB: " << dob << std::endl;
    std::cout << "\t" << "Bio: " << about_me << std::endl << "\n";
    ```
5. After user entering all strings, the final output likes this, for example:
    ```
    AMS562 hw2 Personal Information Collector: Firstname Lastname
        DOB: 01\01\2000
        Bio: I'm a student in Stony Brook University.
    ```
6. Here is all about hw2 coding part.
7. Use `git add .` and `git commit -m "__"` to commit creation and changes to the local branch.
8. Use `git merge` to merge the branch_hw2 to the main.
9.  Use `git push` to push changes to the GitHub.

That's all for the homework 2.
