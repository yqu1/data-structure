#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	int age, F(0), M(0), count(0), number, sum(0);
	double average;
	char sex;
	ifstream file;
	file.open("test.txt");

	while(!file.eof())
	{
		file>>number>>age>>sex;

		if(sex=='F') F++;
		else M++;
		sum+=age;
		count++;
	}

	file.close();

	average=double(sum/count);
	if(F>M) sex='F';
	else sex='M';

	ofstream file1;
	file1.open("test.txt",ios::app);
	file1<<0<<average<<sex<<endl;
	file1.close();

}