#include <iostream>
#include <Windows.h>


using namespace std;

template <class T>
class Mnozhestvo
{
private:
    T* array;
    int kol;
public:
    Mnozhestvo(int a)
    {
        kol = a;
        array = new T[kol];
    }
    void input();
    void zamena(T d, int i);
    T elemzam(int i);
    void resh();
    friend ostream& operator<< <T>(ostream& out, const Mnozhestvo<T>& d);
    ~Mnozhestvo()
    {
        delete[] array;
    }
};

//=================================================================================

template <class T>
void Mnozhestvo<T>::input()
{
    cout << "Введите массив: " << endl;
    for (int i = 0; i < kol; i++)
    {
        cin >> array[i];
    }
}

//=================================================================================

template <class T>
void Mnozhestvo<T>::zamena(T d, int i)
{
    array[i] = d;
}

//=================================================================================

template <class T>
T Mnozhestvo<T>::elemzam(int i)
{
    return array[i];
}

//=================================================================================

template <class T>
void Mnozhestvo<T>::resh()
{
    T buff;
    int sum = 0;

    for (int i = 0; i < kol; i++)
    {
        if (array[i] > 0)
            sum += i;
    }

    if (sum % 2 == 0)
    {
        for (int i = 0; i < kol - 1; i++)
        {
            buff = array[i];
            array[i] = array[i + 1];
            array[i + 1] = buff;
            i++;
        }

        for (int i = 0; i < kol; i++)
        {
            cout << array[i] << " ";
        }
    }
    else
    {
        cout << "Ничо не вышло, не получилось";
    }
}

//=================================================================================

template <class T>
ostream& operator<< (ostream& out, const Mnozhestvo<T>& d)
{
    out << "{";
    for (int i = 0; i < d.kol; i++)
    {
        out << d.array[i] << " ";
    }
    out << "}" << endl;
    out << "Кол-во элементов в массиве: col = " << d.kol << endl;
    return out;
}

//=================================================================================

int main()
{
    SetConsoleOutputCP(1251);

    int kol;
    cout << "Введите количество элементов в массиве: kol = ";
    cin >> kol;
    while (kol < 0)
    {
        cout << "Не понял, даваи ещё kol = ";
        cin >> kol;
    }

    cout << endl;

    cout << "Ввод массива:" << endl;
    Mnozhestvo<int> A(kol);
    A.input();

    cout << "=================================================================================" << endl;
    system("pause");
    cout << "=================================================================================" << endl;

    cout << "Массив А = ";
    cout << A;

    cout << endl;

    cout << "=================================================================================" << endl;
    system("pause");
    cout << "=================================================================================" << endl;

    cout << "РЕШЕНИЕ ЗАДАЧИ." << endl;
    if (kol == 0)
    {
        cout << "Массивы пустые, искать нечего!!!" << endl;
    }
    else
    {
        A.resh();
    }

    return 0;
}
