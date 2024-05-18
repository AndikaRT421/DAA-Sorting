#include <iostream>
#include <vector>
// #include <chrono>
#include <numeric>
// #include <windows.h>
// #include <psapi.h>
#include <algorithm>

using namespace std;

void counting_sort(vector <int> &vec, int n)
{
    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());
    int range = max - min + 1;

    vector<int> count(range), output(n);
    for (int i = 0; i < n; i++)
    {
        count[vec[i] - min]++;
    }

    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[vec[i] - min] - 1] = vec[i];
        count[vec[i] - min]--;
    }

    for (int i = 0; i < n; i++)
    {
        vec[i] = output[i];
    }
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
//         count_sort(vec_copy, vec_copy.size());
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