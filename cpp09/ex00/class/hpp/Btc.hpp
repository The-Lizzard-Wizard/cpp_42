#ifndef BTC_HPP
#define BTC_HPP

#include <map>
#include <string>
#include "../../utils.hpp"

class Btc
{
	public:
		Btc();
		Btc(str DbTxt);
		Btc(const Btc &src);
		Btc &operator=(Btc &src);

		str getStr() const;
	private:
		str DbStr;
		std::map<str, float> input;
};

#endif //BTC_HPP