/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:15:12 by aapadill          #+#    #+#             */
/*   Updated: 2026/02/11 10:15:14 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* std98
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}
*/

/* std11: auto and trailing ( -> ) //auto func(params) -> return_type
template <typename T>
auto easyfind(T& container, int value) -> typename T::iterator
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

template <typename T>
auto easyfind(const T& container, int value) -> typename T::const_iterator
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}
*/

/* std11 merged by using decltype
template <typename T>
auto easyfind(T& container, int value) -> decltype(container.begin())
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}
*/

// std14 merged with return type deduction
template <typename T>
auto easyfind(T& container, int value)
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}
