/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <aang-shu.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 05:34:12 by aang-shu          #+#    #+#             */
/*   Updated: 2024/10/08 19:03:40 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "contact.class.hpp"

const std::size_t maxContacts = 8;

class Phonebook{
private:
    Contact _contactsArr[maxContacts];
    std::size_t _index;
    std::size_t _totalContacts;

public:
    Phonebook();
    void    addContact();
    void    searchContact() const;
};

#endif //PHONEBOOK_CLASS_HPP