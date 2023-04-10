#pragma once
#ifndef TASK_
#define TASK_
#include <string>

class Task {
private:
	std::string task;

public:
	Task() {};
	Task(const Task& copyTask);
	Task(const std::string& tsk) : task(tsk) {};

	void setTask(const std::string& tsk);
	std::string getTask();
	Task& operator=(const Task& other);
};


#endif



Task::Task(const Task& anotherTask) : task(anotherTask.task)
{
}

void Task::setTask(const std::string& tsk)
{
	task = tsk;
}

std::string Task::getTask()
{
	return task;
}