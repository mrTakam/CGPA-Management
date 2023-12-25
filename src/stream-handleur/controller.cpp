#include "..\..\include\stream-handleur\controller.hpp"

void initMaillonCopies() {

}


//TO DO -flemme
void initStudentListe(const char* sheetname) {
    // Open the existing Excel file for reading
    xlsxioreader workbook = ExcelManagement::r_openworkbook(path);
    xlsxioreadersheet sheet;
    char* value;
    
    if ((sheet = xlsxioread_sheet_open(workbook, sheetname, XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL) {
        //read all rows
        for (int i = 0; xlsxioread_sheet_next_row(sheet); i++)
        {
            //the first ad second columns
            value = xlsxioread_sheet_next_cell(sheet);
            xlsxioread_free(value);   
        }
        xlsxioread_sheet_close(sheet);
    }

    //clean up
    xlsxioread_close(workbook);
}

void handlExam() {
    int option;

    while (1) {
        cout << "----- CRUD operations on exam -----\n" << endl;
        cout << "Select one option below :" << endl;
        cout << "      1. Display exams (existe pas flemme)." << endl;
        cout << "      2. Register exam result" << endl;
        cout << "      0. exit" << endl;
        option = int_input("\nEnter your choice: ");
        //cannot declare a variable inside a block --> "transfer of control bypasses initialization,"
        string sfilename; 
        switch (option) {
            case 1: cout << "dsl j'avais la flemme" << endl; break;
            case 2: 
                sfilename = str_input("provide the filename of the course relate to this exame : ");
                ExcelManagement::registerExam(path, sfilename.c_str()); 
                break;
            case 0: return;

            default:
                cout << "\n\nInvalid option. Please try again." << endl;
                break;
        }

        cout << "\n";
        cout << "\n";
    }

    return;
}

void handlCourse() {
    int option;

    while (1) {
        cout << "----- CRUD operations on course -----\n" << endl;
        cout << "Select one option below :" << endl;
        cout << "      1. View courses." << endl;
        cout << "      2. Display course." << endl;
        cout << "      0. Exit" << endl;

        option = int_input("\nEnter your choice: ");
        //cannot declare a variable inside a block --> "transfer of control bypasses initialization,"
        string sfilename; 

        switch (option) {
            case 1: ExcelManagement::avalaibleCourses(path); break;
            case 2: 
                sfilename = str_input("provide the filename of the course relate to this exame : ");
                ExcelManagement::displayCourse(path, sfilename.c_str());
            case 0: return;

            default:
                cout << "\n\nInvalid option. Please try again." << endl;
                break;
        }

        cout << "\n";
        cout << "\n";
    }

    return;
}

void handlCGPA() {
    int option;

    while (1) {
        cout << "----- CRUD operations on CGPA -----\n" << endl;
        cout << "Select one option below :" << endl;
        cout << "      1. View CGPA." << endl;
        cout << "      0. Exit" << endl;

        option = int_input("\nEnter your choice: ");

        switch (option) {
            case 1: ExcelManagement::avalaibleCourses(path); break;
            case 0: return;

            default:
                cout << "\n\nInvalid option. Please try again." << endl;
                break;
        }

        cout << "\n";
        cout << "\n";
    }

}









