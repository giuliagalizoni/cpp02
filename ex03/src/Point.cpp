#include "../include/Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	std::cout << "Constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	(void)src;
	return *this;
}

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}
