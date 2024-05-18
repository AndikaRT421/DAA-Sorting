//  g++ main.cpp counting_sort.cpp generate_number.cpp merge_sort.cpp quick_sort.cpp heap_sort.cpp insertion_sort.cpp -o sorting_algorithm
// ./sorting_algorithm

#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <windows.h>
#include <psapi.h>
#include <algorithm>
#include "counting_sort.h"
#include "generate_number.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "insertion_sort.h"
#include "heap_sort.h"

using namespace std;

void menu()
{
    printf("\n");
    printf("0. Generate Random Number\n");
    printf("1. Insertion Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Heap Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Counting Sort\n");
    printf("\n-1. Exit\n");
    printf("Choose the sorting algorithm: ");
}

void read_file(vector<int> &vec, string file_name)
{
    FILE *fp = fopen(file_name.c_str(), "r");
    if (fp == NULL)
    {
        printf("Error: File not found\n");
        exit(1);
    }

    int n;
    while (fscanf(fp, "%d", &n) != EOF)
    {
        vec.push_back(n);
    }
    fclose(fp);
}

void write_sort_number(vector<int> &vec, string file_name)
{
    FILE *fp = fopen(file_name.c_str(), "a+");
    if (fp == NULL)
    {
        printf("Error: File not found\n");
        exit(1);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        fprintf(fp, "%d\n", vec[i]);
    }
    fclose(fp);
}

