#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>


class Contact{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

public:
    // Constructor and Destructor
	// Contact();
	// ~Contact();

	// Getters
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	// Setters
	void setFirstName(const std::string& first_name);
	void setLastName(const std::string& last_name);
	void setNickname(const std::string& nickname);
	void setPhoneNumber(const std::string& phone_number);
	void setDarkestSecret(const std::string& darkest_secret);

	// Filling in contact details from user input
	bool fillContactDetails();
    void displayDetails() const;
    std::string getShortString(const std::string &str) const;

};

#endif // CONTACT_CLASS_HPP