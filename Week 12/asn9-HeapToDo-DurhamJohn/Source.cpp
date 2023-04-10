#include <iostream>
#include <string>
#include <stdexcept>
#include "Task.h"
#include "HeapPriorityQueue.h"
#include "PreCondViolatedExcept.h"


int menu(std::unique_ptr<HeapPriorityQueue<Task>>& list);
void addANewTask(std::unique_ptr<HeapPriorityQueue<Task>>& list);
void removeATask(std::unique_ptr<HeapPriorityQueue<Task>>& list);
void printTasks(std::unique_ptr<HeapPriorityQueue<Task>>& list);



int main() {
	std::unique_ptr<HeapPriorityQueue<Task>> todo;
	int choice;

	do {
		choice = menu(todo);

		switch (choice) {
		case 1:
			addANewTask(todo);
			break;
		case 2:
			removeATask(todo);
			break;
		case 3://exit
			choice = 5;
			break;
		default:
			std::cout << "Invalid selection, try again!\n";
		}

		system("CLS");

	} while (choice != 5);


	

	return 0;
}




int menu(std::unique_ptr<HeapPriorityQueue<Task>>& list)
{
	std::cin.clear();
	int choice;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "|                          ***TODO List***                     |" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "|        1. add a task  2. complete current task  3. quit      |" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	printTasks(list);
	std::cin >> choice;
	if (choice < 1 || choice > 3)
		return -1;
	else
		return choice;
}

void addANewTask(std::unique_ptr<HeapPriorityQueue<Task>>& list)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string newTask;
	std::cout << "Enter the task: ";
	getline(std::cin, newTask);
	Task tsk;
	tsk.setTask(newTask);

	try {
		bool results = list->enqueue(tsk);
		std::cout << "tsk success: " << results << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Access violation exception caught: " << std::endl;
	}
}

void removeATask(std::unique_ptr<HeapPriorityQueue<Task>>& list)
{
	list->dequeue();
}

void printTasks(std::unique_ptr<HeapPriorityQueue<Task>>& list)
{
	try {
		Task tsk = Task(list->peekFront());
		std::cout << std::endl;
		std::cout << "                     Next TODO: " << tsk.getTask() << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------------------------------------\n";
	}
	catch (std::exception e) {
		std::cout << std::endl;
		std::cout << "                     *** No New Tasks ***" << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------------------------------------\n";
	}
}

