/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <aang-shu.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:45:47 by aang-shu          #+#    #+#             */
/*   Updated: 2025/01/26 17:42:45 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#define C_RED "\033[31m"
#define C_BLUE "\033[34m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_DEFAULT "\033[0m"

#include <iostream>
#include <fstream>
#include <string>

class Replacer
{
private:
	std::string _filename;
	std::string _s1;
	std::string _s2;

	std::string replaceS1withS2(const std::string &content, const std::string &s1, const std::string &s2);

public:
	Replacer(const std::string &filename, const std::string &s1, const std::string &s2);
	bool replace(void);
};
#endif
