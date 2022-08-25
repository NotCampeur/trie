/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:50:14 by ldutriez          #+#    #+#             */
/*   Updated: 2022/08/25 05:52:15 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie"
#include <iostream>

void trie_insert_test(trie &trie)
{
	std::cout << "\n{TRIE INSERT TEST}\n" << std::boolalpha;
	std::cout << "\n[inserting `hello`]\n";
	std::cout << "hello has been inserted in trie : " << trie.insert("hello") << '\n';

	std::cout << "\n[inserting `hella`]\n";
	std::cout << "hella has been inserted in trie : " << trie.insert("hella") << '\n';

	std::cout << "\n[inserting `world`]\n";
	std::cout << "world has been inserted in trie : " << trie.insert("world") << '\n';

	std::cout << "\n[inserting `world`]\n";
	std::cout << "world has been inserted in trie : " << trie.insert("world") << '\n';

	std::cout << "\n[inserting `hellaworld`]\n";
	std::cout << "hellaworld has been inserted in trie : " << trie.insert("hellaworld") << '\n';

	std::cout << "\n[inserting `42`]\n";
	std::cout << "42 has been inserted in trie : " << trie.insert("42") << '\n';

	std::cout << "\n[inserting `.`]\n";
	std::cout << ". has been inserted in trie : " << trie.insert(".") << '\n';
}

void trie_search_test(trie &trie)
{
	std::cout << "\n{TRIE SEARCH TEST}\n" << std::boolalpha;
	std::cout << "\n[searching `hello`]\n";
	std::cout << "hello is in trie : " << trie.search("hello") << '\n';

	std::cout << "\n[searching `hella`]\n";
	std::cout << "hella is in trie : " << trie.search("hella") << '\n';
	
	std::cout << "\n[searching `world`]\n";
	std::cout << "world is in trie : " << trie.search("world") << '\n';
	
	std::cout << "\n[searching `hell`]\n";
	std::cout << "hell is in trie : " << trie.search("hell") << '\n';
	
	std::cout << "\n[searching `helloa`]\n";
	std::cout << "helloa is in trie : " << trie.search("helloa") << '\n';
	
	std::cout << "\n[searching `whelloa`]\n";
	std::cout << "whelloa is in trie : " << trie.search("whelloa") << '\n';

	std::cout << "\n[searching `hellaworld`]\n";
	std::cout << "hellaworld is in trie : " << trie.search("hellaworld") << '\n';

	std::cout << "\n[searching `42`]\n";
	std::cout << "42 is in trie : " << trie.search("42") << '\n';
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

void trie_copy_constructor_test(const trie &to_copy)
{
	std::cout << "\n{TESTING TRIE COPY CONSTRUCTOR}\n";
	trie t(to_copy);

	std::cout << "Salut has been inserted in trie : " << t.insert("Salut") << '\n';
	trie_search_test(t);
	trie_print_test(t);
}

void trie_assignation_operator_test(const trie &to_assign)
{
	std::cout << "\n{TESTING TRIE ASSIGNATION OPERATOR}\n";
	trie t;
	
	t = to_assign;

	std::cout << "Plop has been inserted in trie : " << t.insert("Plop") << '\n';
	trie_search_test(t);
	trie_print_test(t);
}

void trie_erase_test(trie &t)
{
	std::cout << "\n{TESTING ERASE}\n";
	
	std::cout << "\nErasing `he` : " << t.erase("he") << '\n';
	std::cout << "\nErasing `42` : " << t.erase("42") << '\n';
	std::cout << "\nErasing `Hella` : " << t.erase("Hella") << '\n';
	std::cout << "\nErasing `Hello world` : " << t.erase("Hello world") << '\n';

	std::cout << "\nPrinting trie after deletion test :\n";
	t.print();
}

void trie_iterator_test(trie &t)
{
	std::cout << "\n{TRIE ITERATOR TESTING}\n";

	std::cout << "\nFor loop iterator post increment test\n";
	for (trie::const_iterator cit(t.cbegin()); cit != t.cend(); cit++)
		std::cout << *cit << '\n';

	std::cout << "\nFor loop iterator pre increment test\n";
	for (trie::const_iterator cit(t.cbegin()); cit != t.cend(); ++cit)
		std::cout << *cit << '\n';

	std::cout << "\nFor loop iterator post decrement test\n";
	for (trie::const_iterator lit(t.clast()); lit != t.cend(); lit--)
		std::cout << *lit << '\n';

	std::cout << "\nFor loop iterator pre decrement test\n";
	for (trie::const_iterator lit(t.clast()); lit != t.cend(); --lit)
		std::cout << *lit << '\n';
}

int main(void)
{
	trie t;
	
	trie_insert_test(t);
	trie_search_test(t);
	trie_print_test(t);
	trie_copy_constructor_test(t);
	trie_assignation_operator_test(t);
	trie_erase_test(t);
	trie_iterator_test(t);
	return (0);
}