int main()
{
    printf("WELCOME TO SORTING ALGORITHM\n");
    int choice;
    do
    {
        menu();
        scanf("%d", &choice);

        if (choice == 0)
        {
            char name_file[50];
            printf("Enter the file name: ");
            scanf("%s", name_file);

            int n;
            printf("Enter the number of random numbers: ");
            scanf("%d", &n);

            generate_number(name_file, n);
        }
        else if (choice == 1)
        {
            char name_file[50];
            printf("Enter the file name: ");
            scanf("%s", name_file);

            vector<int> vec, ms_time, micro_time;
            read_file(vec, name_file);

            int n_iterasi;
            printf("Enter the number of iterations: ");
            scanf("%d", &n_iterasi);

            for (int i = 0; i < n_iterasi; i++)
            {
                vector<int> vec_copy = vec;

                auto start = chrono::high_resolution_clock::now();
                insertion_sort(vec_copy);
                auto end = chrono::high_resolution_clock::now();

                ms_time.push_back(chrono::duration_cast<chrono::milliseconds>(end - start).count());
                micro_time.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());

                if (i == n_iterasi - 1)
                {
                    vec = vec_copy;
                }

            }

            double sum_ms = accumulate(ms_time.begin(), ms_time.end(), 0.0);
            double average_ms = sum_ms / ms_time.size();
            printf("Average time in milliseconds: %f ms\n", average_ms);

            double sum_micro = accumulate(micro_time.begin(), micro_time.end(), 0.0);
            double average_micro = sum_micro / micro_time.size();
            printf("Average time in microseconds: %f microseconds\n", average_micro);

            PROCESS_MEMORY_COUNTERS memInfo;
            GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
            printf("Memory used: %lu KB\n", memInfo.WorkingSetSize / 1024);

            printf("Do you want to save the sorted number? (y/n): ");
            char save;
            scanf(" %c", &save);

            if (save == 'y')
            {
                sprintf(name_file, "insertion_sort_%d_numbers.txt", (int)vec.size());
                write_sort_number(vec, name_file);
            }
        }
        else if (choice == 2)
        {
            char name_file[50];
            printf("Enter the file name: ");
            scanf("%s", name_file);

            vector<int> vec, ms_time, micro_time;
            read_file(vec, name_file);

            int n_iterasi;
            printf("Enter the number of iterations: ");
            scanf("%d", &n_iterasi);

            for (int i = 0; i < n_iterasi; i++)
            {
                vector<int> vec_copy = vec;
                
                auto start = chrono::high_resolution_clock::now();
                merge_sort(vec_copy, 0, vec_copy.size() - 1);
                auto end = chrono::high_resolution_clock::now();

                ms_time.push_back(chrono::duration_cast<chrono::milliseconds>(end - start).count());
                micro_time.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());

                if (i == n_iterasi - 1)
                {
                    vec = vec_copy;
                }

            }

            double sum_ms = accumulate(ms_time.begin(), ms_time.end(), 0.0);
            double average_ms = sum_ms / ms_time.size();
            printf("Average time in milliseconds: %f ms\n", average_ms);

            double sum_micro = accumulate(micro_time.begin(), micro_time.end(), 0.0);
            double average_micro = sum_micro / micro_time.size();
            printf("Average time in microseconds: %f microseconds\n", average_micro);

            PROCESS_MEMORY_COUNTERS memInfo;
            GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
            printf("Memory used: %lu KB\n", memInfo.WorkingSetSize / 1024);

            printf("Do you want to save the sorted number? (y/n): ");
            char save;
            scanf(" %c", &save);

            if (save == 'y')
            {
                sprintf(name_file, "merge_sort_%d_numbers.txt", (int)vec.size());
                write_sort_number(vec, name_file);
            }
        }
        else if (choice == 3)
        {
            char name_file[50];
            printf("Enter the file name: ");
            scanf("%s", name_file);

            vector<int> vec, ms_time, micro_time;
            read_file(vec, name_file);

            int n_iterasi;
            printf("Enter the number of iterations: ");
            scanf("%d", &n_iterasi);

            for (int i = 0; i < n_iterasi; i++)
            {
                vector<int> vec_copy = vec;

                auto start = chrono::high_resolution_clock::now();
                heap_sort(vec_copy);
                auto end = chrono::high_resolution_clock::now();

                ms_time.push_back(chrono::duration_cast<chrono::milliseconds>(end - start).count());
                micro_time.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());

                if (i == n_iterasi - 1)
                {
                    vec = vec_copy;
                }

            }

            double sum_ms = accumulate(ms_time.begin(), ms_time.end(), 0.0);
            double average_ms = sum_ms / ms_time.size();
            printf("Average time in milliseconds: %f ms\n", average_ms);

            double sum_micro = accumulate(micro_time.begin(), micro_time.end(), 0.0);
            double average_micro = sum_micro / micro_time.size();
            printf("Average time in microseconds: %f microseconds\n", average_micro);

            PROCESS_MEMORY_COUNTERS memInfo;
            GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
            printf("Memory used: %lu KB\n", memInfo.WorkingSetSize / 1024);

            printf("Do you want to save the sorted number? (y/n): ");
            char save;
            scanf(" %c", &save);

            if (save == 'y')
            {
                sprintf(name_file, "heap_sort_%d_numbers.txt", (int)vec.size());
                write_sort_number(vec, name_file);
            }
        }
        else if (choice == 4)
        {
            char name_file[50];
            printf("Enter the file name: ");
            scanf("%s", name_file);

            vector<int> vec, ms_time, micro_time;
            read_file(vec, name_file);

            int n_iterasi;
            printf("Enter the number of iterations: ");
            scanf("%d", &n_iterasi);

            for (int i = 0; i < n_iterasi; i++)
            {
                vector<int> vec_copy = vec;

                auto start = chrono::high_resolution_clock::now();
                quick_sort(vec_copy, 0, vec_copy.size() - 1);
                auto end = chrono::high_resolution_clock::now();

                ms_time.push_back(chrono::duration_cast<chrono::milliseconds>(end - start).count());
                micro_time.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());

                if (i == n_iterasi - 1)
                {
                    vec = vec_copy;
                }

            }

            double sum_ms = accumulate(ms_time.begin(), ms_time.end(), 0.0);
            double average_ms = sum_ms / ms_time.size();
            printf("Average time in milliseconds: %f ms\n", average_ms);

            double sum_micro = accumulate(micro_time.begin(), micro_time.end(), 0.0);
            double average_micro = sum_micro / micro_time.size();
            printf("Average time in microseconds: %f microseconds\n", average_micro);

            PROCESS_MEMORY_COUNTERS memInfo;
            GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
            printf("Memory used: %lu KB\n", memInfo.WorkingSetSize / 1024);

            printf("Do you want to save the sorted number? (y/n): ");
            char save;
            scanf(" %c", &save);

            if (save == 'y')
            {
                sprintf(name_file, "quick_sort_%d_numbers.txt", (int)vec.size());
                write_sort_number(vec, name_file);
            }

        }
        else if (choice == 5)
        {
            char name_file[50];
            printf("Enter the file name: ");
            scanf("%s", name_file);

            vector<int> vec, ms_time, micro_time;
            read_file(vec, name_file);

            int n_iterasi;
            printf("Enter the number of iterations: ");
            scanf("%d", &n_iterasi);

            for (int i = 0; i < n_iterasi; i++)
            {
                vector<int> vec_copy = vec;

                auto start = chrono::high_resolution_clock::now();
                counting_sort(vec_copy, *max_element(vec_copy.begin(), vec_copy.end()));
                auto end = chrono::high_resolution_clock::now();

                ms_time.push_back(chrono::duration_cast<chrono::milliseconds>(end - start).count());
                micro_time.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());

                if (i == n_iterasi - 1)
                {
                    vec = vec_copy;
                }

            }

            double sum_ms = accumulate(ms_time.begin(), ms_time.end(), 0.0);
            double average_ms = sum_ms / ms_time.size();
            printf("Average time in milliseconds: %f ms\n", average_ms);

            double sum_micro = accumulate(micro_time.begin(), micro_time.end(), 0.0);
            double average_micro = sum_micro / micro_time.size();
            printf("Average time in microseconds: %f microseconds\n", average_micro);

            PROCESS_MEMORY_COUNTERS memInfo;
            GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
            printf("Memory used: %lu KB\n", memInfo.WorkingSetSize / 1024);

            printf("Do you want to save the sorted number? (y/n): ");
            char save;
            scanf(" %c", &save);

            if (save == 'y')
            {
                sprintf(name_file, "counting_sort_%d_numbers.txt", (int)vec.size());
                write_sort_number(vec, name_file);
            }

        }
        else if (choice == -1)
        {
            printf("Thank you for using this program\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
            break;
        }

    } while (choice != -1 && choice >= 0 && choice <= 5);

    return 0;
}
