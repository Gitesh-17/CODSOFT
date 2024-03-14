#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

void addTask(vector<Task> &tasks, const string &description);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks, int taskNumber);
void removeTask(vector<Task> &tasks, int taskNumber);

int main()
{
    vector<Task> tasks;
    int choice;

    do
    {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        string description;
        int taskNumber;

        switch (choice)
        {
        case 1:
            cout << "Enter task description: ";
            getline(cin, description);
            addTask(tasks, description);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            markTaskCompleted(tasks, taskNumber);
            break;
        case 4:
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            removeTask(tasks, taskNumber);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

void addTask(vector<Task> &tasks, const string &description)
{
    tasks.emplace_back(description);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(vector<Task> &tasks, int taskNumber)
{
    if (taskNumber < 1 || taskNumber > tasks.size())
    {
        cout << "Invalid task number.\n";
        return;
    }
    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask(vector<Task> &tasks, int taskNumber)
{
    if (taskNumber < 1 || taskNumber > tasks.size())
    {
        cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + (taskNumber - 1));
    cout << "Task removed successfully.\n";
}
