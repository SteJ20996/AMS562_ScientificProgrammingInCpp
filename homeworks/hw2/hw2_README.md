**This is the README file for homework 2.**

> Create a new branch called branch_hw2, and hw2 is done in this branch.

*Here are steps of this homework.*
1. Create a file called hw2_file.cpp, in order to code c++ homework in it, using command `touch hw2_file.cpp`.
2. Set up function `int main(){}` and initialize three strings in it, name, dob(date of birth), and bio. Command `std::string name, dob, bio;`. These are three information user need to input to go forward.
3. Friendly tips for user to input information, using `std::cout`, and store them by using  `std::getline(std::cin, ___)` (Input string on underline).
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
    std::getline(std::cin, bio);
    ```
4. Then design the output page, by using `std::cout std::endl` and use escape sequences such as`\n` to set a new line, `\t` to make a horizontal tap space.
    ```
    std::cout << "AMS562 hw2 Personal Information Collector: " << name << "\n";
    std::cout << "\t" << "DOB: " << dob << std::endl;
    std::cout << "\t" << "Bio: " << bio << std::endl << "\n";
    ```
5. After user entering all strings, the final output likes this, for example:
    ```
    AMS562 hw2 Personal Information Collector: Firstname Lastname
        DOB: 01\01\2000
        Bio: I'm a student in Stony Brook University.
    ```
   Here is all about hw2 coding part.
6. After several lines of editting, I use `git add .` and `git commit -m "__"` to commit creation and changes to the local branch. This process can be done a few times.
7. Use `git checkout main` to switch to main branch.
8. Use `git merge branch_hw2` to merge the branch_hw2 to the main, can also be followed by `--strategy-option=theirs` to merge changes in accordance with files in branch_hw2.
9. Use `git push` to push changes to the GitHub, so others can check my GitHub account for updates.
10. At last, create a pull request on GitHub, by 
    * Switch to branch_hw2,
    * Click Contribute button,
    * Click Openpull request,
    * Edit title and comment,
    * Submit the Pull Request.

That's all for the homework 2.
