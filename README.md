# C++ utilities

## binary_double2float
This program takes a binary file containing vectors of doubles and converts it into the same vector structure of floats. It's aim is to reduce the size of the file. 

The structure of the file is as follow:

```
int
int double double ... 
int double double ...
...
int double double ... 
```

where the first integer represents the nmajor size (number of vectors), and every other integer represents the minor size (size of the vector). 

### Getting started with the program
Start the compiled program and you'll be instructed to enter the name of the input file using a command line argument.
