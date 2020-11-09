// take a binary file that may contain integers and double and convert it into a binary file of integers and floats
// the structure of the file is given as a two dimensional array such that
//
// int
// int double double ... 
// int double double ...
// int double double ...
// ...
// 
// where the first int represents the major size and the other integers represent the minor size


#include <iostream>
#include <fstream>

#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define RESET   "\033[0m"

using namespace std;
int main(int argc, char *argv[])
{

	char* filename;
	if (argc > 1)
		filename = argv[1];
	else
	{
		cout << ' ' << endl;
		cout <<BOLDRED<< "No input file provided!" <<RESET<< endl;
		cout <<BOLDRED<< "Input file name comes as the first command line argument." <<RESET<<endl;
		cout <<BOLDRED<< "Process terminated!" <<RESET<<endl;
		cout << ' ' << endl;
		return(1);
	}


	cout << ' ' << endl;
	cout <<BOLDYELLOW<< "Program has started ... " <<RESET<<endl;
	cout << "Analysing the file ... " << endl;

	ifstream in_file(filename, ios::in | ios::binary);
	ofstream out_file("output.bin", ios::out | ios::binary);

//	set position to the end
	in_file.seekg(0, ios::end);	
	cout << "The file size is " << in_file.tellg() << " bytes" << endl;
	cout << "Do you wish to continue? (y/n) ";
	char yn;
	cin >> yn;

	// if 'y' or 'Y' continue, else terminate the program
	if (yn == 'y' || yn == 'Y')
	{}
	else
	{
		cout <<BOLDRED<< "Process terminated by user!" <<RESET<<endl;
		return(0);
	}


	// loop until the end of file
	int value_int;
	double value_double;

	// set position back to the beginning
	in_file.seekg(0, ios::beg);
	in_file.read((char*) &value_int, sizeof(int));
	int major_size = value_int;
	cout << "major_size = " << major_size << endl;

	out_file.write(reinterpret_cast<const char *>(&value_int), sizeof(int));

	for (int i=0; i<major_size; i++)
	{
		in_file.read((char*) &value_int, sizeof(int));
		int minor_size = value_int;	
		cout << "minor_size = " << minor_size << endl;	

		out_file.write(reinterpret_cast<const char *>(&value_int), sizeof(int));

		
		for (int j=0; j<minor_size; j++)
		{
			in_file.read((char*) &value_double, sizeof(double));	
			cout << value_double << endl;

			float value_float = (float)value_double;
			out_file.write(reinterpret_cast<const char *>(&value_float), sizeof(float));

		}
	}	
	in_file.close();

	cout <<BOLDGREEN<< "Program has finished!" <<RESET<<endl;
	cout <<BOLDGREEN<< "The file is saved under the name output.bin" <<RESET<<endl;
	cout << ' ' << endl;	

	return(0);

}

