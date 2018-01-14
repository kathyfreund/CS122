#include "menu.h"


Menu::Menu()
{

}


Menu::~Menu()
{

}



int Menu::display_menu()
{
	int choice = 0;

	cout << "Please select one of the following options:" << endl;
	cout << "1.Import Course List" << endl;
	cout << "2.Load Master List" << endl;
	cout << "3.Store Master List" << endl;
	cout << "4.Mark Absences" << endl;
	cout << "5.Edit Absences" << endl;
	cout << "6.Generate Report" << endl;
	cout << "7.Exit" << endl;

	cin >> choice;
	return choice;
}


int Menu::display_submenu()
{
	int choice = 0;
	cout << "Which option would you like?" << endl;
	cout << "1.Generate report for all students - show most recent absence." << endl;
	cout << "2.Generate report for student who exceed inputted amount of absences" << endl;

	cin >> choice;
	return choice;
}
