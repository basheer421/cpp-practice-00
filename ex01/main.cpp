/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:48:39 by bammar            #+#    #+#             */
/*   Updated: 2023/01/23 15:57:57 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

typedef struct s_contact_info
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
}			t_contact_info;


static bool add(PhoneBook &pb, t_contact_info info)
{
	if (info.firstName.length() == 0 || info.lastName.length() == 0
		|| info.nickName.length() == 0
		|| info.phoneNumber.length() == 0
		|| info.darkestSecret.length() == 0)
		return (false);
	
	pb.addContact(Contact(info.firstName, info.lastName,
		info.nickName, info.phoneNumber, info.darkestSecret));
	return (true);
}

static void	request_info(t_contact_info &info)
{
	std::cout << "First Name: ";
	std::cin >> info.firstName;
	std::cout << "\nLast Name: ";
	std::cin >> info.lastName;
	std::cout << "\nNick Name: ";
	std::cin >> info.nickName;
	std::cout << "\nPhone Number: ";
	std::cin >> info.phoneNumber;
	std::cout << "\nDarkest Secret: ";
	std::cin >> info.darkestSecret;
}

static void	display_contacts()
{
	
}

static void	request_input(PhoneBook &phoneBook)
{
	std::string		input;
	t_contact_info	addInfo;
	int				index;

	std::cout << "Please Enter a command [ADD, SEARCH, EXIT]: ";
	std::cin >> input;
	std::cout << "\n";
	if (input == "EXIT")
		return ;
	else if (input == "ADD")
	{
		request_info(addInfo);
		if (!add(phoneBook, addInfo))
			std::cout << "Please fill all fields.\n";
		
	}
	else if (input == "SEARCH")
	{
		phoneBook.displayAllContacts();
		std::cout << "Choose the index of the contact you want to display: ";
		std::cin >> index;
		std::cout << "\n";
		if (index  >= phoneBook.getCurrentSize() || index < 0)
			std::cout << "Choose within the given range please.\n";
		else
			phoneBook.displayContact(index);
	}
	request_input(phoneBook);
}


int main(void)
{
	PhoneBook		phoneBook;

	phoneBook = PhoneBook();
	request_input(phoneBook);
	return (0);
}
