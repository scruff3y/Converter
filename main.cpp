#include "converter_data.h"

int main(int argc, char *argv[]) {
	if (argc == 2) {
		convert::parseAndConvert(std::string(argv[1]));
	}
	else if (argc == 3) {
		std::string cmdLineInput(argv[1]);
		cmdLineInput += argv[2];
		convert::parseAndConvert(cmdLineInput);
	}
	else {
		std::cout << "unrecognised command-line input" << std::endl;
	}

	while (true) {
		std::cout << "\nconvert:>";
		std::string input;
		std::getline(std::cin, input);

		if (convert::AreSameString(input, std::string("quit"))) break;

		convert::parseAndConvert(input);
	}

	return 0;
}

