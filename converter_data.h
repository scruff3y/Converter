#ifndef CONVERTER_DATA_H
#define CONVERTER_DATA_H

#define CONVERTER_MASS_CONVERSION_TABLE_NUMEL 4 // Number of elements in the mass conversion table.
#define CONVERTER_LENG_CONVERSION_TABLE_NUMEL 6 // Number of elements in the length conversion table.
#define CONVERTER_TIME_CONVERSION_TABLE_NUMEL 4 // Number of elements in the time conversion table.
#define CONVERTER_TEMPERATURE_CONVERSION_TABLE_NUMEL 3 // Number of elements in the temperature conversion table.

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
	Returns true if character is part of a valid string representing a unit.
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
	struct containing arguments for conversion()
	*/
	struct conversionParameters {
		double value					 = -1;
		int indexOfUnitToConvertFrom	 = -1;
		int numOfElInConversionTable	 = -1;
		const double* conversionTable	 = NULL;
		const std::string * stringRepOf	 = NULL;
	};

	/*
	Returns parameters for conversion.
	*/
	conversionParameters getConversionParameters(double, std::string);

	/*
	*/
	void conversion(conversionParameters);

	/*
	Main program loop.
	*/
	void convertLoop();

	/*
	Displays help message.
	*/
	void displayHelp() {
		std::cout << "\nUsage: <quantity> <unit> OR <quantity><unit>" << std::endl;
		std::cout << "Type:" << std::endl;
		std::cout << "\t\"help\" to display this message.\n";
		std::cout << "\t\"about\" to view details about this program.\n";
		std::cout << "\t\"quit\" to quit." << std::endl;
	}

	/*
	Displays about message.
	*/
	void displayAbout() {
		std::cout << "Converter by scruff3y, 2016.\n";
		std::cout << "Source can be found online at\n\n\tgithub.com\/scruff3y\/converter\n\n";
		std::cout << "Made using C++ in VS2015." << std::endl;
	}

	/*
	Converts the argument std::string to all lower case.
	*/
	void makeStdStringLowercase(std::string &input) {
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
		{ "yd", "y" },
		// FEET
		{ "foot", "f" },
		{ "feet", "f" },
		{ "'", "f"},
		// INCHES
		{ "i", "i" },
		{ "in", "i" },
		{ "inch", "i" },
		{ "inches", "i" },
		{ "\"", "i" },
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
		{ "seconds", "sec" },
		{ "secs", "sec" },
		// HOURS
		{ "hrs", "hrs" },
		{ "hour", "hrs" },
		{ "h", "hrs" },
		{ "hours", "hrs" },
		// MINUTES
		{ "min", "min" },
		{ "mins", "min" },
		{ "minute", "min" },
		{ "minutes", "min" },
		// DAY
		{ "day", "day" },
		{ "days", "day" },
		{ "d", "day" },
	// TEMPERATURES -----------------------------------------------------------
		// CELSIUS
		{ "cel", "cel" },
		{ "c", "cel" },
		{ "degreesc", "cel" },
		{ "degreec", "cel" },
		{ "degreescelsius", "cel" },
		{ "celsius", "cel" },
		// FARENHEIT
		{ "faren", "faren" },
		{ "f", "faren" },
		{ "degreesf", "faren" },
		{ "degreef", "faren" },
		{ "degreesfarenheit", "faren" },
		{ "degreefarenheit", "faren" },
		// KELVIN
		{ "kel", "kel" },
		{ "k", "kel" },
		{ "kelvin", "kel" }
	};

