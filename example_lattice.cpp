/*This program produces an output file that can be plotted in vmd. The plot is either an fcc or bcc lattice based on the user selection. The atoms are Carbon.*/

#include <iostream>  // For input/output 
#include <fstream> // For streaming data to the output file
#include <string> // For strings

using namespace std;

int main()
{


int rows, columns, stacks; // define variables to be used
string outputfile, type;

//main menu

cout << "\nWelcome to the Carbon Lattice Generator. The coordinates generated will be placed in a file specified by you and can easily be plotted in vmd.\n\n";
cout << "Please enter 'bcc' if you would like a body-centered cubic lattice or 'fcc' if you would like a face-centered cubic lattice: ";
cin >> type; 
cout << "How many rows of carbon atoms would you like: ";
cin >> rows;
cout << "How many columns of carbon atoms would you like: ";
cin >> columns; 
cout << "How many stacks of carbon sheets would you like: ";
cin >> stacks;
cout << "What is the name of the output file where you would like to store your coordinates (e.g. data.xyz): ";
cin >> outputfile;

//define output file and open it up

ofstream out;
out.open(outputfile.c_str());

//define the initial coordinates of the first carbon atom

double c0_x = -2.0, c0_y = -2.0, c0_z = -2.0, c1_x, c1_y, c1_z = -1.0;

double x0_values[columns], y0_values[rows], x1_values[columns], y1_values[rows], z0_values[stacks], z1_values[stacks];

//if user select the bcc lattice

if (type == "bcc")
{

out << 2*rows*columns*stacks << "\n\n"; // print how many atoms there are

for (int j = 0; j < stacks; j ++)   //for loops to produce the 3d points
{
	c0_z += 2.0;
	c1_z += 2.0;
	z0_values[j] = c0_z;
	z1_values[j] = c1_z;

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
		out << 	"C\t" << x0_values[i] << "\t" << y0_values[n] << "\t" << z0_values[j] << endl;
	
		out << "C\t" << x1_values[i] << "\t" << y1_values[n] << "\t" << z1_values[j]  << endl;
			
	}
}
}
}

// if the user selects the fcc lattice

if (type == "fcc")
{

out << 4*rows*columns*stacks << "\n\n";  // print out the number of atoms

for (int j = 0; j < stacks; j ++) // for loops to print the atoms coordinates
{
        c0_z += 2.0;
        c1_z += 2.0;

        z0_values[j] = c0_z;
        z1_values[j] = c1_z;

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
                out <<  "C\t" << x0_values[i] << "\t" << y0_values[n] << "\t" << z0_values[j] << endl;
                out << "C\t" << x1_values[i] << "\t" << y1_values[n] << "\t" << z0_values[j]  << endl;
                out << "C\t" << x0_values[i] << "\t" << y1_values[n] << "\t" << z1_values[j] << endl;
		out << "C\t" << x1_values[i] << "\t" << y0_values[n] << "\t" << z1_values[j] << endl; 
        }
}
}
}

cout << "\nThe lattice vector for your structure is {" << 2*columns << " " << 2*rows << " " << 2*stacks << "}\n" << endl; 


// close the output file and terminate the program
out.close();
return 0;
}







