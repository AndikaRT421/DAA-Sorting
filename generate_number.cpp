#include "generate_number.h"
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

void generate_number(string file_name, int n)
{
    ofstream file(file_name, ios::app);
    if (!file.is_open())
    {
        cout << "Error in opening file" << endl;
        return;
    }

    // Menggunakan generator angka acak dari pustaka <random>
    random_device rd;  // Non-deterministic generator
    mt19937 gen(rd()); // Seeded with non-deterministic random number
    uniform_int_distribution<> dis(0, n-1);

    for (int i = 0; i < n; i++)
    {
        file << dis(gen) << "\n";
    }
    file.close();

    cout << "File " << file_name << " created successfully" << endl;
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