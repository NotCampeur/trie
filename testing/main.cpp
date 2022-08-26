/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:50:14 by ldutriez          #+#    #+#             */
/*   Updated: 2022/08/26 13:37:38 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie"
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string>	words;

void trie_insert_test(trie &trie)
{
	std::cout << "\n=============================>{TRIE INSERT TEST}\n";
	std::string tmp_word(words[rand() % 1000]);
	std::cout << tmp_word << " has been inserted in trie : " << trie.insert(tmp_word) << '\n';
}

void trie_search_test(trie &trie)
{
	std::cout << "\n=============================>{TRIE SEARCH TEST}\n";
	std::string tmp_word(words[rand() % 1000]);
	std::cout << tmp_word << " is in trie : " << trie.search(tmp_word) << '\n';
}

void trie_print_test(trie &trie)
{
	std::cout << "\n=============================>{TRIE PRINT TEST}\n";
	std::cout << "\n[printing trie]\n";
	trie.print();
}

void trie_copy_constructor_test(trie &to_copy)
{
	std::cout << "\n=============================>{TESTING TRIE COPY CONSTRUCTOR}\n";
	trie t(to_copy);

	std::string tmp_word(words[rand() % 1000]);
	std::cout << tmp_word << " has been inserted in tmp trie : " << t.insert(tmp_word) << '\n';
	std::cout << "Is " << tmp_word << " in tmp : " << t.search(tmp_word)
				<< " is " << tmp_word << " in base trie : " << to_copy.search(tmp_word) << '\n';
}

void trie_assignation_operator_test(trie &to_assign)
{
	std::cout << "\n=============================>{TESTING TRIE ASSIGNATION OPERATOR}\n";
	trie t;
	
	t = to_assign;


	std::string tmp_word(words[rand() % 1000]);
	std::cout << tmp_word << " has been inserted in tmp trie : " << t.insert(tmp_word) << '\n';
	std::cout << "Is " << tmp_word << " in tmp : " << t.search(tmp_word)
				<< " is " << tmp_word << " in base trie : " << to_assign.search(tmp_word) << '\n';
}

void trie_erase_test(trie &t)
{
	std::cout << "\n=============================>{TESTING ERASE}\n";
	
	std::string tmp_word(words[rand() % 1000]);
	std::cout << "Is " << tmp_word <<  " in trie before deletion : " << t.search(tmp_word) << '\n';
	std::cout << tmp_word << " is a correct word to erase : " << t.erase(tmp_word) << '\n';

	std::cout << "\nPrinting trie after deletion test :\n";
	t.print();
}

void trie_iterator_test(trie &t)
{
	std::cout << "\n=============================>{TRIE ITERATOR TESTING}\n";

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

void trie_size_test(trie & t)
{
	std::cout << "\n=============================>{TRIE SIZE TESTING}\n";
	std::cout << "Number of words in the trie : " << t.size() << '\n';
}

bool	get_testing_words(void)
{
	std::ifstream	file(std::getenv("HOME") + std::string("/.zsh_history"));

	if (file.good() == false)
	{
		std::cout << "Error could not open `~/.zsh_history` file\n";
		return false;
	}
	for (int i(0); i < 1000; ++i)
	{
		std::string tmp;
		file >> tmp;
		words.push_back(tmp);
	}
	file.close();
	return true;
}

int main(void)
{
	trie t;
	void (*tests[8])(trie &) = {
		trie_insert_test, trie_search_test, trie_print_test,
		trie_copy_constructor_test, trie_assignation_operator_test,
		trie_erase_test, trie_iterator_test, trie_size_test
	};

	if (get_testing_words() == false)
		return 1;
	srand(time(NULL));
	std::cout << std::boolalpha;
	for (
			int to_call(rand() % 8), count(0);
			count != -1;
			to_call = rand() % 8, ++count
		)
		tests[to_call](t);

	return 0;
}