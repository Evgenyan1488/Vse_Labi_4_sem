#include <iostream>
#include <list>
#include <string>
using namespace std;


//Есть список спортсменов, создать другой список, содержащий тех спортсменов, 
//у которых рост ниже среднего и фамилия начинается  с букв ‘а’ или ‘c’.



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


    int sum = 0;


    for (auto iter = l.begin(); iter != l.end(); iter++) {
        sum += iter->height;
    }


    cout << "sr rost = " << sum / n << endl << endl;

    bool flag = false;
    list<Info> list;
    for (auto iter = l.begin(); iter != l.end(); iter++)
    {
        if ((iter->height < (sum / n)) && ((iter->name[0] == 'a') || (iter->name[0] == 'c')))
        {
            list.push_back(*iter);
        }

    }
    cout << "Poluchai otvet: " << endl;

    for (auto& el : list) {
        cout << el;
    }
    return 0;
}
