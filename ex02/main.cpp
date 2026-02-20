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
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl; //prints 17
	mstack.pop(); //removes 17
	std::cout << mstack.size() << std::endl; //one

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	/*
	-- current stack be like --
		0  <---- end, top
		737
		5
		3
		5  <---- begin
	*/
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it; //pos of 3
	--it; //pos of 5
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
