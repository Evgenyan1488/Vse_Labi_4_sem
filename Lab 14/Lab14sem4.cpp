#include <iostream>
#include <string>
#include <cstdlib>
#include<iomanip>
#include <fstream> 
#include <vector>

using namespace std;

//===================================================================================================================================

// Manual_input  - выполняет функцию ввода всех данных для матрицы смежности с помощью консоли.
// Scheme_size - - количество элементов в схеме.
// chain_kol  - количество цепей в схеме.
// matr  - матрица смежности.
// Iscreated - создалась ли матрица.
void Manual_input(int& Scheme_size, int& chain_kol, int**& matr, bool& Iscreated)
{
    cout << "Введите количество элементов в схеме: N = "; cin >> Scheme_size;
    while (Scheme_size < 0)
    {
        cout << endl;
        cout << "НЕВЕРНЫЙ ВВОД. ОТРИЦАТЕЛЬНОЕ ЗНАЧЕНИЕ Scheme_size. Повторите ввод." << endl;
        cout << "Введите количество элементов в схеме: N = "; cin >> Scheme_size;
    }

    cout << "Введите количество цепей в схеме:     L = "; cin >> chain_kol;
    while (chain_kol < 0)
    {
        cout << endl;
        cout << "НЕВЕРНЫЙ ВВОД. ОТРИЦАТЕЛЬНОЕ ЗНАЧЕНИЕ chain_kol. Повторите ввод." << endl;
        cout << "Введите количество цепей в схеме:     L = "; cin >> chain_kol;
    }

    matr = new int* [Scheme_size];
    for (int i = 0; i < Scheme_size; i++)
    {
        matr[i] = new int[Scheme_size];
    }

    cout << endl;

    cout << "Ввод данных для матрицы смежности." << endl;
    int sum_l = 0;
    for (int i = 0; i < Scheme_size; i++)
    {
        for (int j = i; j < Scheme_size; j++)
        {
            cout << "Введите количество рёбер, соединяющих вершину V" << left << setw(3) << i + 1 << " и вершину V" << left << setw(3) << j + 1 << ": ";
            cin >> matr[i][j];
            sum_l += matr[i][j];
            while ((sum_l > chain_kol) || (matr[i][j] < 0))
            {
                if (sum_l > chain_kol)
                {
                    cout << endl;
                    cout << "НЕВЕРНЫЙ ВВОД. ПРЕВЫШЕНО КОЛИЧЕСТВО ВОЗМОЖНЫХ ЦЕПЕЙ. Повторите ввод." << endl;
                    sum_l -= matr[i][j];
                    cout << "Введите количество рёбер, соединяющих вершину V" << left << setw(3) << i + 1 << " и вершину V" << left << setw(3) << j + 1 << ": ";
                    cin >> matr[i][j];
                    sum_l += matr[i][j];
                }
                if (matr[i][j] < 0)
                {
                    cout << endl;
                    cout << "НЕВЕРНЫЙ ВВОД. ОТРИЦАТЕЛЬНОЕ ЗНАЧЕНИЕ ЭЛЕМЕНТА МАТРИЦЫ СМЕЖНОСТИ matr. Повторите ввод." << endl;
                    sum_l -= matr[i][j];
                    cout << "Введите количество рёбер, соединяющих вершину V" << left << setw(3) << i + 1 << " и вершину V" << left << setw(3) << j + 1 << ": ";
                    cin >> matr[i][j];
                    sum_l += matr[i][j];
                }
            }
        }
    }

    for (int i = 0; i < Scheme_size; i++)
        matr[i][i] = 0;

    if ((Scheme_size == 0) && (chain_kol > 0))
    {
        cout << endl;
        cout << "НЕВОЗМОЖНО СОЗДАТЬ МАТРИЦУ СМЕЖНОСТИ. Завершение программы." << endl;
        Iscreated = false;
    }
    else
    {
        if (sum_l != chain_kol)
        {
            cout << endl;
            cout << "НЕВЕРНЫЙ ВВОД. НЕДОСТАТОЧНОЕ КОЛИЧЕСТВО ЦЕПЕЙ В СХЕМЕ. Автоматическое исправление." << endl;
            matr[0][0] = chain_kol + matr[0][0] - sum_l;
        }
    }
    for (int i = 1; i < Scheme_size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            matr[i][j] = matr[j][i];
        }
    }

    ofstream out;
    out.open("matr.txt");
    srand(time(0));
    out << Scheme_size << "  " << chain_kol << endl;
    for (int i = 0; i < Scheme_size; i++)
    {

        for (int j = 0; j < Scheme_size; j++)
        {
            out << matr[i][j] << "   ";
        }
        out << "\n";
    }
    out.close();

}

