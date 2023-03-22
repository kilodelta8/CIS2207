#include <iostream>
#include <iomanip>
#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include "Rainfall.h"

//protos
char mainMenu();
Rainfall& addMonth();
void print(LinkedList<Rainfall>* list, int count);
void print(LinkedList<Rainfall>* list, int count, bool x);

int main()
{
	std::cout << std::setprecision(3);

	//vars
	int falseCounter = 1;
	char inputChoice;
	LinkedList<Rainfall>* list = new LinkedList<Rainfall>();

	do {
		system("CLS");
		inputChoice = mainMenu();
		std::cin.ignore();

		switch (inputChoice)
		{
			case 'a':  //add a rainfall item
			case 'A': {
				if (list->insert(falseCounter, addMonth()))
					falseCounter++;
				else {
					std::cout << "Failed to add to list...\n";
					system("PAUSE");
				}
				break;
			}
			case 'e':  //edit a rainfall item
			case 'E': {
				int chce;
				try {
				
					print(list, falseCounter, false);
				
					std::cout << "<<==***Edit Selection***==>>\n";
					std::cout << "Enter your selection to edit: (e.g. 1 - X)";
					std::cin >> chce;
					Rainfall* newest = new Rainfall(addMonth());
					list->replace(chce, *newest);
					delete newest;
					newest = nullptr;
				}
				catch (PrecondViolatedExcept) {
					std::cout << "failed at case: E/e or lower....\n";
					system("PAUSE");
				}
				break;
			}
			case 'p':  //print the linked list
			case 'P': {
				print(list, falseCounter, true);
				break;
			}
			case 'q':  //quit
			case 'Q':
				break;
			default:{
				std::cout << "That is an incorrect option, try again!" << std::endl;
				system("PAUSE");
				break;
			}
		}
	} while (inputChoice != 'Q' && inputChoice != 'q');



	//cleanup
	delete list;
	list = nullptr;


	//salutations
	std::cout << "Good-Bye!" << std::endl;



	return 0;
}


//Function Definitions
char mainMenu()
{
	char mainMenuChoice;
	std::cout << "============================================================================" << std::endl;
	std::cout << "|                           A - Add Month of Stats                         |" << std::endl;
	std::cout << "|                           E - Edit Month of Stats                        |" << std::endl;
	std::cout << "|                           P - Print a Report                             |" << std::endl;
	std::cout << "|                           Q - Quit                                       |" << std::endl;
	std::cout << "============================================================================" << std::endl;
	std::cout << "                           Enter your selection: ";
	std::cin >> mainMenuChoice;

	return mainMenuChoice;
}


Rainfall& addMonth()
{
	Rainfall* stat = new Rainfall();
	std::string month;
	double rain;
	std::cout << "Enter the name of the MONTH: ";
	std::cin >> month;
	//getline(std::cin, month);
	std::cout << "Enter the amount of RAIN (in inches): ";
	std::cin >> rain;

	stat->setMonth(month);
	stat->setRainfall(rain);
	return *stat;
}

void print(LinkedList<Rainfall>* list, int count)
{
	//clear the screen
	system("CLS");

	try {
		double total = 0.0;
		double most = 0.0;
		double least = 0.0;

		for (int i = 1; i < count; i++)
		{
			
			Rainfall *temp = new Rainfall(list->getEntry(i));
			//temp-> = list->getEntry(i);
			std::cout << i << ". " << temp->getMonth() << " > " << temp->getRainfall() << " inches\n";

			//set total
			total += temp->getRainfall(); 
			
			//set most
			if (most < temp->getRainfall())
				most = temp->getRainfall();

			//set min	
			if (most > temp->getRainfall())
				least = temp->getRainfall();

			
			//cleanup
			delete temp;
			temp = nullptr;
		}

		//calculate average
		double average = total / count;

		std::cout << "\n";
		std::cout << "============================================================================" << std::endl;
		std::cout << "|                             Total: " << total << "                                     |" << std::endl;
		std::cout << "|                           Average: " << average << "                                    |" << std::endl;
		std::cout << "|                              Most: " << most << "                                  |" << std::endl;
		std::cout << "|                             Least: " << least << "                                 |" << std::endl;
		std::cout << "============================================================================\n";

		system("PAUSE");

	}
	catch(PrecondViolatedExcept) {

		std::cout << "There is nothing in the list, if you've added an item then there is an error!\n";
		system("PAUSE");

	}

}


//
void print(LinkedList<Rainfall>* list, int count, bool x)
{
	//clear the screen
	system("CLS");

	try {
		double total = 0.0;
		double most = 0.0;
		double least = 10.0;

		for (int i = 1; i < count; i++)
		{

			Rainfall* temp = new Rainfall(list->getEntry(i));
			std::string month = temp->getMonth();
			double newRainfallTotal = temp->getRainfall();
			std::cout << i << ". " << month << " > " << newRainfallTotal << " inches\n";

			//set total
			total += newRainfallTotal;

			//set min	
			if (newRainfallTotal < least)
				least = newRainfallTotal;

			//set most
			if (newRainfallTotal > most)
				most = newRainfallTotal;

			//cleanup
			delete temp;
			temp = nullptr;
		}

		//calculate average
		double average = total / (count - 1);

		std::cout << "\n";
		std::cout << "============================================================================" << std::endl;
		std::cout << "|                             Total: " << total << "                     |" << std::endl;
		std::cout << "|                           Average: " << average << "                     |" << std::endl;
		std::cout << "|                              Most: " << most << "                       |" << std::endl;
		std::cout << "|                             Least: " << least << "                       |" << std::endl;
		std::cout << "============================================================================" << std::endl;

		if (x == true)
			system("PAUSE");

	}
	catch (PrecondViolatedExcept) {

		std::cout << "There is nothing in the list, if you've added an item then there is an error!\n";
		system("PAUSE");

	}

}