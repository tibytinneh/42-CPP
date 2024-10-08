/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <aang-shu.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 05:27:33 by aang-shu          #+#    #+#             */
/*   Updated: 2024/10/08 05:27:33 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

// Constructor
// initializes the objects of the phonebook class.
Phonebook::Phonebook() : _index(0), _totalContacts(0) {}

// Add new contact to the phonebook
void Phonebook::addContact() {
    Contact newContact;

    if (newContact.fillContactDetails()){
        _contactsArr[_index] = newContact;
        _index = (_index + 1) % maxContacts;
    if (_totalContacts < 8) {
        _totalContacts++;
    }
    }
    else {
        std::cout << "Invalid: Contact details issue." << std::endl;
    }
}

// Display and search for a contact in the phone book
void Phonebook:: searchContact() const {
    if (_totalContacts == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
	// Print the contact list in table format
	// setw(10) sets the width of the next output field to 10 characters, right-aligned.
    std::cout << std::setw(10) << "Index" << "|" 
        << std::setw(10) << "First Name" << "|" 
		<< std::setw(10) << "Last Name" << "|" 
		<< std::setw(10) << "Nickname" << std::endl;
	for (std::size_t i = 0; i < _totalContacts; i++){
		std::cout << std::setw(10) << i << "|" 
   		 	<< std::setw(10) << _contactsArr[i].getShortString(_contactsArr[i].getFirstName()) << "|" 
			<< std::setw(10) << _contactsArr[i].getShortString(_contactsArr[i].getLastName()) << "|" 
        	<< std::setw(10) << _contactsArr[i].getShortString(_contactsArr[i].getNickname()) << std::endl;
	}
	// Prompt user for contact index and display details
	std::cout << "Enter the index of the contact: " << std::endl;
	std::size_t index;

	if (std::cin >> index && index <_totalContacts){
		std::cin.ignore(); // default: ignores one character (\n)
		_contactsArr[index].displayDetails();
	}
	else {
		std::cin.clear(); // clears the error flag after invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer before taking in new input
		std::cout << "Invalid index. Please try again." << std::endl;
	}
}