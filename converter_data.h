#ifndef CONVERTER_DATA_H
#define CONVERTER_DATA_H

#define CONVERTER_MASS_CONVERSION_TABLE_NUMEL 4 // Number of elements in the mass conversion table.

#include <iostream>
#include <string>
#include <map>

// Declarations of a few helper functions.
namespace convert {
	/*
	Returns true if argument is a valid character that could be found in a
	number, i.e '0' - '9' and '.'
	*/
	int IsNumberChar(char);

	/*
	Returns true is argument is a letter.
	*/
	int IsLetterChar(char);

	/*
	Returns true if arguments are identical.
	*/
	int AreSameString(std::string, std::string);

	/*
	Displays the input quantity as a variety of other quantities.
	*/
	void parseAndConvert(std::string);

	// This holds the conversion constants for converting masses.
	double massConversionTable[CONVERTER_MASS_CONVERSION_TABLE_NUMEL][CONVERTER_MASS_CONVERSION_TABLE_NUMEL] = {
		//			kg      oz      stone   lb
		/* kg*/{ 1.0000, 35.274, 0.1575, 2.2046 },
		/* oz*/{ 35.274, 1.0000, 224.00, 16.000 },
		/* st*/{ 6.3502, 224.00, 1.0000, 14.000 },
		/* lb*/{ 0.4536, 16.000, 0.0714, 1.0000 }
	};

	// This is the mapping between the string representations of the units and
	// their respective places in the conversion table.
	const std::map<const std::string, const int> unitsToTableIndex = {
		{ "kg", 0 },
		{ "oz", 1 },
		{ "st", 2 },
		{ "lb", 3 }
	};

	// This holds all possible ways of specifiying a given unit (mass).
	const std::map<const std::string, const std::string> alternateNamesForMassUnits = {
		// KILOGRAMS
		{ "kg", "kg" },
		{ "KG", "kg" },
		{ "Kgs", "kg" },
		{ "kgs", "kg" },
		{ "KGs", "kg" },
		{ "Kgs", "kg" },
		{ "kilo", "kg" },
		{ "Kilo", "kg" },
		{ "kilos", "kg" },
		{ "Kilos", "kg" },
		{ "kiloes", "kg" },
		{ "Kiloes", "kg" },
		{ "kilogram", "kg" },
		{ "Kilogram", "kg" },
		{ "kilograms", "kg" },
		{ "Kilograms", "kg" },
		// OUNCES
		{ "oz", "oz" },
		{ "OZ", "oz" },
		{ "ounce", "oz" },
		{ "ounces", "oz" },
		{ "Ounce", "oz" },
		{ "Ounces", "oz" },
		// STONE
		{ "st", "st" },
		{ "ST", "st" },
		{ "stone", "st" },
		{ "Stone", "st" },
		{ "stones", "st" },
		{ "Stones", "st" },
		// POUND
		{ "lb", "lb" },
		{ "LB", "lb" },
		{ "lbs", "lb" },
		{ "LBs", "lb" },
		{ "pound", "lb" },
		{ "pounds", "lb" },
		{ "Pound", "lb" },
		{ "Pounds", "lb" },
	};

	std::string intToString[4] = { "kg", "oz", "st", "lb" };

}

int convert::IsNumberChar(char check) {
	if (((check >= '0') && (check <= '9')) || (check == '.')) return 1;
	return 0;
}

int convert::IsLetterChar(char check) {
	if (((check >= 'A') && (check <= 'Z')) || ((check >= 'a') && (check <= 'z'))) return 1;
	return 0;
}

int convert::AreSameString(std::string str1, std::string str2) {
	if (str1.length() == str2.length()) {
		for (unsigned int i = 0; i < str1.length(); i++) {
			if (str1.at(i) != str2.at(i)) return 0;
		}
	}
	else {
		return 0;
	}
	return 1;
}

void convert::parseAndConvert(std::string input) {
	unsigned int i;
	std::string numberToConvert = "0";
	for (i = 0; i < input.length(); i++) {
		if (convert::IsNumberChar(input.at(i))) {
			numberToConvert += input.at(i);
		}
		else break;
	}
	double valueToConvert = std::stod(numberToConvert);

	std::string unitToConvert;
	for (i; i < input.length(); i++) {
		if (convert::IsLetterChar(input.at(i))) unitToConvert += input.at(i);
	}

	for (int i = 0; i < CONVERTER_MASS_CONVERSION_TABLE_NUMEL; i++) {
		int indexToCheck = convert::unitsToTableIndex.at(convert::alternateNamesForMassUnits.at(unitToConvert));
		if (indexToCheck != i) {
			double converted = valueToConvert * convert::massConversionTable[indexToCheck][i];
			std::cout << std::to_string(converted) << " " << intToString[i] << std::endl;
		}
	}
}


#endif
