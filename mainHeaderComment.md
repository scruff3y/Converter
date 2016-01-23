This file contains the header comment that was originally in main.cpp. It's where I put all of my goals and a lot of my thoughts before starting.

----------------------------------------------------------------------------------------------

Universal Converter, Version 0;
By: scruff3y, December 2015

User types in number. Number is then displayed converted to a variety of different units.

Goals

1. Zeroth-order Quantities (distance, mass, temp, time)

Convert distance to various other units.
Convert mass.
Convert temperature.
Convert time.
Recognise orders-of-magnitude.
Recognise non-standard units.
Allow lexing of parentheses, for precise unit definition.

2. Higher-order Quantities (rates of change)

Recognise and convert exponentiated properties.															
Convert rates per time to units/second.																	
Convert rates per *thing* to units/thing. (An abstraction of the above).								
Add option to keep either top unit, bottom unit or neither (defaults to SI).							

3. User Interface/Computer-Related stuff

Ensure that internal variables are of a type large enough to minimise floating-point rounding/overflow errors.
Decide most apropriate conversion to make. (?) Pure SI units in Scientific Notation, Most-Readable SI, Most-Readable Imperial, one 'extreme', e.g Planc Lengths or Lightyears (chosen psuedo-randomly).
Add optional command to specify output conversion.
Add command-line functionality (e.g, "convert 5km" should act on the 5km).									

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

Thoughts:

This matrix should probably be defined within a member function of some 'Quantity' class, with access to the discussed enum. This way, the *only* way to convert a value from one type to another is to pass a reference to that value and the desired type to that function, which can then check for invalid types/indices and such. Lets call this the 'converter' function.

The converter function should probably be defined separately for each Dimension, so that attempting to change a unit from one dimension to another should throw an error (at you, the dev, not the user).

---------------------------------------------------------------------

Glossary:

"Most Readable"

The value expressed with appropriate prefixes, i.e 250 Kilograms instead of 250,000 grams

--

"Dimension"

The most basic types described here. These are MASSES, DISTANCES (or LENGTHS) and TIME.

All other units are derived from these basic dimensions, for example, energy = m\*c^2, therefore having dimensions : MASS*(DISTANCE^2)/(TIME^2).

This means anything matching that description is a unit of energy; e.g grams * (inch/year)^2 is a valid (though odd) unit of energy.
