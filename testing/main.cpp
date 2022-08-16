/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:50:14 by ldutriez          #+#    #+#             */
/*   Updated: 2022/08/16 21:21:51 by ldutriez         ###   ########.fr       */
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

	std::cout << "\n[inserting `hellaworld`]\n";
	trie.insert("hellaworld");

	std::cout << "\n[inserting `42`]\n";
	if (trie.insert("42") == true)
		std::cout << "INSERTED\n";
	else
		std::cout << "NOT INSERTED\n";
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

	std::cout << "\n[searching `hellaworld`]\n";
	trie.search("hellaworld");

	std::cout << "\n[searching `42`]\n";
	if (trie.insert("42") == true)
		std::cout << "FOUND\n";
	else
		std::cout << "NOT FOUND\n";
}

void trie_print_test(trie &trie)
{
	std::cout << "\n{TRIE PRINT TEST}\n";
	std::cout << "\n[printing trie]\n";
	trie.print();

	std::cout << "\n[printing words starting with `he`]\n";
	std::string s("he");
	trie.print(s);

	std::cout << "\n[printing words starting with `foo`]\n";
	trie.print("foo");

	std::cout << "\n[printing words starting with `hellaa`]\n";
	trie.print("hellaa");

	std::cout << "\n[printing words starting with `hella`]\n";
	trie.print("hella");
}

int main(void)
{
	trie trie;
	
	trie_insert_test(trie);
	trie_search_test(trie);
	trie_print_test(trie);
	
	return (0);
}