UIntvar
=======

Conversion program using C++


Uintvar is a binary numbering system, the first bit in an byte is either a 0 or 1, 1 signifying that the there will be another byte, and 0 signifying it is the end of the represented number.
Example: 10000000 in would, in uintvar, be effectively equal to 10000001 00000000 (the first one says that it is not the last byte, numerical 1 is moved, and the first 0 in the second byte says its the last byte.


Dec2Uint:

Converts a decimal number to a uintvar represented in hexadecimal format.

Uint2Dev

Converts a uintvar to decimal format.
