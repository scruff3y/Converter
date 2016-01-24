#ifndef CONVERTER_DATA_H
#define CONVERTER_DATA_H

#define CONVERTER_MASS_CONVERSION_TABLE_NUMEL 4 // Number of elements in the mass conversion table.
#define CONVERTER_LENG_CONVERSION_TABLE_NUMEL 6 // Number of elements in the length conversion table.
#define CONVERTER_TIME_CONVERSION_TABLE_NUMEL 4 // Number of elements in the time conversion table.

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

	/*
	Main program loop.
	*/
	void convertLoop();

	/*
	Displays help message.
	*/
	void displayHelp() {
		std::cout << "\nUsage: <quantity> <unit> OR <quantity><unit>" << std::endl;
		std::cout << "Type \"help\" to see this message again, or \"quit\" to quit." << std::endl;
	}

	/*
	Converts the argument std::string to all lower case.
	*/
	void stdLowercase(std::string &input) {
		for (unsigned int i = 0; i < input.length(); i++) {
			if ((input.at(i) >= 'A') && (input.at(i) <= 'Z')) {
				input.at(i) += 0x20;
			}
		}
	}

	// This holds all possible ways of specifying a unit.
	const std::map<const std::string, const std::string> alternateNamesForUnits = {
	// MASSES -----------------------------------------------------------------
		// KILOGRAMS
		{ "kg", "kg" },
		{ "kgs", "kg" },
		{ "kilo", "kg" },
		{ "kilos", "kg" },
		{ "kiloes", "kg" },
		{ "kilogram", "kg" },
		{ "kilograms", "kg" },
		// OUNCES
		{ "oz", "oz" },
		{ "ounce", "oz" },
		{ "ounces", "oz" },
		// STONE
		{ "st", "st" },
		{ "stone", "st" },
		{ "stones", "st" },
		// POUND
		{ "lb", "lb" },
		{ "lbs", "lb" },
		{ "pound", "lb" },
		{ "pounds", "lb" },
	// LENGTHS -----------------------------------------------------------------
		// METERS
		{ "m", "m" },
		{ "metre", "m" },
		{ "metres", "m" },
		{ "meter", "m" }, // fkn Yanks...
		{ "meters", "m" },
		// YARDS
		{ "y", "y" },
		{ "yard", "y" },
		{ "yards", "y" },
		// FEET
		{ "f", "f" },
		{ "foot", "f" },
		{ "feet", "f" },
		// INCHES
		{ "i", "i" },
		{ "in", "i" },
		{ "inch", "i" },
		{ "inches", "i" },
		// MILES
		{ "mi", "mi" },
		{ "mile", "mi" },
		{ "miles", "mi" },
		// NAUTICAL MILES
		{ "nmi", "nmi" },
		{ "nauticalmile", "nmi" },
		{ "nauticalmiles", "nmi" },
		{ "nm", "nmi" },
	// TIMES -----------------------------------------------------------------
		// SECONDS
		{ "sec", "sec" },
		{ "s", "sec" },
		{ "seconds", "sec" },
		{ "second", "sec" },
		{ "Seconds", "sec" },
		{ "seconds", "sec" },
		{ "secs", "sec" },
		{ "Secs", "sec" },
		// HOURS
		{ "hrs", "hrs" },
		{ "hour", "hrs" },
		{ "h", "hrs" },
		{ "hours", "hrs" },
		{ "Hour", "hrs" },
		{ "Hours", "hrs" },
		// MINUTES
		{ "min", "min" },
		{ "mins", "min" },
		{ "Mins", "min" },
		{ "Minute", "min" },
		{ "Minutes", "min" },
		{ "minute", "min" },
		{ "minutes", "min" },
		// DAY
		{ "day", "day" },
		{ "Day", "day" },
		{ "days", "day" },
		{ "Days", "day" },
		{ "d", "day" },
	};

