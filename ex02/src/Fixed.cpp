#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = value << _bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(value * (1 << _bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _fixedPoint(src._fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPoint = src._fixedPoint;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedPoint / (1 << 8);
}

int Fixed::toInt(void) const
{
	return _fixedPoint >> 8;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return this->_fixedPoint > fixed._fixedPoint;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return this->_fixedPoint < fixed._fixedPoint;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->_fixedPoint >= fixed._fixedPoint;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->_fixedPoint <= fixed._fixedPoint;
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return this->_fixedPoint == fixed._fixedPoint;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->_fixedPoint != fixed._fixedPoint;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits(this->_fixedPoint + fixed._fixedPoint);
	return newFixed;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits(this->_fixedPoint - fixed._fixedPoint);
	return newFixed;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits((this->_fixedPoint * fixed._fixedPoint) >> _bits);
	return newFixed;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits((this->_fixedPoint << _bits) / fixed._fixedPoint);
	return newFixed;
}

Fixed &Fixed::operator++()
{
	_fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_fixedPoint++;
	return temp;
}

Fixed &Fixed::operator--()
{
	_fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_fixedPoint--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixedPoint < b._fixedPoint)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._fixedPoint < b._fixedPoint)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixedPoint > b._fixedPoint)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._fixedPoint > b._fixedPoint)
		return a;
	else
		return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
