/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:10:48 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/18 17:44:21 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "Span.hpp"

static void subjectTest()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "subject shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "subject longest: " << sp.longestSpan() << std::endl;
}

static void largeRangeTest()
{
	const int count = 10000;
	std::vector<int> values;
	values.reserve(count);
	int i = 0;
	while (i < count)
	{
		values.push_back(i * 3);
		++i;
	}

	Span sp(count);
	sp.addNumber(values.begin(), values.end());
	std::cout << "large shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "large longest: " << sp.longestSpan() << std::endl;
}

static void exceptionTest()
{
	Span sp(2);
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cout << "full span exception: " << e.what() << std::endl;
	}
	try
	{
		Span tiny(1);
		tiny.addNumber(5);
		std::cout << tiny.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "no span exception: " << e.what() << std::endl;
	}
}

int main()
{
	subjectTest();
	largeRangeTest();
	exceptionTest();
	return 0;
}
