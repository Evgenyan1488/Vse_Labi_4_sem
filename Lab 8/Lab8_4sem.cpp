#include <iostream>
#include <list>

using namespace std;


/*Дан массив X(20), если сумма индексов положительных
элементов массива четная, то поменять местами соседние
элементы первый со вторым, третий с четвертым и так
далее, иначе выдать на экран сообщение, что это условие не
выполнено.*/


int main() 
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите кол-во элементов массива >> ";
    cin >> n;

    list<int> l(n);

    cout << endl;
    cout << "Введите элементы >>  ";
    cout << endl;
    for (int& el : l)
    {
        cin >> el;
    }

    cout << endl << endl;
    cout << "Ваш массив >> " << endl;
    for (int& el : l)
    {
        cout << el << " ";
    }


    cout << endl;
    int sum = 0;
    int i = 0;
    for (auto iter = l.begin(); iter != l.end(); iter++)
    {
        if (*iter > 0)
        sum += i;
        i++;
    }
    sum++;

    
    if (sum % 2)
    {
        int buf1, buf2;
        for (auto iter = l.begin(); iter != l.end(); iter++)
        {
            buf1 = *(iter);
            iter++;
            buf2 = *iter;       //Да это жоска
            iter--;     
            *(iter) = buf2;
            *(++iter) = buf1;
        }
        cout << "Искомый массив:";
        cout << endl;
        for (auto& el : l) {
            cout << el << " ";
        }
    }
    else
        cout << "Ничего не вышло(";
    cout << endl;


    return (0);
}