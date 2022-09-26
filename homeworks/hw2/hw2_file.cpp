# include <iostream>

int main(){
    std::string name, dob, about_me;

    std::cout << "Please enter name...\n";
    std::getline(std::cin, name);
    std::cout << "Please enter date of birth (form of mm\\dd\\yyyy)...\n";
    std::getline(std::cin, dob);
    std::cout << "Please enter your brief bio...\n";
    std::getline(std::cin, about_me);
    std::cout << "\n";

    std::cout << "AMS562 hw2 Personal Information Collector: " << name << "\n";
    std::cout << "    " << "DOB: " << dob << std::endl;
    std::cout << "    " << "Bio: " << about_me << std::endl << "\n";
    return 0;
}