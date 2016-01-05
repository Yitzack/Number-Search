/*This program finds the self-referential number described by Dr. James Grime (@singingbanana). The first digit is the number of 0s, the second is the number of 1s, ... the 10th digit is the number of 9s. I was going to try to make a matrix that described the number meaning that the eigenvectors would be the answer, but I don't think it exists. You could use logic and I immediately determined by proof by contradiction that the first digit can't be 0, otherwise it would be 1. After that, it was more think than I wanted. So I turned to my favorite force, brute force.
Recommended run method:
g++ Brute\ Force.cpp -O3
./a.out 0 &
./a.out 1 &
./a.out 2 &
./a.out 3 &
./a.out 4 &
./a.out 5 &
./a.out 6 &
./a.out 7 &
./a.out 8 &
./a.out 9
*/
#include<iostream>
#include<cstdlib>
using namespace std;

void Increment(short[10]);
bool Check(short[10]);
bool End(short[10]);
bool Progress(short[10]);

int main(int argc, char* argv[])
{
	short Number[10] = {atoi(argv[1]),0,0,0,0,0,0,0,0,0};
	bool Condition;

	do
	{
		Increment(Number);
		Condition = Check(Number);
		if(Condition)
		{
			for(short i = 0; i < 10; i++)
				cout << Number[i];
			cout << endl;
		}	//May be more than 1 answer, unquieness was not gurenteed in the video.
	}while(End(Number));

	return(0);
}

void Increment(short Number[10])
{
	short i = 9;
	while(Number[i] == 9)
	{
		Number[i] = 0;
		i--;
	}
	Number[i]++;
}

bool Check(short Number[10])
{
	short Condition[10] = {0,0,0,0,0,0,0,0,0,0};
	short i;

	for(i = 0; i < 10; i++)
		Condition[Number[i]]++;

	for(i = 0; i < 10; i++)
		if(Condition[i] != Number[i])
			return(false);	//If any number digit doesn't satisfy the condition, return false
	return(true);	//else return true
}

bool End(short Number[10])
{
	for(short i = 1; i < 10; i++)
		if(Number[i] != 9)
			return(true);	//If any digit other than the first one is not 9, keep going
	return(false);	//else stop
}
