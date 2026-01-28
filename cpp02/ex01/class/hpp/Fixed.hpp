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
		Fixed &operator=(const Fixed &newF);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int fixedPoint;
		static const int size = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed &fix);

#endif //FIXED_HPP