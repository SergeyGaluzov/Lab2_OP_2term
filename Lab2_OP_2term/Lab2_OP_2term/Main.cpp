#include <iostream>
#include <string>
#include <fstream>
#include "Our_lib.h"
using namespace std;
int main()
{
	ifstream fin;
	fin.open("evrovision.csv");
	if (!fin.is_open())
	{
		cout << "Input file can not be opened!" << endl;
	}
	else
	{
		string s;
		int n = reading_the_number_of_the_countries(fin, s);
		Country *arr = creating_the_array_of_the_objects_countries(n);
		filling_the_objects_of_the_array(fin, n, s, arr);
		console_output_of_the_input_file(n, arr);
		scoring_the_points(n, arr);
		top_winners(arr, n);
		removing_the_array_with_objects(n, arr);
	}
	fin.close();
	system("pause");
}