#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
    (1 << this->_fractionalBits) means 2^(this->_fractionalBits) in my code
*/
Fixed::Fixed()
{
    this->_rawBits = 0;
    std::cout<< "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = num * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(num * (1 << this->_fractionalBits));
}

int Fixed::getRawBits (void) const
{
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
    this->_rawBits = other._rawBits;
    return (*this);
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_rawBits /(1 << this->_fractionalBits));
}

int Fixed::toInt( void ) const
{
    return (this->_rawBits /(1 << this->_fractionalBits));
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits = raw;
}

std::ostream& operator<<(std::ostream &stream, const Fixed& obj)
{
    stream << obj.toFloat();
    return (stream);
}
