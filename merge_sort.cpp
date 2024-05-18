#include <iostream>
#include <vector>
// #include <chrono>
#include <numeric>
// #include <windows.h>
// #include <psapi.h>

using namespace std;

void merge(vector<int> &vec, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = vec[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = vec[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &vec, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    merge_sort(vec, l, m);
    merge_sort(vec, m + 1, r);
    merge(vec, l, m, r);
}

// int main()
// {
//     char name_file[10];
//     printf("Enter the file name: ");
//     scanf("%s", name_file);

//     FILE *fp = fopen(name_file, "r");
//     if (fp == NULL)
//     {
//         printf("Error: File not found\n");
//         exit(1);
//     }

//     int n;
//     vector<int> vec;
//     while (fscanf(fp, "%d", &n) != EOF)
//     {
//         vec.push_back(n);
//     }

//     int n_iterasi;
//     vector<int> ms_time, micro_time;
//     printf("Enter the number of iterations: ");
//     scanf("%d", &n_iterasi);

//     for (int i = 0; i < n_iterasi; i++)
//     {
//         vector<int> vec_copy;
//         vec_copy.assign(vec.begin(), vec.end());
//         auto start = chrono::high_resolution_clock::now();
//         merge_sort(vec_copy, 0, vec_copy.size() - 1);
//         auto stop = chrono::high_resolution_clock::now();
//         ms_time.push_back(chrono::duration_cast<chrono::milliseconds>(stop - start).count());
//         micro_time.push_back(chrono::duration_cast<chrono::microseconds>(stop - start).count());

//         if (i == n_iterasi - 1)
//         {
//             vec.assign(vec_copy.begin(), vec_copy.end());
//         }
//     }
//     double sum_ms = accumulate(ms_time.begin(), ms_time.end(), 0.0);
//     double average_ms = sum_ms / ms_time.size();
//     cout << "Average time in milliseconds: " << average_ms << " ms" << endl;

//     double sum_micro = accumulate(micro_time.begin(), micro_time.end(), 0.0);
//     double average_micro = sum_micro / micro_time.size();
//     cout << "Average time in microseconds: " << average_micro << " microseconds" << endl;

//     PROCESS_MEMORY_COUNTERS memInfo;
//     GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
//     cout << "Memory usage: " << memInfo.WorkingSetSize / 1024 << " KB" << endl;

//     fclose(fp);
//     return 0;
// }