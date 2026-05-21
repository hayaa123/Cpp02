#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
    (1 << 8) means 2^8 in my code
*/
Fixed::Fixed()
{
    this->_rawBits = 0;
}

Fixed::Fixed(const Fixed &other)
{
    this->_rawBits = other._rawBits;
}

Fixed::Fixed(const int num)
{
    this->_rawBits = num * ( 1 << this->_fractionalBits );
}

Fixed::Fixed(const float num)
{
    this->_rawBits = roundf(num * ( 1 << this->_fractionalBits ));
}

int Fixed::getRawBits (void) const
{
    return (this->_rawBits);
}

Fixed::~Fixed()
{
}
Fixed& Fixed::operator=(const Fixed &other)
{
    if(this == &other)
        return (*this);
    this->_rawBits = other.getRawBits();
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

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    std::cout << this->toFloat() << " , " << other.toFloat() << std::endl;
    return (Fixed(this->toFloat() / other.toFloat()));
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_rawBits > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_rawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_rawBits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_rawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_rawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
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

Fixed& Fixed::operator--()
{
    this->_rawBits--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_rawBits--;
    return (temp);
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if(fixed1 < fixed2)
        return (fixed1);
    return (fixed2);
}
const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if(fixed1 < fixed2)
        return (fixed1);
    return (fixed2);
}
Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if(fixed1 > fixed2)
        return (fixed1);
    return (fixed2);
}
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if(fixed1 > fixed2)
        return (fixed1);
    return (fixed2);
}

std::ostream& operator<<(std::ostream &stream, const Fixed& obj)
{
    stream << obj.toFloat();
    return (stream);
}
