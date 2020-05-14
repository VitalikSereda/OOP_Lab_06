#include <iostream>
#include "D_List.hpp"

using namespace std;


int main()
{
	D_List<int> listInt;
	listInt.Add_begin(5);
	listInt.Add_begin(15);
	listInt.Add_begin(23);
	listInt.Add_begin(14);
	listInt.Add_end(11);
	listInt.Add_end(12);
	listInt.Add_end(15);
	listInt.Add_end(34);
	listInt.Add_end(19);
	cout << listInt << endl;
	listInt.reversList();
	cout << listInt << endl;
	D_List<char> listChar;
	for (int i = 'a'; i <= 'k'; i++)
	{
		listChar.Add_end(i);
	}
	cout << listChar << endl;
	listChar.reversList();
	cout << listChar << endl;
}
