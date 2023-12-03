#include <iostream>
/*#include <xlsxio_read.h>

int main() {
    std::cout << "hello\n";
    // Open .xlsx file for reading
    const char* filename = "file-management/semester.xlsx";  // Replace with the actual path to your Excel file
    xlsxioreader xlsxioread;

    if ((xlsxioread = xlsxioread_open(filename)) == NULL) {
        std::cerr << "Error opening .xlsx file" << std::endl;
        return 1;
    }

    // List available sheets
    xlsxioreadersheetlist sheetlist;
    const char* sheetname;
    std::cout << "Available sheets:" << std::endl;

    if ((sheetlist = xlsxioread_sheetlist_open(xlsxioread)) != NULL) {
        while ((sheetname = xlsxioread_sheetlist_next(sheetlist)) != NULL) {
            std::cout << " - " << sheetname << std::endl;
        }
        xlsxioread_sheetlist_close(sheetlist);
    }

    // Clean up
    xlsxioread_close(xlsxioread);
    return 0;
}
*/