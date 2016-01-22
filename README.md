# Converter
Displays a quantity in a variety of alternate units.

Copied from main.cpp header comment{

Universal Converter, Version 0;
By: scruff3y, December 2015

User types in number. Number is then displayed converted to a variety
of different units.


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

Thoughts/Notes:

This matrix should probably be defined within a member function of
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
