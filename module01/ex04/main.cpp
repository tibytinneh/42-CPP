/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <aang-shu.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:43:34 by aang-shu          #+#    #+#             */
/*   Updated: 2025/02/05 17:05:05 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "./programName <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	Replacer result(filename, s1, s2);
	if (!result.replace())
	{
		return (1);
	}
	return (0);
}
