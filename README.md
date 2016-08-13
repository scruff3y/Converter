# Converter
Displays a quantity in a variety of alternate units.

Currently a command-line application.

    convert [quantity][unit]

For example;

    convert 10kgs | convert 10 kilos | convert 5 seconds

Are all valid calls. Open with no parameters to open in loop mode (converter will prompt for values until exit). Additional information can be found in mainHeaderComment.md

---

So far;
-
Masses:

    kilograms, ounces, pounds, stone.

Distances:

    meters, yards, feet, inches, miles, nautical miles.

Times:

    seconds, minutes, hours, days.

---

Now accepting command-line arguments! (23/01/16)

Also converts various measures of distance and time! (24/01/16)

---

#Next up : Combinational units.
For example

    m/s
    kilograms/yard
etc...

----

I'm using VS2015, and honestly I'm not sure how it's set up so if you can't get it to compile then it's Microsoft's fault...

Antony (scruff3y) 2016.
