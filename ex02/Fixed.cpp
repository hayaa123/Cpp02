#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
    (1 << 8) means 2^8 in my code
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
    this->_rawBits = num * ( 1 << 8 );
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(num * ( 1 << 8 ));
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
    this->_rawBits = other.getRawBits();
    return (*this);
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_rawBits /(1 << 8));
}

int Fixed::toInt( void ) const
{
    return (this->_rawBits /(1 << 8));
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits = raw;
}

Fixed Fixed::operator+(const Fixed &other)
{
    return (Fixed((this->_rawBits + other._rawBits) / (1 << 8)));
}

Fixed Fixed::operator-(const Fixed &other)
{
    return (Fixed((this->_rawBits - other._rawBits) / (1 << 8)));
}

Fixed Fixed::operator*(const Fixed &other)
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
    return (Fixed(this->_rawBits / other._rawBits));
}

bool Fixed::operator>(const Fixed &other)
{
    return (this->_rawBits > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other)
{
    return (this->_rawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other)
{
    return (this->_rawBits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other)
{
    return (this->_rawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other)
{
    return (this->_rawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other)
{
    return (this->_rawBits != other.getRawBits());
}

Fixed& Fixed::operator++()
{
    this->_rawBits++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_rawBits++;
    return (temp);
}
float Fixed::min(Fixed& fixed1, Fixed& fixed2)
{

}
float Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{

}
float Fixed::max(Fixed& fixed1, Fixed& fixed2)
{

}
float Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{

}

std::ostream& operator<<(std::ostream &stream, const Fixed& obj)
{
    stream << obj.toFloat();
    return (stream);
}
