#include "..\include\stream-handleur\controller.hpp"

int main() {
    int option;

    while (1) {
        cout << "----- CGPA Management System -----\n" << endl;
        cout << "Select one option below :" << endl;
        cout << "      1. Manage Exams" << endl;
        cout << "      2. Manage Courses" << endl;
        cout << "      3. View CGPA Report" << endl;
        cout << "      0. Exit" << endl;

        option = int_input("\nEnter your choice: ");

        switch (option) {
            case 1: handlExam(); break;
            case 2: handlCourse(); break;
            case 3: handlCGPA(); break;   
            case 0: return 0;

            default:
                cout << "\n\nInvalid option. Please try again." << endl;
                break;
        }

        cout << "\n";
        cout << "\n";
    }

    return 0;
}




