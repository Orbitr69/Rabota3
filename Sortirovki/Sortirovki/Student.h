#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Student
{
private:
    char lastName[20];      // фамилия
    int group;              // номер группы
    int grades[5];          // 5 оценок
    double averageGrade;    // средний балл

public:
    // Конструкторы
    Student(const char* name, int gr, int g1, int g2, int g3, int g4, int g5);
    Student();

    // Вычисление среднего балла
    void calculateAverage();

    // Операторы сравнения (для сортировок)
    bool operator>(const Student& b);
    bool operator<(const Student& b);
    bool operator==(const Student& b);

    // Операторы ввода/вывода
    friend ostream& operator<<(ostream& os, const Student& m);
    friend istream& operator>>(istream& is, Student& m);

    // Геттеры
    char* getLastName();
    int getGroup();
    double getAverageGrade();
    int getGrade(int index);

    // Вывод на экран
    void print();
};