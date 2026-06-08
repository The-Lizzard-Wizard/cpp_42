#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <cstddef>
#include <vector>

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
		const std::vector<int> &getVec() const;

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();

	private :
		int getBigNumPos();
		int getShortNumPos();

		std::vector<int> array;
		int size;
		int nbReg;
};

#endif //SPAN_HPP