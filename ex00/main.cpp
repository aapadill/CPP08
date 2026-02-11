/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:10:48 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/10 13:24:28 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

static void testVector()
{
	std::vector<int> values;
	values.push_back(4);
	values.push_back(2);
	values.push_back(1);

	try
	{
		auto it = easyfind(values, 1); //std98 //std::vector<int>::iterator it = easyfind(values, 1);
		std::cout << "vector found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "vector error: " << e.what() << std::endl;
	}
}

static void testList()
{
	std::list<int> values;
	values.push_back(9);
	values.push_back(8);
	values.push_back(7);

	try
	{
		auto it = easyfind(values, 8); //std98 //std::list<int>::iterator it = easyfind(values, 8);
		std::cout << "list found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "list error: " << e.what() << std::endl;
	}
}

static void testDeque()
{
	std::deque<int> values;
	values.push_back(3);
	values.push_back(1);
	values.push_back(4);

	try
	{
		auto it = easyfind(values, 42); //std98 //std::deque<int>::iterator it = easyfind(values, 42);
		std::cout << "deque found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "deque error: " << e.what() << std::endl;
	}
}

int main()
{
	testVector();
	testList();
	testDeque();
	return 0;
}
