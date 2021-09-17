
#include <iostream>

using namespace std;


class complex
{
private:
	int real;
	int image;
public:
	complex()
	{
		real = -1;
		image = -1;
	}
	complex(int real, int image)
	{
		this->image = image;
		this->real = real;
	}
	void print()
	{
		if (image > 0)
			cout << real << "+" << image << "i" << endl;
		else
			cout << real << image << "i" << endl;
	}

	complex operator+(const complex& obj)
	{
		return complex(real + obj.real, image + obj.image);

	}
	bool operator<(const complex& obj)
	{
		if ((real + image) < (obj.real + obj.image))
			return true;
		else return false;
	}
	bool operator<(const int x)
	{
		if ((x > real) && (x > image))
			return true;
		else return false;
	}

	complex operator=(const complex obj)
	{
		real = obj.real;
		image = obj.image;
		return *this;
	}

	complex operator=(int x)
	{
		real = x;
		image = x;
		return *this;
	}

	complex operator/(int x)
	{
		real = real / x;
		image = image / x;
		return *this;
	}


	friend istream& operator>>(istream& in, complex& obj);
	friend ostream& operator<< (ostream& out, complex& obj);
};


istream& operator>>(istream& in, complex& obj)
{
	cout << "real = ";
	in >> obj.real;
	cout << "image = ";
	in >> obj.image;
	return in;
}


ostream& operator<<(ostream& out, complex& obj)
{
	if (obj.image < 0)
		out << obj.real << " " << obj.image << "i " << endl;
	else
		out << obj.real << " + " << obj.image << "i " << endl;
	return out;
}



template <typename T>
T** ArrCreate(int n, int m)
{
	T** arr = new T * [n];

	for (int i = 0; i < n; i++)
		arr[i] = new T[m];

	cout << "Vvedi matricu" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			};
		}

		return arr;
	}




template <typename T>
T FindSr(T** arr, int m, int i)
{
	T zero;
	zero = 0;
	T sum;
	sum = 0;
	int kol = 0;
	for (int j = 0; j < m; j++)
	{

		if (arr[j][i] < 0)
		{
			sum = sum + arr[j][i];
			kol += 1;
		}
	}
	try
	{
		if (kol == 0)
		{
			throw - 1;
			return sum / kol;
		}
		else
			return zero;
	}
	catch (int a)
	{
		cerr << "Na 0 delit nelzya" << endl; 
	}
}





template <typename T>
int FindNum(int n, int m, T** arr)
{
	int num = 0;
	T SrAr; 
	SrAr = 0;
	T buff;
	for (int i = 0; i < n;  i++)
	{
			buff = FindSr(arr, m, i);
			if (buff < SrAr)
			{
				SrAr = buff;
				num = i;
			}
	}
	return num;
}




int main()
{
	int n = 3;
	int m = 3;
	complex** matr = ArrCreate<complex>(n, m);
	/*int** matr = new int*[n];
		for (int i = 0; i < m; i++)
			matr[i] = */

	cout << "Nomer = " << FindNum<complex>(n, m, matr) + 1;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << " ";
		cout << endl;
	}


	return(0);
}
