/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:24:31 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/18 18:24:43 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>
# include <exception>
# include <vector>

class Span
{
	private:
		unsigned int		_capacity;
		std::vector<int>	_vector;

	public:
		Span();
		Span(unsigned int n); //add explicit to avoid Span sp = n to work
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int number); //single number

		template <typename Iterator>
		void	addNumbers(Iterator first, Iterator last); //range of numbers

		int		shortestSpan() const;
		int		longestSpan() const;

		class FullSpanException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

template <typename Iterator>
void	Span::addNumbers(Iterator first, Iterator last)
{
	std::vector<int> buffer;

	Iterator it = first;
	while (it != last)
	{
		buffer.push_back(*it);
		++it;
	}
	if (_vector.size() + buffer.size() > _capacity)
		throw FullSpanException();
	std::size_t i = 0;
	while (i < buffer.size())
	{
		_vector.push_back(buffer[i]);
		++i;
	}
}
