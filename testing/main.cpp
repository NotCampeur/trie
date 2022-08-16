/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:50:14 by ldutriez          #+#    #+#             */
/*   Updated: 2022/08/16 12:57:46 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie"
#include <iostream>

void trie_insert_test(trie &trie)
{
	std::cout << "\n{TRIE INSERT TEST}\n";
	std::cout << "\n[inserting `hello`]\n";
	trie.insert("hello");

	std::cout << "\n[inserting `hella`]\n";
	trie.insert("hella");

	std::cout << "\n[inserting `world`]\n";
	trie.insert("world");

	std::cout << "\n[inserting `world`]\n";
	trie.insert("world");

	try {
		std::cout << "\n[inserting NULL]\n";
		trie.insert(NULL);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\n[inserting `42`]\n";
		trie.insert("42");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void trie_search_test(trie &trie)
{
	std::cout << "\n{TRIE SEARCH TEST}\n";
	std::cout << "\n[searching `hello`]\n";
	trie.search("hello");

	std::cout << "\n[searching `hella`]\n";
	trie.search("hella");
	
	std::cout << "\n[searching `world`]\n";
	trie.search("world");
	
	std::cout << "\n[searching `hell`]\n";
	trie.search("hell");
	
	std::cout << "\n[searching `helloa`]\n";
	trie.search("helloa");
	
	std::cout << "\n[searching `whelloa`]\n";
	trie.search("whelloa");

	try
	{
		std::cout << "\n[searching NULL]\n";
		trie.search(NULL);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n[searching `42`]\n";
		trie.search("42");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	trie trie;
	
	trie_insert_test(trie);
	trie_search_test(trie);

	return (0);
}