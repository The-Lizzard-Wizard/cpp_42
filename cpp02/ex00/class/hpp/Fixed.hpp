class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &newF);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int fixedPoint;
		static const int size;

};