#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;


//Есть список спортсменов, создать другой список, содержащий тех спортсменов, 
//у которых рост ниже среднего и фамилия начинается  с букв ‘а’ или ‘c’.

//библиотека нужна получаеца

struct Info {
    string name;
    int height;
};

istream& operator>> (istream& in, Info& elem) {
    getline(in, elem.name, ',');
    in >> elem.height; 
    elem.name.erase(0, 1);
    return in;
}
ostream& operator<< (ostream& out, const Info& elem) {
    out << "Familiya: " << elem.name << "\n Rost: " << elem.height << endl;
    return out;
}

/*bool myfunc(list<Info>::iterator iter,int sum, int n)
{
    return ((iter->height < (sum / n)) && ((iter->name[0] == 'a') || (iter->name[0] == 'c')) == true);
}
*/

void myfunc(list<Info>::iterator iter, list<Info> &newlist,  int sum, int n)
{
    if ((iter->height < (sum / n)) && ((iter->name[0] == 'a') || (iter->name[0] == 'c')))
    {
        newlist.push_back(*iter);
    }
    return;
}


class functor
{
private:
    int sum;
    int n;
    
public:
    list<Info> newlist;
    functor(int sum, int n)
    {
        this->sum = sum;
        this->n = n;
    }

    void operator ()(Info info)
    {
        if ((info.height < (sum / n)) && ((info.name[0] == 'a') || (info.name[0] == 'c')) == true)
        {
            newlist.push_back(info);
            cout << info;
        }

    }
    void print()
    {
        for (auto& el : newlist)
        {
            cout << el;
        }
    }
};
int main() {
    int n;
    cout << "Vvedi kol-vo sportsmenov >>";
    cin >> n;
    list<Info> l(n);

    cout << "Vvodi dannie\n";
    for (auto& el : l) {
        cin >> el;
    }
    


    cout << "Spisok:" << endl;
    for (auto& el : l) {
        cout << el;
    }

    list<Info>::iterator iter;
    int sum = 0;


    for (iter = l.begin(); iter != l.end(); iter++) {
        sum += iter->height;
    }


    cout << "sr rost = " << sum / n << endl << endl;
    
    //bool flag = false;
    //list<Info> mynewlist;

   
    /*for (auto iter = l.begin(); iter != l.end(); iter++) 
    {
        if ((iter->height < (sum / n)) && ((iter->name[0] == 'a') || (iter->name[0] == 'c')))
        {
            newlist.push_back(*iter);
        }
           
    }*/
    functor a(sum, n);

    for_each(l.begin(), l.end(), a);
    //copy_if(l.begin(), l.end(), newlist.begin(), a);
    a.print();
    
    /*bool flag2 = ((iter->height < (sum / n)) && ((iter->name[0] == 'a') || (iter->name[0] == 'c')) == true);
    copy_if(l.begin(), l.end(), newlist.begin(), myfunc(iter, sum, n));*/
    //Ошибка	C2064	результатом вычисления фрагмента не является функция, принимающая 1 аргументов	Lab10_4sem_list	C : \Program Files(x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\include\algorithm	1652

    return 0;
}
