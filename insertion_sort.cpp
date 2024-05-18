#include <iostream>
#include <vector>
// #include <chrono>
#include <numeric>
// #include <windows.h>
// #include <psapi.h>

using namespace std;

void insertion_sort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 1; i < n; i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}