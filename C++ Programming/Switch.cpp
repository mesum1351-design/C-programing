
# include<iostream>
using namespace std ;

int main()
{
	int points;			
	char grade = 'A';
	switch (grade)
	{
		case 'A':
			points = 4.0;
			break;
			case'B':
				points = 3.0;
				break;
				case'C':
					points = 2.0;
					break;
					default:
						points = 0.0;
	}
	cout<< points;
	
}
