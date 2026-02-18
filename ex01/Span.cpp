/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:24:06 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/18 18:07:14 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span() : _capacity(0), _size(0), _data(nullptr) {}

Span::Span(unsigned int n) : _capacity(n), _size(0), _data(nullptr)
{
	if (n > 0)
		_data = new int[n];
}

Span::Span(const Span &other) : _capacity(other._capacity), _size(other._size), _data(nullptr)
{
	if (_capacity > 0)
		_data = new int[_capacity];
	unsigned int i = 0;
	while (i < _size)
	{
		_data[i] = other._data[i];
		++i;
	}
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	int *newData = nullptr;
	if (other._capacity > 0)
		newData = new int[other._capacity];
	unsigned int i = 0;
	while (i < other._size)
	{
		newData[i] = other._data[i];
		++i;
	}
	delete[] _data;
	_data = newData;
	_capacity = other._capacity;
	_size = other._size;
	return *this;
}

Span::~Span()
{
	delete[] _data;
}

void Span::addNumber(int number)
{
	if (_size >= _capacity)
		throw FullSpanException();
	_data[_size++] = number;
}

int Span::shortestSpan() const
{
	if (_size < 2)
		throw NoSpanException();
	std::vector<int> tmp(_data, _data + _size);
	std::sort(tmp.begin(), tmp.end());
	long long minDiff = std::numeric_limits<long long>::max();
	std::size_t i = 1;
	while (i < tmp.size())
	{
		long long diff = static_cast<long long>(tmp[i]) - static_cast<long long>(tmp[i - 1]);
		if (diff < minDiff)
			minDiff = diff;
		++i;
	}
	return static_cast<int>(minDiff);
}

int Span::longestSpan() const
{
	if (_size < 2)
		throw NoSpanException();
	int minVal = _data[0];
	int maxVal = _data[0];
	unsigned int i = 1;
	while (i < _size)
	{
		if (_data[i] < minVal)
			minVal = _data[i];
		if (_data[i] > maxVal)
			maxVal = _data[i];
		++i;
	}
	long long diff = static_cast<long long>(maxVal) - static_cast<long long>(minVal);
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
