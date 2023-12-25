#include "..\..\include\stream-handleur\excelmanagement.hpp"

xlsxioreader ExcelManagement::r_openworkbook(const char* workbookpath) {
    xlsxioreader xlsxioread;
    if ((xlsxioread = xlsxioread_open(workbookpath)) == NULL) {
        fprintf(stderr, "Error opening .xlsx file\n");
        return;
    } else {
        return xlsxioread;
    }  
}
xlsxiowriter ExcelManagement::w_opensheet(const char* workbookpath, const char* sheetname) {
    xlsxiowriter xlsxiowrite;
    if ((xlsxiowrite = xlsxiowrite_open(workbookpath, sheetname)) == NULL) {
        fprintf(stderr, "Error creating .xlsx file\n");
        return;
    } else  {
        return xlsxiowrite;
    }    
}



void ExcelManagement::avalaibleCourses(const char* workbookpath) {
    //list available sheets
    xlsxioreader xlsxioread = ExcelManagement::r_openworkbook(workbookpath);
    xlsxioreadersheetlist sheetlist;
    const char* sheetname;

    printf("Available semesters:\n");

    if ((sheetlist = xlsxioread_sheetlist_open(xlsxioread)) != NULL) {
        for(int i = 1; (sheetname = xlsxioread_sheetlist_next(sheetlist)) != NULL; i++) {
            printf(" - %d %s\n", i, sheetname);
        }
        xlsxioread_sheetlist_close(sheetlist);
    }

    //clean up
    xlsxioread_close(xlsxioread);
}

void ExcelManagement::displayCourse(const char* workbookpath, const char* sheetname){
    //open .xlsx file for reading
    xlsxioreader xlsxioread = r_openworkbook(workbookpath);

    //read values from first sheet
    char* value;
    xlsxioreadersheet sheet;
    printf("Contents of the selected sheet:\n");
    if ((sheet = xlsxioread_sheet_open(xlsxioread, sheetname, XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL) {
        //read all rows
        while (xlsxioread_sheet_next_row(sheet)) {
            //read all columns
            while ((value = xlsxioread_sheet_next_cell(sheet)) != NULL) {
                printf("| %-20s |", value);
                xlsxioread_free(value);
            }
            printf("\n");
        }
        xlsxioread_sheet_close(sheet);
    }

    //clean up
    xlsxioread_close(xlsxioread);
}


int ExcelManagement::getlastrow(const char* workbookpath, const char* sheetname) {
    // Open the existing Excel file for reading
    xlsxioreader workbook = r_openworkbook(workbookpath);
    xlsxioreadersheet sheet;

    if ((sheet = xlsxioread_sheet_open(workbook, sheetname, XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL) {
        //read all rows
        while (xlsxioread_sheet_next_row(sheet)) {}
    }


    // Get the index of the last read row
    int lastRowIndex = xlsxioread_sheet_last_row_index(sheet);

    // Close the sheet and the reader
    xlsxioread_sheet_close(sheet);
    xlsxioread_close(workbook);

    return lastRowIndex;
}
void ExcelManagement::registerExam(const char* workbookpath, const char* sheetname) {
    //open .xlsx file for writing (will overwrite if it already exists)
    xlsxiowriter sheet = w_opensheet(workbookpath, sheetname);
    int lastRow = getlastrow(workbookpath, sheetname);

    // Start writing new data from the last row
    for (int i = 0; i <= lastRow + 1; ++i) {
        xlsxiowrite_next_row(sheet);
    }

    xlsxiowrite_next_row(sheet);

    //retrive the data provided
    copie* cliste = getExam();

    //column name
    xlsxiowrite_add_column(sheet, "name", 0);
    xlsxiowrite_add_column(sheet, "surname", 0);

    for (const auto& str : cliste->exo_liste) {
        // Convert std::string to const char*
        xlsxiowrite_add_column(sheet, str.name.c_str(), 0);
    }
    xlsxiowrite_next_row(sheet);

    //write data  
    while (cliste->suiv != NULL){
        // Convert std::string to const char*
        xlsxiowrite_add_cell_string(sheet, cliste->name.name.c_str());
        xlsxiowrite_add_cell_string(sheet, cliste->name.surname.c_str());
        for (const auto& str : cliste->exo_liste) {
            xlsxiowrite_add_cell_int(sheet, str.score);
        }
		cliste = cliste->suiv;
	}
    
    //close .xlsx file
    xlsxiowrite_close(sheet);
}

