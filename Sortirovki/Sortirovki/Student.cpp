#include "Student.h"

// Конструктор с параметрами
Student::Student(const char* name, int gr, int g1, int g2, int g3, int g4, int g5)
{
    strcpy_s(lastName, name);
    group = gr;
    grades[0] = g1;
    grades[1] = g2;
    grades[2] = g3;
    grades[3] = g4;
    grades[4] = g5;
    calculateAverage();
}

// Конструктор по умолчанию
Student::Student()
{
    lastName[0] = '\0';
    group = 0;
    for (int i = 0; i < 5; i++)
        grades[i] = 0;
    averageGrade = 0;
}

// Вычисление среднего балла
void Student::calculateAverage()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += grades[i];
    averageGrade = sum / 5.0;
}

// Операторы сравнения (по фамилии)
bool Student::operator>(const Student& b)
{
    return strcmp(lastName, b.lastName) > 0;
}

bool Student::operator<(const Student& b)
{
    return strcmp(lastName, b.lastName) < 0;
}

bool Student::operator==(const Student& b)
{
    return strcmp(lastName, b.lastName) == 0;
}

// Вывод в поток
ostream& operator<<(ostream& os, const Student& m)
{
    os << m.lastName << "\t"
        << m.group << "\t";

    for (int i = 0; i < 5; i++)
        os << m.grades[i] << " ";

    os << "\t| Avg: ";

    // Форматируем вывод среднего балла
    if (m.averageGrade == (int)m.averageGrade)
        os << (int)m.averageGrade;
    else
        os << m.averageGrade;

    return os;
}

// Ввод из потока
istream& operator>>(istream& is, Student& m)
{
    is >> m.lastName >> m.group;
    for (int i = 0; i < 5; i++)
        is >> m.grades[i];
    m.calculateAverage();
    return is;
}

// Геттеры
char* Student::getLastName()
{
    return lastName;
}

int Student::getGroup()
{
    return group;
}

double Student::getAverageGrade()
{
    return averageGrade;
}

int Student::getGrade(int index)
{
    if (index >= 0 && index < 5)
        return grades[index];
    return 0;
}

// Вывод на экран
void Student::print()
{
    cout << lastName << "\t" << group << "\t";
    for (int i = 0; i < 5; i++)
        cout << grades[i] << " ";
    cout << "\t| Avg: ";

    if (averageGrade == (int)averageGrade)
        cout << (int)averageGrade;
    else
        cout << averageGrade;

    cout << endl;
}