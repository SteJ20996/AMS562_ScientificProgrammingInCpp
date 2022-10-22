# include <iostream>

int main(){
    std::string name, mm, dd, yyyy, bio;

    std::cout << "Please enter name...\n";
    std::getline(std::cin, name);
    std::cout << "Please enter date of birth (form of mm\\dd\\yyyy)...\n";
    std::getline(std::cin, mm);
    std::getline(std::cin, dd);
    std::getline(std::cin, yyyy);
    std::cout << "Please enter your brief bio...\n";
    std::getline(std::cin, bio);
    std::cout << "\n";

    std::cout << "AMS562 hw2 Info Collector: " << name << "\n";
    std::cout << "\t" << "DOB: " << mm << "\\" << dd << "\\" << yyyy << std::endl;
    std::cout << "\t" << "Bio: " << bio << std::endl << "\n";
    return 0;
}