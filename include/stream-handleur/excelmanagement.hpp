#include "..\..\xlsxio\include\xlsxio_read.h"
#include "..\..\xlsxio\include\xlsxio_write.h"
#include "..\structure\main_structure.hpp"


namespace ExcelManagement {
    xlsxioreader r_openworkbook(const char* workbookpath);
    xlsxiowriter w_opensheet(const char* workbookpath, const char* sheetname);
    
    void avalaibleCourses(const char* workbookpath);
    void displayCourse(const char* workbookpath, const char* sheetname);

    int getlastrow(const char* workbookpath, const char* sheetname);
    void registerExam(const char* workbookpath, const char* sheetname);
}