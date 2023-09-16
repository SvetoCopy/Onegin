
#include "tests.h"

int main()
{
    //runTests();
    const char* name = "onegin.txt";
    FileInfo file = FileInfoCtor(name);


    QSort(file.text, 0, file.n_lines - 1, ComparatorRL);
    printf("\n");
    for (int i = 0; i < file.n_lines; i++) {
        printf("%s\n", file.text[i]);
    }
    FileInfoDtor(&file);
}