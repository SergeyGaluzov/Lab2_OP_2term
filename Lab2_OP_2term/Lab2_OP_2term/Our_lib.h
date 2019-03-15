#pragma once
using namespace std;
class Country;
int reading_the_number_of_the_countries(ifstream &fin, string s);
Country* creating_the_array_of_the_objects_countries(int n);
void filling_the_objects_of_the_array(ifstream &fin, int n, string s, Country* arr);
void console_output_of_the_input_file(int n, Country *arr);
void removing_the_array_with_objects(int n, Country *arr);
