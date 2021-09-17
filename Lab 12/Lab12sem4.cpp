//А-09-19 Шведов Евгений
//Разбить схему на две части, в первую часть поместить все элементы с
//нечетным номером, а во вторую с четным, Подсчитать число цепей,
//которые не входят в цепи, попавшие в разрез.
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

#define gen 0
#define cut 1


#if gen
int main() {
    ofstream out;
    out.open("circuit.txt");
    srand(time(0));
    for (int i = 0; i < 20; i++) 
    {

        for (int j = 0; j < 12; j++)
        {
            int f = rand() % 2;
            out << f << "   ";
        }
        out << "\n";
    }
    out.close();
}
#endif


#if cut


#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    int** e = new int* [20];
    for (char i = 0; i < 20; i++)
    {
        e[i] = new int[12];
    }

    ifstream file_in("C:\\Users\\Кучерявое божество\\source\\repos\\Lab12sem4\\circuit.txt");
    for (char i = 0; i < 20; i++)
    {
        for (char j = 0; j < 12; j++)
        {
            file_in >> e[i][j];
        }
    }
    file_in.close();

    cout << "ПОДТВЕРЖДЕНИЕ ВВОДА:" << endl;

    cout << "    ";
    for (int i = 1; i <= 12; i++)
    {
        cout << " e" << left << setw(3) << i;
    }
    cout << endl;

    for (char i = 0; i < 20; i++)
    {
        cout << "V" << left << setw(3) << i + 1;
        for (char j = 0; j < 12; j++)
        {
            cout << "  " << e[i][j] << "  ";
        }
        cout << endl;
    }
   
    cout << "==================================================================" << endl;
    int* vect1 = new int[20];
    int* vect2 = new int[20];
    for (int i = 0; i < 12; i++)
    {
        vect1[i] = 0;
        vect2[i] = 0;
    }


    bool flag1, flag2;
    int kol = 0;
    for (int i = 0; i < 20; i++) 
    {
        flag1 = 1;
        flag2 = 1;

        for (int j = 0; j < 12; j++)
        {
            if (j % 2 == 0)
                vect1[j] = e[i][j];
            else
                vect2[j] = e[i][j];
        }


        /*cout << i+1 << ": ";
        for (int j = 0; j < 12; j++)
        {
            cout << vect1[j] << " ";   
        }
        cout << endl;
        cout << i+1 << ": ";
        for (int j = 0; j < 12; j++)
        {
            cout << vect2[j] << " ";
        }
        cout << endl;*/





        for (int j = 0; (j < 12) && (flag1); j++)
            if (vect1[j] == 1)
                flag1 = 0;

       for (int j = 0; (j < 12) && (flag2); j++)
            if (vect2[j] == 1)
                flag2 = 0;


        for (int j = 0; j < 12; j++)
        {
            vect1[j] = 0;
            vect2[j] = 0;
        }


        if (!((flag1 == 0) && (flag2 == 0)))
        {
            cout << "Строка номер "<< i+1 << endl;
            kol++;
        }
    }
    cout << endl << "Их количество = " << kol;
}

#endif