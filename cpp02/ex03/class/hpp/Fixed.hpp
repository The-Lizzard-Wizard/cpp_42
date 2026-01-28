#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const int Fp);
		Fixed(const float Fp);
		Fixed(const Fixed &src);
		~Fixed();

		Fixed &operator=(const Fixed &newF);
		Fixed operator+(const Fixed &b);
		Fixed operator-(const Fixed &b);
		Fixed operator/(const Fixed &b);
		Fixed operator*(const Fixed &b);
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		bool operator>(const Fixed &b) const;
		bool operator<(const Fixed &b) const;
		bool operator>=(const Fixed &b) const;
		bool operator<=(const Fixed &b) const;
		bool operator==(const Fixed &b) const;
		bool operator!=(const Fixed &b) const;

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
	private:
		int fixedPoint;
		static const int size = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed &fix);

#endif //FIXED_HPP
