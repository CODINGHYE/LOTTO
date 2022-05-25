#include <iostream>
#include "Lotto.h"
using namespace std;

extern int cnt;
int main()
{
	srand(time(NULL));
	int n;
	int choice;
	Lotto lotto;
	while (1) 
	{
		cout << "1. Draw  2. Show  3. Stat  4. Exit:: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cnt++;
			lotto.draw();
			break;
		case 2:
			cout << "최근으로부터 몇번째 draw를 보고 싶나요? :";
			cin >> n;
			lotto.show(n);
			break;
		case 3:
			lotto.stat();
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}
	return 0;
	
}