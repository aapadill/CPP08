/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:24:31 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/18 17:44:49 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <cstddef>
# include <exception>
# include <vector>

class Span
{
	private:
		unsigned int	_capacity;
		unsigned int	_size;
		int				*_data;

	public:
		Span();
		explicit Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int number);

		template <typename InputIt>
		void	addNumber(InputIt first, InputIt last)
		{
			std::vector<int> buffer;

			InputIt it = first;
			while (it != last)
			{
				buffer.push_back(*it);
				++it;
			}
			if (_size + buffer.size() > _capacity)
				throw FullSpanException();
			std::size_t i = 0;
			while (i < buffer.size())
			{
				_data[_size++] = buffer[i];
				++i;
			}
		}

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

#endif
