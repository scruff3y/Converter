#include "converter_data.h"

int main(int argc, char *argv[]) {
	if (argc == 2) {
		convert::stdLowercase(std::string(argv[1]));
		if (convert::AreSameString(argv[1], "/?")) {
			std::cout << "\nUsage: <quantity> <unit> OR <quantity><unit>" << std::endl;
		}
		else {
			std::cout << "\n";
			convert::parseAndConvert(std::string(argv[1]));
		}
		return 0;
	}
	else if (argc == 3) {
		std::string cmdLineInput(argv[1]);
		cmdLineInput += argv[2];
		convert::stdLowercase(cmdLineInput);
		convert::parseAndConvert(cmdLineInput);
		return 0;
	}
	else {
		std::cout << "Converter by scruff3y. Vist me on GitHub at\n\n\thttps://github.com/scruff3y" << std::endl;
		convert::convertLoop();
	}

	return 0;
}
