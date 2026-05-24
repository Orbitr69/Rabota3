#pragma once

#include <cstdlib>
#include "Student.h"

// ---------------- ПУЗЫРЬКОВАЯ СОРТИРОВКА ----------------
template <class T>
void bubbleSort(T* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].operator>(arr[j + 1]))
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ---------------- СОРТИРОВКА ВЫБОРОМ ----------------
template <class T>
void selectionSort(T* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min].operator>(arr[j]))
            {
                min = j;
            }
        }
        if (min != i)
        {
            T temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// ---------------- СОРТИРОВКА ВСТАВКАМИ ----------------
template <class T>
void insertionSort(T* arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        T x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].operator>(x))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

// ---------------- ГНОМЬЯ СОРТИРОВКА ----------------
template <class T>
void gnomeSort(T* arr, int n)
{
    int index = 0;
    while (index < n)
    {
        if (index == 0 || !(arr[index].operator<(arr[index - 1])))
        {
            index++;
        }
        else
        {
            T temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}

// ---------------- СОРТИРОВКА ШЕЛЛА ----------------
template <class T>
void shellSort(T* arr, int n)
{
    for (int step = n / 2; step > 0; step = step / 2)
    {
        for (int i = step; i < n; i++)
        {
            T x = arr[i];
            int j = i;
            while (j >= step && arr[j - step].operator>(x))
            {
                arr[j] = arr[j - step];
                j = j - step;
            }
            arr[j] = x;
        }
    }
}

// ---------------- БЫСТРАЯ СОРТИРОВКА ----------------
template <class T>
void quickSort(T* arr, int left, int right)
{
    if (left >= right) return;

    int k = (left + right) / 2;
    T x = arr[k];
    int i = left;
    int j = right;

    do
    {
        while (arr[i].operator<(x))
            i++;
        while (arr[j].operator>(x))
            j--;
        if (i <= j)
        {
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
