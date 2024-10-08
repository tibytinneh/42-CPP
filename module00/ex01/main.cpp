/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <aang-shu.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 05:39:50 by aang-shu          #+#    #+#             */
/*   Updated: 2024/10/08 19:02:36 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include <iostream>
#include <string>

enum input_code {
    ADD,
    SEARCH,
    EXIT,
    INVALID
};

input_code indexify(std::string input) {
    if (input == "ADD") return ADD;
    if (input == "SEARCH") return SEARCH;
    if (input == "EXIT") return EXIT;
    return INVALID;
}

/**
 * @brief converts string to uppercase.
 * 
 * static_cast<char> explicitly converts the int returned by std::toupper back into a char
 *
 * @param str string to convert. `&` reference allows the function to modify the original variable passed to it directly
 * @return returns a reference to the modified string
 */
std::string& strToUpperCase(std::string& str)
{
    for(std::size_t i = 0; str[i] != '\0'; i++){
        str[i] = static_cast<char>(std::toupper(str[i]));
    }
    return str;
}



int main(){
    Phonebook phonebook;
    std::string input;

    while (true) {
        std::cout << "Input: [ADD] [SEARCH] [EXIT]\n";
     //Check for std::cin failure && EOF condition (Ctrl+D on Linux/macOS, Ctrl+Z on windows)
     if(!std::getline(std::cin, input))
     {
         if (std::cin.eof()){ //EOF
             std::cout << "u rlly needa test eof for what a bit overkill leh ok bye" << std::endl;
             break;
         }
         else {
            std::cin.clear(); //clear error flag after invalid input
            std::cout << "Input error occured, please try again" << std::endl;
            continue;
         }
     };

     switch(indexify(strToUpperCase(input))){
         case ADD:
             phonebook.addContact();
             break;
         case SEARCH:
             phonebook.searchContact();
                break;
          case EXIT:
             std::cout << "SELAMAT SAYONARA" << std::endl;
                 return 0;
         default:
             std::cout << "Invalid input my good sir." << std::endl;
        }
    }
    return 0;
}