#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to display the menu options
void displayMenu() {
  cout << endl;
  cout << "~~~~~~~~ Dropdown Menu ~~~~~~~~" << endl;
  cout << "1. Add Task" << endl;
  cout << "2. Mark Task as Completed" << endl;
  cout << "3. View Completed Tasks" << endl;
  cout << "4. Exit" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << endl;
  cout << "Enter your choice: ";
}

int main() {
  vector<string> tasks;
  vector<string> completedTasks;
  int choice;

  do {
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1: {
      cout << endl;
      cout << "Enter task: ";
      string task;
      cin.ignore();
      getline(cin, task);
      tasks.push_back(task);
      cout << endl;
      cout << "*Task added successfully*" << endl;
      cout << endl;
      cout << "->->->->->-> To-Do ->->->->->->" << endl;
      for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
      }
      break;
    }
    case 2: {
      if (tasks.empty()) {
        cout << endl;
        cout << "*No tasks pending! Please check back later.*" << endl;
      } else {
        cout << endl;
        cout << "Enter task number to mark as completed: ";
        int taskNum;
        cin >> taskNum;
        if (taskNum > 0 && taskNum <= static_cast<int>(tasks.size())) {
          // string element = tasks[taskNum - 1];
          completedTasks.push_back(tasks.at(taskNum - 1));
          tasks.erase(tasks.begin() + taskNum - 1);
          cout << endl;
          cout << "*Task marked as completed*" << endl;
          cout << endl;
          if (tasks.empty()) {
            cout << endl;
            cout << "*No tasks pending! Please check back later.*" << endl;
          } else {
            cout << "->->->->->-> To-Do ->->->->->->" << endl;
            for (int i = 0; i < tasks.size(); i++) {
              cout << i + 1 << ". " << tasks[i] << endl;
            }
          }
        } else {
          cout << endl;
          cout << "*Invalid task number*" << endl;
        }
      }
      break;
    }
    case 3: {
      cout << endl;
      if (completedTasks.empty()) {
        cout << "*No tasks completed yet. Let's get to work!*" << endl;
        cout << endl;
      } else {
        cout << "->->->->->-> Completed Tasks ->->->->->->" << endl;
        for (int i = completedTasks.size() - 1; i >= 0; i--) {
          cout << completedTasks.size() - i << ". " << completedTasks[i]
               << endl;
        }
      }
      if (tasks.empty()) {
        cout << endl;
        cout << "*No tasks pending! Please check back later.*" << endl;
      } else {
        cout << "->->->->->-> To-Do ->->->->->->" << endl;
        for (int i = 0; i < tasks.size(); i++) {
          cout << i + 1 << ". " << tasks[i] << endl;
        }
      }
      break;
    }
    case 4: {
      cout << endl;
      cout << "*Exiting program. Thank you!*" << endl;
      break;
    }
    default:
      cout << endl;
      cout << "*Invalid choice. Please try again*" << endl;
    }
  } while (choice != 4);

  return 0;
}
