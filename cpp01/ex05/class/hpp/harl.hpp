#include <string>

class harl
{
	public:
		harl();
		void complain(std::string level);
	private: 
		void DEBUG(void);
		void info(void);
		void warning(void);
		void error(void);
};