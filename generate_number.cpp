#include "generate_number.h"
#include <iostream>
using namespace std;

void generate_number(string file_name, int n)
{
    FILE *fp = fopen(file_name.c_str(), "a+");
    if (fp == NULL)
    {
        cout << "Error in opening file" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", rand() % n);
    }
    fclose(fp);
    printf("File %s created successfully\n", file_name.c_str());
}

// {
//     FILE *fp = fopen("10_numbers.txt", "a+");
//     if (fp == NULL)
//     {
//         cout << "Error in opening file" << endl;
//         return 1;
//     }
//     int banyak_angka = 10;
//     for (int i = 0; i < banyak_angka; i++)
//     {
//         fprintf(fp, "%d\n", rand() % 10);
//     }
//     fclose(fp);
//     printf("File 10_numbers.txt created successfully\n");
//     return 0;
// }