// MASSES -----------------------------------------------------------------

	// This holds the conversion constants for converting masses.
	const double massConversionTable[CONVERTER_MASS_CONVERSION_TABLE_NUMEL][CONVERTER_MASS_CONVERSION_TABLE_NUMEL] = {
		//			kg      oz      stone   lb
		/* kg*/{ 1.0000, 35.274, 0.1575, 2.2046 },
		/* oz*/{ 0.0283, 1.0000, 0.0045, 0.0625 },
		/* st*/{ 6.3502, 224.00, 1.0000, 14.000 },
		/* lb*/{ 0.4536, 16.000, 0.0714, 1.0000 }
	};

	// This holds the mapping between a unit of MASS and its postion in the conversion table.
	const std::map<const std::string, const int> massConversionTableIndex = {
		{ "kg", 0 },
		{ "oz", 1 },
		{ "st", 2 },
		{ "lb", 3 }
	};

	// This is to used to display the new unit of the converted mass.
	const std::string massStringUnitRepr[CONVERTER_MASS_CONVERSION_TABLE_NUMEL] = {
		"kilograms",
		"ounces",
		"stone",
		"pounds"
	};

	// LENGTHS ----------------------------------------------------------------

	// This holds the conversion constants for converting lengths.
	const double lengthConversionTable[CONVERTER_LENG_CONVERSION_TABLE_NUMEL][CONVERTER_LENG_CONVERSION_TABLE_NUMEL] = {
		//		 metres  yards   feet    inches  miles        nautical mi
		/* m */{ 1.0000, 1.0936, 3.2808, 39.370, 0.000621371, 0.000539957 },
		/* y */{ 0.9144, 1.0000, 3.0000, 36.000, 0.000568182, 0.000493737 },
		/* f */{ 0.3048, 0.3333, 1.0000, 12.000, 0.000189394, 0.000164579 },
		/* i */{ 0.0254, 0.0278, 0.0833, 1.0000, 0.000015783, 0.000013715 },
		/* mi*/{ 1609.3, 1760.0, 5280.0, 63360,  1.000000000, 0.868976000 },
		/*nmi*/{ 1852.0, 2025.3, 6076.1, 72913,  1.15078,	  1.000000000 }
	};

	// This holds the mapping between a unit of LENGTH and its postion in the conversion table.
	const std::map<const std::string, const int> lengthConversionTableIndex = {
		{ "m", 0 },
		{ "y", 1 },
		{ "f", 2 },
		{ "in", 3 },
		{ "mi", 4 },
		{ "nmi", 5 }
	};

	// This is to used to display the new unit of the converted length.
	const std::string lengthStringUnitRepr[CONVERTER_LENG_CONVERSION_TABLE_NUMEL] = {
		"metres",
		"yards",
		"feet",
		"inches",
		"miles",
		"nautical miles"
	};

	// TIMES ------------------------------------------------------------------

	// This holds the conversion constants for converting times.
	const double timeConversionTable[CONVERTER_TIME_CONVERSION_TABLE_NUMEL][CONVERTER_TIME_CONVERSION_TABLE_NUMEL] = {
		//       sec          hrs          min          day
		/*sec*/{ 1.000000000, 0.000277778, 0.016666700, 0.000011574 },
		/*hrs*/{ 3600.000000, 1.000000000, 60.00000000, 0.041666700 },
		/*min*/{ 60.00000000, 0.016666700, 1.000000000, 0.000694444 },
		/*day*/{ 86400.00000, 24.00000000, 1440.000000, 1.000000000 }
	};

	// This holds the mapping between a unit of TIME and its postion in the conversion table.
	const std::map<const std::string, const int> timeConversionTableIndex = {
		{ "sec", 0 },
		{ "hrs", 1 },
		{ "min", 2 },
		{ "day", 3 }
	};

	// This is to used to display the new unit of the converted time.
	const std::string timeStringUnitRepr[CONVERTER_TIME_CONVERSION_TABLE_NUMEL] = {
		"seconds",
		"hours",
		"minutes",
		"days"
	};

	// DIMENSIONS -------------------------------------------------------------

	/*
	Returns the dimension of the passed unit. Note that the unit should be
	passed through alternateName map before being passed here.
	*/
	const std::map<const std::string, const std::string> dimensionOf = {
		// MASSES
		{ "kg", "MASS" },
		{ "lb", "MASS" },
		{ "st", "MASS" },
		{ "oz", "MASS" },
		// LENGTHS
		{ "m", "LENG" },
		{ "y", "LENG" },
		{ "f", "LENG" },
		{ "i", "LENG" },
		{ "mi", "LENG" },
		{ "nmi", "LENG" },
		// TIMES
		{ "sec", "TIME" },
		{ "min", "TIME" },
		{ "hrs", "TIME" },
		{ "day", "TIME" },
	};
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

	if (alternateNamesForUnits.find(unitToConvert) != alternateNamesForUnits.end()) {
		std::string dimensionOfUnitToConvert = dimensionOf.at(alternateNamesForUnits.at(unitToConvert));

		if (AreSameString(dimensionOfUnitToConvert, "MASS")) {
			for (int indexOfUnitToConvertTo = 0; indexOfUnitToConvertTo < CONVERTER_MASS_CONVERSION_TABLE_NUMEL; indexOfUnitToConvertTo++) {

				int indexOfUnitToConvertFrom = massConversionTableIndex.at(alternateNamesForUnits.at(unitToConvert));

				if (indexOfUnitToConvertFrom != indexOfUnitToConvertTo) {
					double converted = valueToConvert * massConversionTable[indexOfUnitToConvertFrom][indexOfUnitToConvertTo];
					std::cout << std::to_string(converted) << " " << massStringUnitRepr[indexOfUnitToConvertTo] << std::endl;
				}
			}
		}
		else if (AreSameString(dimensionOfUnitToConvert, "LENG")) {
			for (int indexOfUnitToConvertTo = 0; indexOfUnitToConvertTo < CONVERTER_LENG_CONVERSION_TABLE_NUMEL; indexOfUnitToConvertTo++) {

				int indexOfUnitToConvertFrom = lengthConversionTableIndex.at(alternateNamesForUnits.at(unitToConvert));

				if (indexOfUnitToConvertFrom != indexOfUnitToConvertTo) {
					double converted = valueToConvert * lengthConversionTable[indexOfUnitToConvertFrom][indexOfUnitToConvertTo];
					std::cout << std::to_string(converted) << " " << lengthStringUnitRepr[indexOfUnitToConvertTo] << std::endl;
				}
			}
		}
		else if (AreSameString(dimensionOfUnitToConvert, "TIME")) {
			for (int indexOfUnitToConvertTo = 0; indexOfUnitToConvertTo < CONVERTER_TIME_CONVERSION_TABLE_NUMEL; indexOfUnitToConvertTo++) {

				int indexOfUnitToConvertFrom = timeConversionTableIndex.at(alternateNamesForUnits.at(unitToConvert));

				if (indexOfUnitToConvertFrom != indexOfUnitToConvertTo) {
					double converted = valueToConvert * timeConversionTable[indexOfUnitToConvertFrom][indexOfUnitToConvertTo];
					std::cout << std::to_string(converted) << " " << timeStringUnitRepr[indexOfUnitToConvertTo] << std::endl;
				}
			}
		}
	} else {
		std::cout << "Unit: \"" << unitToConvert << "\" was not recognised" << std::endl;
		std::cout << "Type \"help\" for help message." << std::endl;
	}
}

void convert::convertLoop() {
	while (true) {
		std::cout << "\nconvert:>";
		std::string input;
		std::getline(std::cin, input);

		convert::stdLowercase(input);

		if (convert::AreSameString(input, std::string("quit"))) break;
		if (convert::AreSameString(input, std::string("help"))) {
			displayHelp();
			continue;
		}

		convert::parseAndConvert(input);
	}
}
#endif