// MASSES ---------------------------------------------------------------------

	// This holds the conversion constants for converting masses.
	const double massConversionTable[CONVERTER_MASS_CONVERSION_TABLE_NUMEL][CONVERTER_MASS_CONVERSION_TABLE_NUMEL] = {
		//       kg                oz                stone             lb
		/* kg*/{ 1.00000000000000, 16.0/0.453592370, 1.00000000000000, 1/0.453592370000 },
		/* oz*/{ 0.453592370/16.0, 1.00000000000000, 1/224.0000000000, 1/16.00000000000 },
		/* st*/{ 6.35029318000000, 224.000000000000, 1.00000000000000, 14.0000000000000 },
		/* lb*/{ 0.45359237000000, 16.0000000000000, 1/14.00000000000, 1.00000000000000 }
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
		//		 metres            yards             feet              inches         miles          nautical mi
		/* m */{ 1.00000000000000, 1/0.914400000000, 1/0.304800000000, 1/0.025400000, 1/1609.344000, 1/1852.000000 },
		/* y */{ 0.91440000000000, 1.00000000000000, 3.00000000000000, 36.0000000000, 1/1760.000000, 0.9144/1852.0 },
		/* f */{ 0.30480000000000, 1/3.000000000000, 1.00000000000000, 12.0000000000, 1/5280.000000, 0.3048/1852.0 },
		/* i */{ 0.02540000000000, 1/36.00000000000, 1/12.00000000000, 1.00000000000, 1/63360.00000, 0.0254/1852.0 },
		/* mi*/{ 1609.34400000000, 1760.00000000000, 5280.00000000000, 63360.0000000, 1.00000000000, 1609.344/1852 },
		/*nmi*/{ 1852.00000000000, 1852/0.914400000, 1852/0.278709120, 66672/0.91440, 1852/1609.344, 1.00000000000 }
	};

	// This holds the mapping between a unit of LENGTH and its postion in the conversion table.
	const std::map<const std::string, const int> lengthConversionTableIndex = {
		{ "m", 0 },
		{ "y", 1 },
		{ "f", 2 },
		{ "i", 3 },
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
		/*sec*/{ 1.000000000, 1/3600.0000, 1/60.000000, 1/86400.000 },
		/*hrs*/{ 3600.000000, 1.000000000, 60.00000000, 1/24.000000 },
		/*min*/{ 60.00000000, 1/60.000000, 1.000000000, 1/1440.0000 },
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

	// TEMPERATURES -----------------------------------------------------------

	// This holds the conversion factors (multipliers) for converting temperatures.
	const double temperatureConversionTable[CONVERTER_TEMPERATURE_CONVERSION_TABLE_NUMEL][CONVERTER_TEMPERATURE_CONVERSION_TABLE_NUMEL] = {
		//       celsius  farenheit kelvin
		/* c */{ 1.000000, 9.00/5.0, 1.000000 },
		/* f */{ 5.00/9.0, 1.000000, 5.00/9.0 },
		/* k */{ 1.000000, 9.00/5.0, 1.000000 }
	};

	// This holds the conversion offsets (addition) for converting temperatures.
	const double temperatureConversionOffset[CONVERTER_TEMPERATURE_CONVERSION_TABLE_NUMEL][CONVERTER_TEMPERATURE_CONVERSION_TABLE_NUMEL] = {
		//       celsius   farenheit kelvin
		/* c */{ 0.000000, 32.00000, 273.1500 },
		/* f */{ -32.0000, 0.000000, 459.6700 },
		/* k */{ -273.150, -459.670, 0.000000 }
	};

	// This holds the mapping between a unit of TEMPERATURE and its postion in the conversion table.
	const std::map<const std::string, const int> temperatureConversionTableIndex = {
		{ "cel", 0 },
		{ "faren", 1 },
		{ "kel", 2 },
	};

	/*
	(Because I keep getting confused)...
	The above is to get a number from a string.
	The below is to get a string from a number.
	*/

	// This is to used to display the new unit of the converted time.
	const std::string temperatureStringUnitRepr[CONVERTER_TEMPERATURE_CONVERSION_TABLE_NUMEL] = {
		"celsius",
		"farenheit",
		"kelvin",
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
		// TEMPERATURES
		{ "cel", "TEMPER" },	// 'TEMPER' instead of 'TEMP' so it doesn't get confused with 'temporary'
		{ "faren", "TEMPER" },
		{ "kel", "TEMPER" }
	};

	/*
	This map is used to tell the converter how many elements are in the respective conversion tables.
	*/
	const std::map<const std::string, const int> numberOfElementsInConversionTable = {
		{ "MASS", CONVERTER_MASS_CONVERSION_TABLE_NUMEL },
		{ "LENG", CONVERTER_LENG_CONVERSION_TABLE_NUMEL },
		{ "TIME", CONVERTER_TIME_CONVERSION_TABLE_NUMEL },
		{ "TEMPER", CONVERTER_TEMPERATURE_CONVERSION_TABLE_NUMEL }
	};
}

int convert::IsNumberChar(char check) {
	if (((check >= '0') && (check <= '9')) || (check == '.')) return 1;
	return 0;
}