//===================================================================================================================================

// File_input -  выполняет функцию ввода всех данных для матрицы смежности с помощью файла IN.txt.
// Scheme_size - количество элементов в схеме.
// chain_kol -  количество цепей в схеме.
// matr - матрица смежности.
// Iscreated  - создалась ли матрица.
void File_input(int& Scheme_size, int& chain_kol, int**& matr, bool& Iscreated)
{
    ifstream file_in("C:\\Users\\Кучерявое божество\\source\\repos\\Lab14sem4\\matr.txt");
    file_in >> Scheme_size;
    file_in >> chain_kol;
    matr = new int* [Scheme_size];
    for (int i = 0; i < Scheme_size; i++)
    {
        matr[i] = new int[Scheme_size];
    }
    int** dop_matrices = new int* [Scheme_size];
    for (int i = 0; i < Scheme_size; i++)
    {
        dop_matrices[i] = new int[Scheme_size];
    }
    for (int i = 0; i < Scheme_size; i++)
    {
        for (int j = 0; j < Scheme_size; j++)
        {
            file_in >> matr[i][j];
        }
    }


    int sum_l = 0;
    cout << "Считывание данных для матрицы смежности." << endl;
   



    for (int i = 0; i < Scheme_size; i++)
    {
        delete[] dop_matrices[i];
    }
    delete[] dop_matrices;




    
    file_in.close();
}

//===================================================================================================================================

// Generated_input  - выполняет функцию ввода всех данных для матрицы смежности с помощью генерации.
// Scheme_size  - количество элементов в схеме.
// chain_kol  - количество цепей в схеме.
// matr - - матрица смежности.
// Iscreated -  - создалась ли матрица.
void Generated_input(int& Scheme_size, int& chain_kol, int**& matr, bool& Iscreated)
{
    int min, max;
    cout << "Генерация количества элементов в схеме." << endl;
    cout << "Введите левую границу генерации:  min  = "; cin >> min;
    while (min < 0)
    {
        cout << endl;
        cout << "ЛЕВАЯ ГРАНИЦА НЕ МОЖЕТ БЫТЬ МЕНЬШЕ НУЛЯ. Повторите ввод." << endl;
        cout << "Введите левую границу генерации:  min  = "; cin >> min;
    }
    cout << "Введите правую границу генерации: max = "; cin >> max;
    while (max < min)
    {
        cout << endl;
        cout << "ПРАВАЯ ГРАНИЦА НЕ МОЖЕТ БЫТЬ МЕНЬШЕ ЛЕВОЙ. Повторите ввод." << endl;
        cout << "Введите правую границу генерации: max = "; cin >> max;
    }
    Scheme_size = min + rand() % (max - min + 1);
    cout << "Генерация количества элементов в схеме: N = " << Scheme_size << endl;

    cout << endl;

    cout << "Генерация количества цепей в схеме." << endl;
    cout << "Введите левую границу генерации:  min  = "; cin >> min;
    while (min < 0)
    {
        cout << endl;
        cout << "ЛЕВАЯ ГРАНИЦА НЕ МОЖЕТ БЫТЬ МЕНЬШЕ НУЛЯ. Повторите ввод." << endl;
        cout << "Введите левую границу генерации:  min  = "; cin >> min;
    }
    cout << "Введите правую границу генерации: max = "; cin >> max;
    while (max < min)
    {
        cout << endl;
        cout << "ПРАВАЯ ГРАНИЦА НЕ МОЖЕТ БЫТЬ МЕНЬШЕ ЛЕВОЙ. Повторите ввод." << endl;
        cout << "Введите правую границу генерации: max = "; cin >> max;
    }
    chain_kol = min + rand() % (max - min + 1);
    cout << "Генерация количества цепей в схеме:     L = " << chain_kol << endl;

    matr = new int* [Scheme_size];
    for (int i = 0; i < Scheme_size; i++)
    {
        matr[i] = new int[Scheme_size];
    }

    cout << endl;

    int sum_l = 0;
    double dop = chain_kol / Scheme_size / 2;
    max = 1 + int(dop);
    cout << "Генерация матрицы смежности." << endl;
    for (int i = 0; i < Scheme_size; i++)
    {
        for (int j = i; j < Scheme_size; j++)
        {
            if (i == j) matr[i][j] = 0; else {
                matr[i][j] = rand() % (max + 1);
                sum_l += matr[i][j];
                while (sum_l > chain_kol)
                {
                    sum_l -= matr[i][j];
                    matr[i][j] = rand() % (max + 1);
                    sum_l += matr[i][j];
                }
            }
        }
    }
    for (int i = 1; i < Scheme_size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            matr[i][j] = matr[j][i];
        }
    }
    if ((Scheme_size == 0) && (chain_kol > 0))
    {
        cout << endl;
        cout << "НЕВОЗМОЖНО СОЗДАТЬ МАТРИЦУ СМЕЖНОСТИ. Завершение программы." << endl;
        Iscreated = false;
    }


    ofstream out;
    out.open("matr.txt");
    srand(time(0));
    out << Scheme_size << "  " << chain_kol << endl;
    for (int i = 0; i < Scheme_size; i++)
    {

        for (int j = 0; j < Scheme_size; j++)
        {
            out << matr[i][j] << "   ";
        }
        out << "\n";
    }
    out.close();

}

