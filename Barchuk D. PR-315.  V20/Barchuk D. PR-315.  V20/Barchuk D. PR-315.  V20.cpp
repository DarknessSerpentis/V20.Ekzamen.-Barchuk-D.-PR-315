
#include <iostream>

using namespace std;

/*
Написать функцию, которая заменяет часть строки. Входные
данные: две строки и два числа. Заменяет часть первой
строки, начинающуюся с символа с порядковым
номером первое число и длиной втрое число, строкой
втрорая строка и возвращает результат.
*/

int length(const char* const input) {
    int ctr = 0;

    //Прибавляем счётчик пока не дойдем до символа окончания строки
    for (ctr; input[ctr] != '\0'; ctr++);

    return ctr;
}

void DeleteInsert(int startInd, int size, char* str, const char* const addStr) {

    int objLen = length(str);

    //Если начальный индекс отрицательный, переставляем его в начало строки
    if (startInd < 0) startInd = 0;

    //Если начальный индекс выходит за границы строки, возвращаем текущую строку
    if (startInd >= objLen) return;

    if (size < 0) return;

    //Если область удаления выходит за рамки массива, ограничиваем размер удаления
    if (startInd + size > objLen) size = objLen - startInd;

    //Если размер удалени 0, возвращаем текущую строку.
    if (size == 0) return;

    //Вычисляем конечный индекс
    int end = startInd + size;

    //Вычисляем новый размер массива
    int newSize = objLen - size;

    //Заполняем новый массив
    for (int i = end, k = startInd; i < objLen || k <= startInd; i++, k++) {
        str[k] = str[i];
    }

    str[newSize] = '\0';

    objLen = length(str);
    int otherLen = length(addStr);

    if (otherLen == 0) return;

    //Вычисляем окончательный индекс для вставляемой строки
    end = otherLen + startInd - 1;

    //Вычисляем новый размер
    newSize = objLen + otherLen;

    //Заполняем новый массив
    for (int i = newSize - 1, k = objLen - 1; k > startInd - 1; i--, k--) {
        str[i] = str[k];
    }
    for (int i = startInd, k = 0; k < otherLen; k++, i++) {
        str[i] = addStr[k];
    }

    str[newSize] = '\0';
}

int main()
{
    char firstStr[256];
    char secondStr[256];
    int startInd;
    int length;

    cout << "Enter first string: ";
    cin >> firstStr;
    cout << endl;

    cout << "Enter second string: ";
    cin >> secondStr;
    cout << endl;

    cout << "Enter start index: ";
    cin >> startInd;
    cout << endl;

    cout << "Enter length: ";
    cin >> length;
    cout << endl;

    DeleteInsert(startInd, length, firstStr, secondStr);

    cout << "Result: " << firstStr << endl;
    system("pause");
}


