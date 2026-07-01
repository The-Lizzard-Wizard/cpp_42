#ifndef INPUT_HPP
#define INPUT_HPP

#include <map>
#include <string>
#include "../../utils.hpp"

class Input
{
	public:
		Input();
		Input(str DbTxt);
		Input(const Input &src);
		Input &operator=(Input &src);

		str getStr() const;
		std::map<str, float> getMap() const;
	private:
		str DbStr;
		std::map<str, float> input;
};

#endif //INPUT_HPP