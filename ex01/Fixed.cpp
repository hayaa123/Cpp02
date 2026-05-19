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

Fixed::Fixed(const int num)
{
    this->_rawBits = num * ( 1 << 8 );
}

/*
    (1 << 8) means 2^8 in my code
*/
Fixed::Fixed(const float num)
{
    this->_rawBits = num * ( 1 << 8 );
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
Fixed& Fixed::operator=(Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &other)
        return (*this);
    this->_rawBits = other.getRawBits();
    return (*this);
}

float Fixed::toFloat( void ) const
{
}

int Fixed::toInt( void ) const
{
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits = raw;
}


std::ostream& operator<<(std::ostream &stream, const Fixed& obj)
{
    stream << obj.getRawBits();
    return (stream);
}
