#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	long long num;
	int endofnum = 0;
	int s = 1;


	
	cin >> num;
	for (int j = 0; j < N; j++)
	{
		endofnum = num / 1'000'000'000'000;

		for (long long i = 1'000'000'000'000; i > 10; i /= 10)
		{
			
				if (s % 2 == 1)
				{
					endofnum = endofnum + (num % i / (i / 10) * 3 );
				}
				else
				{
					endofnum = endofnum + num % i / (i / 10) ;
				}
				s++;
				
		}
		endofnum = endofnum % 10;
		endofnum = 10 - endofnum;
		if (endofnum == num % 10)
		{
			cout << "valid" << endl;
		}
		else
		{
			cout << "invalid" << endl;
		}
	}
	

	
	
}