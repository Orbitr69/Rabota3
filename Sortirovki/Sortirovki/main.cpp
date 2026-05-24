#include <iostream>
#include <fstream>
#include <chrono>

#include "Student.h"
#include "Sorts.h"

using namespace std;
using namespace chrono;

// Функция для вывода разделителя
void printSeparator()
{
    cout << "================================================================================" << endl;
}

// Функция для вывода шапки таблицы
void printHeader()
{
    cout << "Last Name\tGroup\tGrades\t\t\tAvg.Grade" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "================================================================================" << endl;
    cout << "STUDENT DATA SORTING PROGRAM" << endl;
    cout << "================================================================================" << endl;
    cout << endl;

    // Открытие текстового файла
    ifstream in("text.txt");

    if (!in)
    {
        cerr << "ERROR: File 'text.txt' not found!" << endl;
        cerr << "Make sure the file is in the program folder" << endl;
        cout << "\nPress any key to exit...";
        cin.get();
        return 1;
    }

    // Массив объектов (10 студентов)
    Student arr[10];
    int n = 0;

    // Чтение объектов из файла
    cout << "Reading data from file...\n" << endl;
    printHeader();

    while (n < 10 && in >> arr[n])
    {
        cout << arr[n] << endl;
        n++;
    }

    in.close();

    cout << "\n" << endl;
    cout << "Total students loaded: " << n << endl;
    cout << "\nPress Enter to continue...";
    cin.get();

    // ==================== 1. BUBBLE SORT ====================
    Student arr1[10];
    for (int i = 0; i < n; i++) arr1[i] = arr[i];

    cout << "\n" << endl;
    printSeparator();
    cout << "1. BUBBLE SORT" << endl;
    cout << "Sorting by last name (A-Z)" << endl;
    printSeparator();

    auto start = high_resolution_clock::now();
    bubbleSort(arr1, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    printHeader();
    for (int i = 0; i < n; i++)
        cout << arr1[i] << endl;

    cout << "\nTime: " << duration.count() << " microseconds" << endl;
    cout << "\nPress Enter to continue...";
    cin.get();

    // ==================== 2. SELECTION SORT ====================
    Student arr2[10];
    for (int i = 0; i < n; i++) arr2[i] = arr[i];

    cout << "\n" << endl;
    printSeparator();
    cout << "2. SELECTION SORT" << endl;
    cout << "Sorting by last name (A-Z)" << endl;
    printSeparator();

    start = high_resolution_clock::now();
    selectionSort(arr2, n);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    printHeader();
    for (int i = 0; i < n; i++)
        cout << arr2[i] << endl;

    cout << "\nTime: " << duration.count() << " microseconds" << endl;
    cout << "\nPress Enter to continue...";
    cin.get();

    // ==================== 3. INSERTION SORT ====================
    Student arr3[10];
    for (int i = 0; i < n; i++) arr3[i] = arr[i];

    cout << "\n" << endl;
    printSeparator();
    cout << "3. INSERTION SORT" << endl;
    cout << "Sorting by last name (A-Z)" << endl;
    printSeparator();

    start = high_resolution_clock::now();
    insertionSort(arr3, n);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    printHeader();
    for (int i = 0; i < n; i++)
        cout << arr3[i] << endl;

    cout << "\nTime: " << duration.count() << " microseconds" << endl;
    cout << "\nPress Enter to continue...";
    cin.get();

    // ==================== 4. GNOME SORT ====================
    Student arr4[10];
    for (int i = 0; i < n; i++) arr4[i] = arr[i];

    cout << "\n" << endl;
    printSeparator();
    cout << "4. GNOME SORT" << endl;
    cout << "Sorting by last name (Z-A)" << endl;
    printSeparator();

    start = high_resolution_clock::now();
    gnomeSort(arr4, n);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    printHeader();
    for (int i = 0; i < n; i++)
        cout << arr4[i] << endl;

    cout << "\nTime: " << duration.count() << " microseconds" << endl;
    cout << "\nPress Enter to continue...";
    cin.get();

    // ==================== 5. SHELL SORT ====================
    Student arr5[10];
    for (int i = 0; i < n; i++) arr5[i] = arr[i];

    cout << "\n" << endl;
    printSeparator();
    cout << "5. SHELL SORT" << endl;
    cout << "Sorting by last name (A-Z)" << endl;
    printSeparator();

    start = high_resolution_clock::now();
    shellSort(arr5, n);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    printHeader();
    for (int i = 0; i < n; i++)
        cout << arr5[i] << endl;

    cout << "\nTime: " << duration.count() << " microseconds" << endl;
    cout << "\nPress Enter to continue...";
    cin.get();

    // ==================== 6. QUICK SORT ====================
    Student arr6[10];
    for (int i = 0; i < n; i++) arr6[i] = arr[i];

    cout << "\n" << endl;
    printSeparator();
    cout << "6. QUICK SORT" << endl;
    cout << "Sorting by last name (A-Z)" << endl;
    printSeparator();

    start = high_resolution_clock::now();
    quickSort(arr6, 0, n - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    printHeader();
    for (int i = 0; i < n; i++)
        cout << arr6[i] << endl;

    cout << "\nTime: " << duration.count() << " microseconds" << endl;

    // ==================== ЗАПИСЬ В БИНАРНЫЙ ФАЙЛ ====================
    ofstream out("students.bin", ios::binary);
    out.write((char*)arr6, n * sizeof(Student));
    out.close();

    cout << "\n" << endl;
    printSeparator();
    cout << "SORTING RESULTS SAVED" << endl;
    cout << "Sorted array saved to: students.bin" << endl;
    printSeparator();

    // ==================== ПОИСК ПО ФАМИЛИИ ====================
    ifstream fin("students.bin", ios::binary);
    Student temp;
    char searchName[20];

    cout << "\n" << endl;
    printSeparator();
    cout << "SEARCH STUDENT BY LAST NAME" << endl;
    printSeparator();
    cout << "Enter last name to search: ";
    cin >> searchName;

    bool found = false;
    int count = 0;

    cout << endl;
    printHeader();

    while (fin.read((char*)&temp, sizeof(Student)))
    {
        if (strcmp(temp.getLastName(), searchName) == 0)
        {
            cout << temp << endl;
            cout << "\n--> STUDENT FOUND! (position #" << count + 1 << ")" << endl;
            found = true;
        }
        count++;
    }

    if (!found)
    {
        cout << "\nStudent with last name \"" << searchName << "\" NOT FOUND!" << endl;
    }

    fin.close();

    cout << "\n" << endl;
    printSeparator();
    cout << "PROGRAM FINISHED SUCCESSFULLY!" << endl;
    printSeparator();

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}