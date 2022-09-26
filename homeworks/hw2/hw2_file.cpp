# include <iostream>

int main(){
    std::string name, dob, bio;

    std::cout << "Please enter name...\n";
    std::getline(std::cin, name);
    std::cout << "Please enter date of birth (form of mm\\dd\\yyyy)...\n";
    std::getline(std::cin, dob);
    std::cout << "Please enter your brief bio...\n";
    std::getline(std::cin, bio);
    std::cout << "\n";

    std::cout << "AMS562 hw2 Info Collector: " << name << "\n";
    std::cout << "    " << "DOB: " << dob << std::endl;
    std::cout << "    " << "Bio: " << bio << std::endl << "\n";
    return 0;
}