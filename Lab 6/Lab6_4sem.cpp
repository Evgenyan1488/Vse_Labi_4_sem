#include <iostream>
#include <windows.h>
#include <string>


using namespace std;

struct dish
{
	string name;
	int cost;

public:
	dish() {
		name = '-';
		cost = 0;
	}
	int operator== (const dish& elem2) {
		return (cost == elem2.cost && name == elem2.name);
	};
	friend istream& operator>> (istream& in, const dish& elem);
	friend ostream& operator<< (ostream& out, const dish& elem);
	dish& operator= (const dish& elem) {
		name = elem.name;
		cost = elem.cost;
		return *this;
	};
	dish(const dish& elem) {
		name = elem.name;
		cost = elem.cost;
	};
	dish(string name, int cost)
	{
		this->name = name;
		this->cost = cost;
	}
};





istream& operator>> (istream& in, dish& elem) {
	in >> elem.name >> elem.cost;
	return in;
}

ostream& operator<< (ostream& out, const dish& elem) {
	out << "Название хрючева: " << elem.name << endl << "Цена: " << elem.cost << " гривень" << endl;
	return out;
}


template <class T> class set {
private:
	int size;
	T* a;
public:
	set();
	set(int n);
	~set();
	void setdish(int num, T elem);
	void add(T elem);
	void del(T elem);
	int check_in(T elem);
	T* mass();
	int lenght() {
		return size;
	}
	set<T> operator+ (const set<T>& set1);
	set<T> operator* (const set<T>& set1);
	set<T>& operator= (const set<T>& set1);
	template <class V> friend istream& operator>> (istream& in, const set<V>& set);
	template <class V> friend ostream& operator<< (ostream& out, const set<V>& set);
	set(const set<T>& set);
	set<T> operator- (const set<T>& set1);
	template <class V> friend void setvalue(const set<V>& set1, int num, V elem);
};


template<typename T>
void set<T>::setdish(int num, T elem) {
	a[num] = elem;
}


template <class T> set<T> ::set(int n) {
	a = new T[n];
	size = n;
}


template <class T> set<T> ::set() {
	size = 0;
	a = nullptr;
}



template <class T> set<T> :: ~set() {
	delete[] a;
	a = nullptr;
	size = 0;
}

template<typename T>
int set<T>::check_in(T elem) {
	for (int i = 0; i < size; ++i) {
		if (a[i] == elem) {
			return 1;
		}
	}
	return 0;
}

template <typename T>
void set<T> ::add(T elem) {
	if (!(*this).check_in(elem)) {
		++size;
		T* dop = new T[size];
		for (int i = 0; i < size - 1; ++i)
			dop[i] = a[i];
		dop[size - 1] = elem;
		delete[]a;
		a = dop;
	}
}

template<typename T>
void set<T> ::del(T elem) {
	if ((*this).check_in(elem)) {
		--size;
		T* dop = new T[size];
		int i;
		for (i = 0; i < size + 1; ++i) {
			if (a[i] == elem)
				break;
			dop[i] = a[i];
		}
		for (i += 1; i < size + 1; ++i)
			dop[i - 1] = a[i];
		delete[] a;
		a = dop;
	}
}

template<typename T>
T* set<T>::mass() {
	return (this->a);
}


template <typename T>
set<T> set<T>:: operator*(const set<T>& set1) {
	set<T> peresech;
	for (int i = 0; i < set1.size; ++i)
		if (check_in(set1.a[i]))
			peresech.add(set1.a[i]);
	return peresech;
}

template <typename T>
set<T> set<T>:: operator+ (const set<T>& set1) {
	set<T> unions(*this);
	for (int i = 0; i < set1.size; ++i)
		unions.add(set1.a[i]);
	return unions;
}

template <typename T>
set<T> set<T>:: operator- (const set<T>& set1) {
	set<T> lit(*this);
	for (int i = 0; i < set1.size; ++i)
		lit.del(set1.a[i]);
	return lit;
}

template <class T>
set<T>& set<T>:: operator= (const set<T>& set1) {
	this->size = set1.size;
	if (this->a != nullptr)
		delete[] this->a;
	this->a = new T[set1.size];
	for (int i = 0; i < set1.size; ++i)
		this->a[i] = set1.a[i];
	return *this;
}

template <class V>
istream& operator>> (istream& in, const set<V>& set) {
	cout << "Вводи сначала имя потом цену";
	for (int i = 0; i < set.size; ++i)
		in >> set.a[i];
	return in;
}

template <class V>
ostream& operator<< (ostream& out, const set<V>& set) {
	if (set.a == nullptr)
		cout << "таких нет, сынок" << endl;
	else {
		for (int i = 0; i < set.size; ++i)
			out << i + 1 << ": " << set.a[i] << endl;
	}
	return out;
}

template<typename T>
set<T>::set(const set<T>& set) {
	size = set.size;
	if (size == 0)
		a = nullptr;
	else
	{
		a = new T[size];
		for (int i = 0; i < size; i++)
			a[i] = set.a[i];
	}
}


template<typename T>
class decision : public set <T> {
public:
	decision() : set <T>() {};
	void resh(set<T>& menu, int n) {
		set<dish> all = menu; // заказал каждый
		set<dish> each; // всё заказанное
		cout << "Вводи номер еды (в соответствии с меню)" << endl;
		int i = 1;
		do {
			set<dish> order;
			cout << "Номер заказа " << i << endl;
			int nom;
			for (int j = 1; j < 4; ++j) {
				cin >> nom;
				order.add(menu.mass()[nom - 1]);
			}
			all = all * order;
			each = each + order;
			++i;
		} while (i < n + 1);


		cout << "Классная еда :" << endl << all << endl;
		cout << "Невкусная еда " << endl << menu - each;
	}
};


template<typename T>
void setvalue(const set<T>& set1, int num, T elem) {
	set1.a[num] = elem;
}


int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Сколько у нас брендовых ед?:" << endl;
	int size = 6;
	//cin >> size;
	set<dish> menu(size);
	setvalue(menu, 0, dish("Yaishnisa", 40));
	setvalue(menu, 1, dish("Tiramisu", 200));
	setvalue(menu, 2, dish("Sirok", 10));
	setvalue(menu, 3, dish("Sok", 99));
	setvalue(menu, 4, dish("Chipsi", 79));
	setvalue(menu, 5, dish("Supchik", 100));
	//cin >> menu;
	cout << menu << endl;

	cout << "Сколько челов пришло:" << endl;
	int n;
	cin >> n;

	decision <dish> a;
	a.resh(menu, n);

	return 0;
}