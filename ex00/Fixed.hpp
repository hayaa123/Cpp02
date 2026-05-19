#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int _rawBits;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed& operator=(Fixed &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif