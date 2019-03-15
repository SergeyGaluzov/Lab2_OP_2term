#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
class Country
{
public:
	string name;
	int *marks;
	int points;
	int sum_of_points;
	~Country()
	{};
};
int reading_the_number_of_the_countries(ifstream &fin, string s)
{
	getline(fin, s);
	return stoi(s);
}
Country* creating_the_array_of_the_objects_countries(int n)
{
	Country *arr = new Country[n];
	for (int i = 0; i < n; i++)
	{
		arr[i].marks = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		arr[i].points = 0;
		for (int j = 0; j < n; j++)
		{
			arr[i].marks[j] = 0;
		}
	}
	return arr;
}
void filling_the_objects_of_the_array(ifstream &fin, int n, string s, Country* arr)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		getline(fin, s);
		for (int j = 0; j < s.length(); j++)
		{
			if ((s[j] == ','))
			{
				count++;
			}
			else
			{
				if (!count)
				{
					arr[i].name += s[j];
				}
				else
				{
					arr[i].marks[count - 1] = 10 * arr[i].marks[count - 1] + int(s[j]) - '0';
				}
			}
		}
		count = 0;
	}
}
void console_output_of_the_input_file(int n, Country *arr)
{
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].name << " ";
		for (int j = 0; j < n; j++)
		{
			cout << arr[i].marks[j] << " ";
		}
		cout << endl;
	}
}
void scoring_the_points(int n, Country *arr)
{
	int p[10] = { 12, 10, 8, 7, 6, 5, 4, 3, 2, 1 };
	int *temp = new int[n];
	for (int u = 0; u < n; u++)
	{
		for (int i = 0; i < n; i++)
		{
			temp[i] = arr[i].marks[u];
		}
		for (int r = 0; r < 10; r++)
		{
			int imax = 0;
			int max = 0;
			for (int i = 0; i < n; i++)
			{
				if (temp[i] > max)
				{
					max = temp[i];
					imax = i;
				}
			}
			arr[imax].points += p[r];
			temp[imax] = 0;
		}
	}
	delete[] temp;
	temp = nullptr;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].name << " " << arr[i].points;
		cout << endl;
	}
}
void removing_the_array_with_objects(int n, Country *arr)
{
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i].marks;
	}
}
