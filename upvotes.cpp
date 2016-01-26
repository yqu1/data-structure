#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void calc_upvotes(vector<long int > V, long int Wsize);
void calc_win(vector<long int > V, long int left, long int right);
int comp(long int a, long int b);
long int trend_num(long int k);

int main()
{
	long int Wsize, data, size;
	string l1, l2;
	vector<long int > V;

	getline(std::cin, l1);

	getline(std::cin, l2);

	size = stoi(l1.substr(0));
	Wsize = stoi(l1.substr(2));

	for(long int i = 0; i < l2.length(); i += 2)
	{
		if(l2.substr(i) != " ")
		{
			long int s = stoi(l2.substr(i));
			V.push_back(s);
		}
	}

	calc_upvotes(V, Wsize);
}

void calc_upvotes(vector<long int > V, long int Wsize)
{
	long int left(0), right(left + Wsize - 1);
	while(right < V.size())
	{
		calc_win(V, left, right);
		left ++;
		right ++;
	}

}

void calc_win(vector<long int > V, long int left, long int right)
{
	long int a(left), b(left + 1), non_dec(0), non_inc(0);
	vector<long int > T;

	while(b <= right)
	{
		T.push_back(comp(V[a],V[b]));
		a++;
		b++;
	}

	while(!T.empty())
	{
		long int first(T[0]), third(0), dis_point(0), second(0), fourth(0) mark(0);

		for(long int i = 1; i < T.size(); i ++)
		{
			if(first != 0 && T[i] == -first) 
			{
				dis_point = i - 1;
				mark = 1; //note that this block is ran
				break;
			}

			else if(first != 0 && T[i] == first) third = i;

			else if(first == 0 && T[i] == 0)

			else if(first == 0 && second == 0) fourth = i;
			{
				if(second == 0)
				{
					second = T[i]; 
					third = i;
					continue;
				}

				else if(T[i] == -second)
				{
					dis_point = i - 1;
					break;
				}

				third = i; //T[i] == second
			}
		}

		if(dis_point == 0 && mark == 0) dis_point = T.size() - 1;

		if(first == 1) 
		{	
			if(T.back() == 0) non_dec = non_dec + trend_num(dis_point + 2) - trend_num(T.size() - 1 - third);
			else non_dec += trend_num(dis_point + 2);
		}

		else if(first == -1) 
		{	
			if(T.back() == 0) non_inc = non_inc + trend_num(dis_point + 2) - trend_num(T.size() - 1 - third);
			else non_inc += trend_num(dis_point + 2);
		}

		else
		{
			if(second == 1) non_dec = non_dec + trend_num(dis_point + 2) - trend_num(fourth + 1);

			else if(second == -1) non_inc = non_inc + trend_num(dis_point + 2) - trend_num(fourth + 1);

		}

		T.erase(T.begin(), T.begin() + third + 1);
	}

	cout << non_dec - non_inc << endl;
}

int comp(long int a, long int b)
{
	if(b > a) return 1;
	else if(b < a) return -1;
	else return 0;
}

//total number of non_inc/non_dec in a subrange of size k: k * (k - 1) / 2

long int trend_num(long int k)
{
	if(k > 1)
		return k * (k - 1) / 2;
	else if(k == 1)
		return 1;

	return 0;
}


//1.	while array not empty
//	1. 	read the first number (after previous discontinuance)
//	2. while no discontinue, continue read into array2
//		1. if first number is non zero, discontinue when reach negative of that number, if first number is 0, continue reading, record the first non-zero number('second', initiated to 0 when not in use) and discontinue when reach the negative of that number
//	3. if first number in array2 is nonzero, calculate trend_num and update accordingly, if first number is 0, check 'second', calculate trend_num and update accordingly. 
//	4. if array2 ends at nonzero number, discard all elements before discontinue point, if ends at 0, preserve previous 0s and discard all other before discontinue point.
//2. return non_dec - non_inc;

//problem: 11001, 00111, continuous 0 sequence not counting non_inc 
