/*
Universal Converter, Version 0;
By: scruff3y, December 2015

User types in number. Number is then displayed converted to a variety
of different units.

Goals																																					Checkbox:
1. Zeroth-order Quantities (distance, mass, temp, time)
Convert distance to various other units.																e.g metres to feet, or feet/inches.						[]
Recognise and convert mass.																				e.g kilo to lb											[]
Recognise and convert temperature.																		e.g C to K, F											[]
Recognise and convert time.																				e.g seconds to seconds/minutes, hours/minutes			[]
Recognise orders-of-magnitude.																			e.g 1000g and 1kg should both work.						[]
Recognise non-standard units.																			e.g energy (ML^2/T^2), Newton (ML/T^2),					[]
Allow lexing of parentheses, for precise unit definition.												e.g k(m^2) VS (km)^2.									[]

2. Higher-order Quantities (rates of change)
Recognise and convert exponentiated properties.															e.g ft^2 to m^2											[]
Convert rates per time to units/second.																	e.g ft/s to m/s, k/h, M/h								[]
Convert rates per *thing* to units/thing. (An abstraction of the above).								e.g ft/kg to m/kg										[]
Add option to keep either top unit, bottom unit or neither (defaults to SI).							e.g Choose between m/kg to ft/kg... OR m/kg to m/lb...	[]

3. User Interface/Computer-Related stuff
Ensure that internal variables are of a type large enough to minimise floating-point rounding/overflow errors.													[]
Decide most apropriate conversion to make. (?) Pure SI units in Scientific Notation, Most-Readable SI,															[]
	Most-Readable Imperial, one 'extreme', e.g Planc Lengths or Lightyears (chosen psuedo-randomly).															--
Add optional command to specify output conversion.																												[]
Add command-line functionality (e.g, "convert 5km" should act on the 5km).																						[]

Lists of units (don't forget OOM, micro, milli, kilo, mega etc.);

Distance;
Planc Length, Inch, Foot, Yard, Metre, Mile, Astronomical Unit, Parsec, Lightyear, 

Mass;
Atomic Mass Unit, Ounce, Pound, Kilogram, Solar Mass, 

Temperature;
Kelvin, Celsius, Farenheit,

Time;
Planc Time, Second, Minute, Hour, Day, Week, Year (365 days, simplified),

-------------------------------------------------------------------------------

Grammar;

expr = NUMBER UNIT

Where NUMBERs are positive scalar real numbers, and UNITs are the
unit of the 

-------------------------------------------------------------------------------

Notes;
USE MATRICES to store the coefficients, i.e

/ m i f K
m 1 x x x
i x 1 x x
f x x 1 x
K x x x 1

Read like "rows per column"
If you use an enum to specify dimension, and set the matrix up correctly, you
can use the enum to index the matrix directly.
e.g to convert QUANTITY from it's type to another arbitrary type T,

		QUANTITY *= matrix[QUANTITY.type][T]

For a more real example, say QUANTITY was in inches, and it was needed in
feet. First, define an enum;
	
		enum {INCH, FEET};

Now, we store the conversion coefficients in a matrix, using our enum;

		coEffcients[INCH][FEET] = 12;

Because there are 12 inches in a foot. Similarly;

		coEfficients[FEET][INCH] = 1/12;

Thus, to convert QUANTITY to feet, all we need to do is this;

		QUANTITY *= coEfficients[QUANTITY.type][T]

Thoughts: This matrix should probably be defined within a member function of
	some 'Quantity' class, with access to the discussed enum. This way, the
	*only* way to convert a value from one type to another is to pass a
	reference to that value and the desired type to that function, which can
	then check for invalid types/indices and such. Lets call this the
	'converter' function.

	The converter function should probably be defined separately for each
	Dimension, so that attempting to change a unit from one dimension
	to another should throw an error (at you, the dev, not the user).

---------------------------------------------------------------------

Glossary:

"Most Readable"
	The value expressed with appropriate prefixes, i.e 250 Kilograms instead of 250,000 grams

"Dimension"
	The most basic types described here. These are MASSES, DISTANCES (or LENGTHS) and TIME.

	All other units are derived from these basic dimensions, for example, energy = m*c^2, therefore
	having dimensions : MASS*(DISTANCE^2)/(TIME^2).

	This means anything matching that description is a unit of energy; e.g grams * (inch/year)^2 is a valid
	(though odd) unit of energy.
*/

#include <iostream>
#include <string>
#include <map>

int IsNumberChar(char);

int main(int argc, char *argv[]) {
	double massConversionTable[4][4] = {
		//  kg      oz      stone   lb
		/* kg*/ { 1.0000, 35.274, 0.1575, 2.2046 },
		/* oz*/ { 35.274, 1.0000, 224.00, 16.000 },
		/* st*/ { 6.3502, 224.00, 1.0000, 14.000 },
		/* lb*/ { 0.4536, 16.000, 0.0714, 1.0000 }
	};

	std::map<std::string, int> stringToInt = {
		{ "kg", 0 },
		{ "oz", 1 },
		{ "st", 2 },
		{ "lb", 3 }
	};

	std::string intToString[4] = { "kg", "oz", "st", "lb" };

	while (true) {
		std::cout << "\nconvert:>";
		std::string input;
		std::getline(std::cin, input);

		std::string numberToConvert = "0";
		for (signed int i = 0; i < input.length(); i++) {
			if (IsNumberChar(input.at(i))) numberToConvert += input.at(i);
			else break;
		}

		double valueToConvert = std::stod(numberToConvert);
		int temp = input.length() - 1;
		std::string unitToConvert;
		unitToConvert = input.at(temp - 1);
		unitToConvert += input.at(temp);

		for (int i = 0; i < 4; i++) {
			if (stringToInt.at(unitToConvert) != i) {
				double converted = valueToConvert * massConversionTable[stringToInt.at(unitToConvert)][i];
				std::cout << std::to_string(converted) << " " << intToString[i] << std::endl;
			}
		}
	}

	return 0;
}

int IsNumberChar(char check) {
	if ( ((check >= '0') && (check <= '9')) || (check == '.') ) return 1;
	return 0;
}
