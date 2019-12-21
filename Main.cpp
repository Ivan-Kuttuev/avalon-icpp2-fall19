#include"Exam.hpp"
#include <iostream>
#include <fstream>


using namespace std;

int main()
{

	int choise;
	cin >> choise;

	switch (choise)
	{
	case 1:
		add();
		break;
	case 2:
		//edit();
		break;
	case 3:
		find();
		break;
	case 4:
		//view_list();
		break;
	case 5:
		show_statistics();
		break;

	default:
		break;
	}
}