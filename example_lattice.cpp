#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{


int rows, columns, stacks;
string outputfile, type;

cout << "\nWelcome to the Carbon Lattice Generator.\n\n";
cout << "Please enter 'bcc' if you would like a body-centered cubic lattice or 'fcc' if you would like a face-centered cubic lattice: ";
cin >> type; 
cout << "How many rows of carbon atoms would you like: ";
cin >> rows;
cout << "How many columns of carbon atoms would you like: ";
cin >> columns; 
cout << "How many stacks of carbon sheets would you like: ";
cin >> stacks;
cout << "What is the name of the output file (e.g. data.xyz): ";
cin >> outputfile;

ofstream out;
out.open(outputfile.c_str());


out << 2*rows*columns*stacks  << "\n\n";

if (type == "bcc")
{

double c0_x = -2.0, c0_y = -2.0, c0_z = -2.0, c1_x, c1_y;

double x0_values[columns], y0_values[rows], x1_values[columns], y1_values[rows];

for (int j = 0; j < stacks; j ++)
{
	c0_z += 2.0;
	c0_x = -2.0;
for (int i = 0; i < columns; i ++)
{	
	c0_x += 2.0;
	c1_x = c0_x + 1.0;
	x0_values[i] = c0_x;
	x1_values[i] = c1_x;

	c0_y = -2.0;
	for (int n = 0; n < rows; n ++)
	{
		c0_y += 2.0;
		c1_y = c0_y + 1.0;
		y0_values[n] = c0_y;
		y1_values[n] = c1_y;
		out << 	"C\t" << x0_values[i] << "\t" << y0_values[n] << "\t" << c0_z << endl;
		out << "C\t" << x1_values[i] << "\t" << y1_values[n] << "\t" << c0_z << endl;
	}
}
}
}
out.close();
return 0;
}






