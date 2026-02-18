/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:24:06 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/18 18:24:43 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>

Span::Span() : _capacity(0) {}

Span::Span(unsigned int n) : _capacity(n)
{
	_vector.reserve(n);
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_vector = other._vector;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_vector.size() >= _capacity)
		throw FullSpanException();
	_vector.push_back(number);
}

int Span::shortestSpan() const
{
	if (_vector.size() < 2)
		throw NoSpanException();
	std::vector<int> tmp(_vector);

	std::sort(tmp.begin(), tmp.end());
	long long minDiff = static_cast<long long>(tmp[1]);
	minDiff -= tmp[0];

	std::size_t i = 1;
	while (i < tmp.size())
	{
		long long diff = static_cast<long long>(tmp[i]);
		diff -= tmp[i - 1];
		if (diff < minDiff)
			minDiff = diff;
		++i;
	}

	return static_cast<int>(minDiff);
}

int Span::longestSpan() const
{
	if (_vector.size() < 2)
		throw NoSpanException();

	auto minmax = std::minmax_element(_vector.begin(), _vector.end());
	long long diff = static_cast<long long>(*minmax.second);
	diff -= *minmax.first;

	return static_cast<int>(diff);
}

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Not enough numbers to compute a span";
}