//===================================================================================================================================

// Prove - выполняет функцию вывода матрицы смежности.
// Scheme_size -количество элементов в схеме.
// matr - матрица смежности.

void Prove(int& Scheme_size, int& chain_kol, int**& matr)
{
    cout << "Данные матрицы смежности:" << endl;
    cout << "    ";
    for (int i = 0; i < Scheme_size; i++)
    {
        cout << " V" << left << setw(3) << i + 1;
    }
    cout << endl;

    for (int i = 0; i < Scheme_size; i++)
    {
        cout << "V" << left << setw(3) << i + 1;
        for (int j = 0; j < Scheme_size; j++)
        {
            cout << " " << left << setw(4) << matr[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "Количество цепей: " << chain_kol << "." << endl;
}

//===================================================================================================================================

// Keyboard_input  - выполняет функцию ввода данных о платах через консоль.
// n - максимальное количество элементов на плате.
// l - количество контактов разъёма платы.
void Keyboard_input(int& n, int& l)
{
    cout << "Введите максимальное количество элементов на плате: n = "; 
    cin >> n;
    while (n < 0)
    {
        cout << endl;
        cout << "НЕВЕРНЫЙ ВВОД. Повторите ввод." << endl;
        cout << "Введите максимальное количество элементов на плате: n = "; 
        cin >> n;
    }
    cout << "Введите количество контактов разъёма платы:         l = "; 
    cin >> l;
    while (l < 0)
    {
        cout << endl;
        cout << "НЕВЕРНЫЙ ВВОД. Повторите ввод." << endl;
        cout << "Введите количество контактов разъёма платы:         l = "; 
        cin >> l;
    }
}

//===================================================================================================================================

// File_input - "Файловый ввод платы" - выполняет функцию ввода данных о платах с помощью файла IN_plata.txt.
// n - максимальное количество элементов на плате.
// l - количество контактов разъёма платы.
void File_input(int& n, int& l)
{
    ifstream file_in("C:\\Users\\Кучерявое божество\\source\\repos\\Lab14sem4\\plata.txt");
    file_in >> n;
    file_in >> l;
    file_in.close();
}

//===================================================================================================================================

// Random_input - выполняет функцию ввода данных о платах с помощью генерации.
// n - максимальное количество элементов на плате.
// l - количество контактов разъёма платы.
void Random_input(int& n, int& l)
{
    int min, max;
    cout << "Генерация максимального количества элементов на плате." << endl;
    cout << "Введите левую границу генерации:  min  = "; cin >> min;
    while (min < 0)
    {
        cout << endl;
        cout << "Минимум не может быть меньше нуля. Повторите ввод." << endl;
        cout << "Введите левую границу генерации:  min  = "; cin >> min;
    }
    cout << "Введите правую границу генерации: max = "; cin >> max;
    while (max < min)
    {
        cout << endl;
        cout << "Максимум меньше минимума((. Повторите ввод." << endl;
        cout << "Введите правую границу генерации: max = "; cin >> max;
    }
    n = min + rand() % (max - min + 1);
    cout << "Генерация максимального количества элементов на плате: n = " << n << endl;

    cout << endl;

    cout << "Генерация количества контактов разъёма платы." << endl;
    cout << "Введите минимум границу генерации:  min  = "; cin >> min;
    while (min < 0)
    {
        cout << endl;
        cout << "Минимум. Повторите ввод." << endl;
        cout << "Введите минимум генерации:  min  = "; cin >> min;
    }
    cout << "Введите правую границу генерации: max = "; cin >> max;
    while (max < min)
    {
        cout << endl;
        cout << "Максимум меньше минимума((. Повторите ввод." << endl;
        cout << "Введите правую границу генерации: max = "; cin >> max;
    }
    l = min + rand() % (max - min + 1);
    cout << "Генерация количества контактов разъёма платы:          l = " << l << endl;
}

//===================================================================================================================================

// Confirm_input_plata - "Подтверждение ввода платы" - выполняет функцию вывода данных о платах.
// n - максимальное количество элементов на плате.
// l - количество контактов разъёма платы.
void Confirm_input_plata(int& n, int& l)
{
    cout << "Максимальное количество элементов на плате: n = " << n << endl;
    cout << "Количество контактов разъёма платы:         l = " << l << endl;
}

//===================================================================================================================================

void Delete(int& Scheme_size, int**& matr)
{
    for (int i = 0; i < Scheme_size; i++)
    {
        delete[] matr[i];
    }
    delete[] matr;
}

//===================================================================================================================================


//===================================================================================================================================


bool contains(vector<int>& plata, int item)
{
    bool flag = false;
    for (int i = 0; i < plata.size(); i++)
    {
        if (plata[i] == item)
            flag = true;
    }
    return flag;
}

int Evgenyan_connections(vector<int>& plata, int& Scheme_size, int**& matr)
{
    int sum = 0;
    for (int i = 0; i < plata.size(); i++)
    {
        for (int j = 0; j < Scheme_size; j++)
        {
           if (!contains(plata, j))
                sum += matr[plata[i]][j];
        }
    }
    return sum;
}

//===================================================================================================================================

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "===============================ВВОД===============================" << endl;

    int Scheme_size;
    int chain_kol;
    int** matr;
    bool Iscreated = true;
    string choice;

    cout << "Выберите удобный вариант для ввода колиечтва элементов и цепей в схеме: (выберите число)" << endl;
    cout << "1. Ввод с клавиатуры." << endl;
    cout << "2. Ввод из файла." << endl;
    cout << "3. Ввод через генерацию данных." << endl;
    cout << "Ваш выбор: "; cin >> choice;
    cout << endl;
    while ((choice != "1") && (choice != "2") && (choice != "3"))
    {
        cout << "НЕВЕРНЫЙ ВЫБОР. Повторите ввод." << endl;
        cout << "1. Ввод с клавиатуры." << endl;
        cout << "2. Ввод из файла." << endl;
        cout << "3. Ввод через генерацию данных." << endl;
        cout << "Ваш выбор: "; cin >> choice;
        cout << endl;
    }
    switch (stoi(choice)) {
    case 1:
    {
        Manual_input(Scheme_size, chain_kol, matr, Iscreated);
        break;
    }
    case 2:
        File_input(Scheme_size, chain_kol, matr, Iscreated);
        break;
    case 3:
        Generated_input(Scheme_size, chain_kol, matr, Iscreated);
        break;
    }

    if (Iscreated == false)
    {
        Delete(Scheme_size, matr);
        return 0;
    }

    


    cout << endl;

    cout << "======================= Матрица: =======================" << endl;

    Prove(Scheme_size, chain_kol, matr);

    cout << "======================== Ввод плат ========================" << endl;

    cout << "Выберите удобный вариант для ввода данных о платах: (выберите число)" << endl;
    cout << "1. Ввод с клавиатуры." << endl;
    cout << "2. Ввод из файла." << endl;
    cout << "3. Ввод через генерацию данных." << endl;
    cout << "Ваш выбор: "; cin >> choice;
    cout << endl;
    while ((choice != "1") && (choice != "2") && (choice != "3"))
    {
        cout << "НЕВЕРНЫЙ ВЫБОР. Повторите ввод." << endl;
        cout << "1. Ввод с клавиатуры." << endl;
        cout << "2. Ввод из файла." << endl;
        cout << "3. Ввод через генерацию данных." << endl;
        cout << "Ваш выбор: "; cin >> choice;
        cout << endl;
    }
    int n, l;
    switch (stoi(choice)) {
    case 1:
    {
        Keyboard_input(n, l);
        break;
    }
    case 2:
        File_input(n, l);
        break;
    case 3:
        Random_input(n, l);
        break;
    }
  

    cout << "========================= решение =========================" << endl << endl;

    if ((n == 0) || (l == 0))
    {
        cout << "не решаемо." << endl;
    }
    else
    {
        vector<int> vertexes;
        for (int i = 0; i < Scheme_size; i++)
        {
            vertexes.push_back(i);
        }
        vector<vector<int>> scheme;
        vector<int> plata;
        int num = 0;
        int vertexe;
        bool flg;
        int index;
        int vnesh;
        auto inter = vertexes.cbegin();
        vector<int> dop_1;
        int vertexNum;
        while (vertexes.size() != 0)
        {
            plata.clear();
            index = rand() % vertexes.size();
            vertexNum = vertexes[index];
            cout << "Вставляем вершину V" << vertexes[index] + 1 << " в " << scheme.size() + 1 << " плату (первая вершина в плате) ";
            cout << endl;
            plata.push_back(vertexNum);
            inter = vertexes.cbegin();
            vertexes.erase(inter + index);
            flg = true;
            while ((flg == true) && (plata.size() < n) && (vertexes.size() != 0))
            {
                if (vertexes.size() < n)
                {
                    for (int i = 0; i < vertexes.size(); i++)
                        dop_1.push_back(vertexes[i]);
                }
                else
                for (int i = 0; i < n - 1; i++)
                    dop_1.push_back(vertexes[i]);


                for (int i = 0; i < dop_1.size(); i++)
                {                        
                    cout << "Вставляем вершину V" << dop_1[i] + 1 << " в " << scheme.size() + 1 << " плату." << endl;
                    plata.push_back(dop_1[i]);
                    for (int v = 0; v < vertexes.size(); v++)
                    {
                        if (vertexes[v] == dop_1[i])
                        {
                            index = v;
                        }
                    }
                    inter = vertexes.cbegin();
                    vertexes.erase(inter + index);
                }
                dop_1.clear();
                vnesh = Evgenyan_connections(plata, Scheme_size, matr);
                cout << "Кол-во внешних связей = " << vnesh << endl;
                if (vnesh > l)
                    cout << "Многовато(((" << endl;
                else cout << "Повезло" << endl;
            }

            cout << endl << "================================================================" << endl;

            cout << "Оставшиеся вершины: ";
            if (vertexes.size() == 0)
            {
                cout << "закончились.";
            }
            else
            {
                cout << "V" << vertexes[0] + 1;
                for (int i = 1; i < vertexes.size(); i++)
                {
                    cout << ", V" << vertexes[i] + 1;
                }
            }

            cout << endl << "================================================================" << endl;

            cout << endl;
            if (plata.size() > 0)
            {
                scheme.push_back(plata);
            }
        }

        int nomer = 0;
        for (auto i : scheme)
        {

            cout << nomer + 1 << "-ая плата: " ;
            for (auto j : i)
                cout << j + 1 << " ";
            cout << "\n";
            nomer++;
        }

        cout << "Количество плат: " << scheme.size() << endl;
    }
    

    Delete(Scheme_size, matr);
    return 0;
}