#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <cstddef>

class Span
{
	public :
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		class numberLimitReach : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		size_t getSize();
		size_t getSize() const;

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();

		int &operator[](unsigned long i);
		int &operator[](unsigned long i) const;
	private :
		int getBigNumPos();
		int getShortNumPos();

		int *array;
		size_t size;
		int nbReg;
};

#endif //SPAN_HPP