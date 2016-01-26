#include "converter_data.h"

int main(int argc, char *argv[]) {
	if (argc == 2) {
		convert::makeStdStringLowercase(std::string(argv[1]));
		if (convert::AreSameString(argv[1], "/?")) {
			std::cout << "\nUsage: <quantity><unit>" << std::endl;
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
		convert::makeStdStringLowercase(cmdLineInput);
		convert::parseAndConvert(cmdLineInput);
		return 0;
	}
	else {
		while (true) {
			std::cout << "\nconvert:>";
			std::string input;
			std::getline(std::cin, input);

			convert::makeStdStringLowercase(input);

			if (convert::AreSameString(input, std::string("quit"))) break;

			convert::parseAndConvert(input);
		}
	}

	return 0;
}
