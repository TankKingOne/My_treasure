#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	string str;
	cin >> str;
	//cout << str;
	string ret;
	int begin = 0;
	if (str[0] == '-')
	{
		ret += '-';
		begin = 1;
	}
	char key[10];
	int i;
	for(i = 1; i <= 9; ++i)
	{
		cin >> key[i];
	}



	int size = str.size();
	i = 0;
	for (i = begin; i < size; ++i)
	{
		ret += key[str[i]-'0'];
	}

	cout << ret << endl;

	system("pause");
	return 0;
}