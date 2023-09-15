#include "sort.h"
#include "super_io.h"


int main()
{
    //int data[11] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    //int left = 0;
    //int right = 10;
    //int mid = Partition(data, left, right, 11);
    //printf("%d", mid);
    //const char* a = "abcded";
    //const char* b = "bbcded";

    //printf("%s %s\n", a, b);
    
    //Swap(t, k);
    //printf("%s %s", a, b);
    const char* name = "onegin.txt";
    FileInfo file = FileInfoCtor(name);
    //FileInfoDtor(&file);
    Sort(file.text, file.n_lines - 1);
    //QSort(file.text, 0, 6);
    //printf("\n");
    //for (int i = 0; i < 7; i++) {
    //    printf("%s\n", file.text[i]);
    //}



    //const char* data[4] = { "aaaa", "wads", "vddd", "wasd" };
    //Sort(data, 4);
}