int convert::IsLetterChar(char check) {
	if ((check >= 'A') && (check <= 'Z')) return 1;
	if ((check >= 'a') && (check <= 'z')) return 1;
	if (check == 0x22) return 1; // "
	if (check == 0x27) return 1; // '
	if (check == 0x5c) return 1; /* \ */
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

void convert::conversion(struct convert::conversionParameters params) {
	if (params.indexOfUnitToConvertFrom == -1) return;
	for (int indexOfUnitToConvertTo = 0; indexOfUnitToConvertTo < params.numOfElInConversionTable; indexOfUnitToConvertTo++) {
		if (indexOfUnitToConvertTo != params.indexOfUnitToConvertFrom) {
			double converted = params.value * params.conversionTable[indexOfUnitToConvertTo];
			std::cout << std::to_string(converted) << " " << params.stringRepOf[indexOfUnitToConvertTo] << std::endl;
		}
	}
}

struct convert::conversionParameters convert::getConversionParameters(double value, std::string unit) {
	std::string dimensionOfUnitToConvert = dimensionOf.at(unit);

	// struct fields:
	// double value
	// int indexOfUnitToConvertFrom
	// int numOfElInConversionTable
	// const double* conversionTable
	// const std::string * stringRepOf

	if (AreSameString(dimensionOfUnitToConvert, "MASS")) {
		struct conversionParameters output;
		output.value					= value;
		output.indexOfUnitToConvertFrom = massConversionTableIndex.at(unit);
		output.numOfElInConversionTable = CONVERTER_MASS_CONVERSION_TABLE_NUMEL;
		output.conversionTable			= massConversionTable[massConversionTableIndex.at(unit)];
		output.stringRepOf				= massStringUnitRepr;
		return output;
	}
	else if (AreSameString(dimensionOfUnitToConvert, "LENG")) {
		struct conversionParameters output;
		output.value					= value;
		output.indexOfUnitToConvertFrom = lengthConversionTableIndex.at(unit);
		output.numOfElInConversionTable = CONVERTER_LENG_CONVERSION_TABLE_NUMEL;
		output.conversionTable			= lengthConversionTable[lengthConversionTableIndex.at(unit)];
		output.stringRepOf				= lengthStringUnitRepr;
		return output;
	}
	else if (AreSameString(dimensionOfUnitToConvert, "TIME")) {
		struct conversionParameters output;
		output.value					= value;
		output.indexOfUnitToConvertFrom = timeConversionTableIndex.at(unit);
		output.numOfElInConversionTable = CONVERTER_TIME_CONVERSION_TABLE_NUMEL;
		output.conversionTable			= timeConversionTable[timeConversionTableIndex.at(unit)];
		output.stringRepOf				= timeStringUnitRepr;
		return output;
	}
	else if (AreSameString(dimensionOfUnitToConvert, "TEMPER")) {
		/*
		Converting temperature isn't a straight forward multiplication by a
		factor, there is also an offset involved, so the conversion is handled
		here by extra logic not found in conversion().
		*/
		for (int indexOfUnitToConvertTo = 0; indexOfUnitToConvertTo < CONVERTER_TEMPERATURE_CONVERSION_TABLE_NUMEL; indexOfUnitToConvertTo++) {

			int indexOfUnitToConvertFrom = temperatureConversionTableIndex.at(alternateNamesForUnits.at(unit));

			if (indexOfUnitToConvertFrom != indexOfUnitToConvertTo) {
				double converted = value;
				double conversionOffset = temperatureConversionOffset[indexOfUnitToConvertFrom][indexOfUnitToConvertTo];
				if (conversionOffset < 0.0) {
					converted += conversionOffset;
					converted *= temperatureConversionTable[indexOfUnitToConvertFrom][indexOfUnitToConvertTo];
				}
				else {
					converted *= temperatureConversionTable[indexOfUnitToConvertFrom][indexOfUnitToConvertTo];
					converted += conversionOffset;
				}
				std::cout << std::to_string(converted) << " " << temperatureStringUnitRepr[indexOfUnitToConvertTo] << std::endl;
			}
		}
	}
}

void convert::parseAndConvert(std::string input) {
	unsigned int i;

	if (convert::AreSameString(input, std::string("help"))) {
		convert::displayHelp();
		return;
	}
	if (convert::AreSameString(input, std::string("about"))) {
		convert::displayAbout();
		return;
	}

	std::string numberToConvert = "0";
	for (i = 0; i < input.length(); i++) {
		if (convert::IsNumberChar(input.at(i))) {
			numberToConvert += input.at(i);
		}
		else break;
	}
	if (i == 0) {
		std::cout << "Could not parse input. Type \"help\" for usage" << std::endl;
	}
	else {
		double valueToConvert = std::stod(numberToConvert);

		std::string unitToConvert = "";
		for (i; i < input.length(); i++) {
			if (convert::IsLetterChar(input.at(i))) unitToConvert += input.at(i);
		}
		if (unitToConvert.length() == 0) {
			std::cout << "Please enter a unit after the value." << std::endl;
			return;
		}

		if (alternateNamesForUnits.find(unitToConvert) != alternateNamesForUnits.end()) {
			unitToConvert = alternateNamesForUnits.at(unitToConvert);
			conversion(getConversionParameters(valueToConvert, unitToConvert));
		}
		else {
			std::cout << "Unit: \"" << unitToConvert << "\" was not recognised" << std::endl;
			std::cout << "Type \"help\" for help message." << std::endl;
		}
	}
}

#endif
