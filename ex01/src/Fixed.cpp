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
	return (float)_fixedPoint / (1 << _bits);
}

int Fixed::toInt(void) const
{
	return _fixedPoint >> _bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
