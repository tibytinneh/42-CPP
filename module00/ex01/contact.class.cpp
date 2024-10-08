#include "contact.class.hpp"
#include <iostream>
#include <iomanip>


// C++ provides a default constructor, only define when I need to initialize member variables.
// Destructor is only needed when I need to release resources that will not be automatically cleaned up.
// Contact::Contact(){
// }

// Contact::~Contact(){
// }

// Getters
std::string Contact::getFirstName() const{
    return this->_first_name;
}
std::string Contact::getLastName() const{
    return this->_last_name;
}
std::string Contact::getNickname() const{
    return this->_nickname;
}
std::string Contact::getPhoneNumber() const{
    return this->_phone_number;
}
std::string Contact::getDarkestSecret() const{
    return this->_darkest_secret;
}

// Setters
void Contact::setFirstName(const std::string &first_name){
    this->_first_name = first_name;
}
void Contact::setLastName(const std::string &last_name){
    this->_last_name = last_name;
}
void Contact::setNickname(const std::string &nickname){
    this->_nickname = nickname;
}
void Contact::setPhoneNumber(const std::string &phone_number){
    this->_phone_number = phone_number;
}
void Contact::setDarkestSecret(const std::string &darkest_secret){
    this->_darkest_secret = darkest_secret;
}

bool Contact::fillContactDetails(){
    std::cout << "First name: ";
    std::getline(std::cin, this->_first_name);
    std::cout << "Last name: ";
    std::getline(std::cin, this->_last_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, this->_nickname);
    std::cout << "Phone number: ";
    std::getline(std::cin, this->_phone_number);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, this->_darkest_secret);
    return !this->_first_name.empty() && !this->_last_name.empty()
        && !this->_nickname.empty() && !this->_phone_number.empty()
        && !this->_darkest_secret.empty();
}

void Contact::displayDetails() const {
    std::cout << "First Name: " << _first_name << std::endl;
    std::cout << "Last Name: " << _last_name << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phone_number << std::endl;
    std::cout << "Darkest Secret: " << _darkest_secret << std::endl;
}


std::string Contact::getShortString(const std::string &str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

