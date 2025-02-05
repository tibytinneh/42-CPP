/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <aang-shu.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:45:20 by aang-shu          #+#    #+#             */
/*   Updated: 2025/01/26 17:44:15 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replacer::Replacer(const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

std::string Replacer::replaceS1withS2(const std::string &content, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		throw std::invalid_argument("The search string (s1) cannot be empty.\n"); // throws error for catch

	std::string result;
	size_t pos = 0, lastPos = 0;

	while ((pos = content.find(s1, lastPos)) != std::string::npos)
	{
		result += content.substr(lastPos, pos - lastPos);
		result += s2;
		lastPos = pos + s1.length();
	}
	result += content.substr(lastPos);
	return (result);
}

bool Replacer::replace(void)
{
	/* OPEN FILE*/
	std::ifstream input(_filename.c_str()); // ifstream: input file stream. reads from a file in C++. c_str(): const char* C++98 bullshit
	if (!input.is_open())
	{
		std::cerr << "Could not open file " << _filename << "." << std::endl;
		return false;
	}

	/* READ FILE INTO STRING*/
	// reads everything into string(reads character from file, EOF.)
	std::string content((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>()); // read whole file at once
	input.close();

	/*REPLACE WORDS IN CONTENT*/
	std::string modified;
	try
	{
		modified = replaceS1withS2(content, _s1, _s2);
	}
	catch (const std::exception &e) // catches throw errors, prints it and returns false.
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}

	/* WRITE OUTPUT TO NEW FILE*/
	std::string outputFilename = _filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str()); // ofstream: output file stream. create/writes to a file in C++.
	if (!outputFile)
	{
		std::cerr << "Error: Could not create output file " << outputFilename << "." << std::endl;
		return false;
	}
	outputFile << modified;
	outputFile.close(); // close and save.
	std::cout << "Successful execution of replacement. Written to " << outputFilename << "." << std::endl;
	return (true);
}
