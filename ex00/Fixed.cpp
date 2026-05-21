#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    this->_rawBits = 0;
    std::cout<< "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = other.getRawBits();
}

int Fixed::getRawBits (void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &other)
        return (*this);
    this->_rawBits = other.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits = raw;
}