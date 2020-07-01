#include <iostream>
#include<vector>
#include <time.h>
#include <algorithm>
template <typename T>
class Matrix_2D
{
protected:
	std::vector<std::vector<T>> vect;
public:
	Matrix_2D() // domyœlny konstruktor tworz¹cy macierz 3x3 
	{
		int size = 3;  
		for (int i = 0; i < size; i++)
		{	
			std::vector<T> v;
			for (int j = 0; j < size; j++)
			{
				v.push_back(rand() % 100 + 1);
			}
			vect.push_back(v);

		}

	}
	Matrix_2D(int size) // konstruktor do tworzenia macierzy o dowolnym rozmiarze
	{
		for (int i = 0; i < size; i++)
		{
			std::vector<T> v;
			for (int j = 0; j < size; j++)
			{
				v.push_back(rand() % 100 + 1);
			}
			vect.push_back(v);

		}

	}
	template <typename T>
	friend std::ostream& operator<<(std::ostream& strumien, const Matrix_2D<T>& macierz)
	{
		for (int i = 0; i < macierz.vect[0].size(); i++)
		{
			for (int j = 0; j < macierz.vect[0].size(); j++)
			{
				strumien << macierz.vect[i][j] << ",";
			}
			strumien << std::endl;
		}
		return strumien;
	}
	T number_select(int i, int j)
	{
		if ((i || j) > vect[0].size()) return NULL;
		else return vect[i][j];
	}
	T min() 
	{
		T temp = vect[0][0];
		for (int i = 0; i < vect[0].size(); i++)
		{
			for (int j = 0; j < vect[0].size(); j++)
			{
				if (temp > vect[i][j])
				{
					temp = vect[i][j];
				}
			}
			
		}
		return temp;
	}
	T max()
	{
		T temp = vect[0][0];
		for (int i = 0; i < vect[0].size(); i++)
		{
			for (int j = 0; j < vect[0].size(); j++)
			{
				if (temp < vect[i][j])
				{
					temp = vect[i][j];
				}
			}

		}
		return temp;
	}
	std::vector<T> transform_to_vector()
	{
		std::vector<T> v;
		for (int i = 0; i < vect[0].size(); i++)
		{
			for (int j = 0; j < vect[0].size(); j++)
			{
				v.push_back(vect[i][j]);
			}
		}
		return v;
	}
	std::vector<T> transform_to_vector(Matrix_2D<T> matrix)
	{
		std::vector<T> v;
		for (int i = 0; i < vect[0].size(); i++)
		{
			for (int j = 0; j < vect[0].size(); j++)
			{
				v.push_back(vect[i][j]);
			}
		}
		return v;
	}
	template<typename T>
	static double wyznacznik(Matrix_2D<T> m)
	{
		double W = (m.vect[0][0] * m.vect[1][1] * m.vect[2][2]) + (m.vect[1][0] * m.vect[2][1] * m.vect[0][2])+ (m.vect[2][0] * m.vect[0][1] * m.vect[1][2]) - (m.vect[0][2] * m.vect[1][1] * m.vect[2][0]) - (m.vect[1][2] * m.vect[2][1] * m.vect[0][0]) -(m.vect[2][2] * m.vect[0][1] * m.vect[1][1]);
		return W;
	}
	template<typename T>
	friend bool operator >(const Matrix_2D<T>& l_macierz, const Matrix_2D<T>& p_macierz);

	template<typename T>
	friend bool operator <(const Matrix_2D<T>& l_macierz, const Matrix_2D<T>& p_macierz);


};
template<typename T>
bool operator >(const Matrix_2D<T>& l_macierz, const Matrix_2D<T>& p_macierz)
{
	return (Matrix_2D<T>::wyznacznik(l_macierz) > Matrix_2D<T>::wyznacznik(p_macierz));
}
template<typename T>
bool operator <(const Matrix_2D<T>& l_macierz, const Matrix_2D<T>& p_macierz)
{
	return (Matrix_2D<T>::wyznacznik(l_macierz) < Matrix_2D<T>::wyznacznik(p_macierz));
}

template<typename T>
class Matrix_2D_sort : public Matrix_2D<T>
{
public:
	Matrix_2D_sort() : Matrix_2D<T>(){}
	Matrix_2D_sort(int size) : Matrix_2D<T>(size) {} // macierz o dowolnych rozmiarach 
	void sort_by_row() // zamienia macierz na wektor jednowymiarowy, sortuje i ustawia rzêdami
	{
		int k = 0;
		std::vector<T> v = Matrix_2D<T>::transform_to_vector(*this);
		std::sort(v.begin(), v.end());
	
		for (int i = 0; i < Matrix_2D<T>::vect[0].size(); i++)
		{
			for (int j = 0;j< Matrix_2D<T>::vect[0].size(); j++)
			{
				std::swap(this->vect[i][j], v[k]);
				k++;
			}

		}
	} 
	void sort_by_column()// zamienia macierz na wektor jednowymiarowy, sortuje i ustawia kolumnami
	{
		int k = 0;
		std::vector<T> temp_v = Matrix_2D<T>::transform_to_vector(*this);
		std::sort(temp_v.begin(), temp_v.end());

		for (int i = 0; i < Matrix_2D<T>::vect[0].size(); i++)
		{
			for (int j = 0; j < Matrix_2D<T>::vect[0].size(); j++)
			{
				this->vect[j][i]= temp_v[k];
				k++;
			}

		}
	}
	template <typename T>
	friend std::ostream& operator<<(std::ostream& strumien, const Matrix_2D_sort<T>& macierz)
	{
		for (int i = 0; i < macierz.vect[0].size(); i++)
		{
			for (int j = 0; j < macierz.vect[0].size(); j++)
			{
				strumien << macierz.vect[i][j] << ",";
			}
			strumien << std::endl;
		}
		return strumien;
	}
};

int main()
{
	srand(time(NULL));
	Matrix_2D<int> macierz_a;
	std::cout << "macierz A : " << std::endl << macierz_a << std::endl << "Wyznacznik = " << Matrix_2D<int>::wyznacznik(macierz_a) << std::endl;
	Matrix_2D<int> macierz_b;
	std::cout << "macierz B : " << std::endl << macierz_b << std::endl << "Wyznacznik = " << Matrix_2D<int>::wyznacznik(macierz_b) << std::endl;
	if (macierz_a > macierz_b)
	{
		std::cout << "Macierz A ma wiekszy wyznacznik" << std::endl;
	}
	else
	{
		std::cout << "Macierz B ma wiekszy wyznacznik" << std::endl;
	}




	Matrix_2D_sort<int> macierz_sort;
	std::cout << "macierz przed sortowaniem: " << std::endl << macierz_sort;
	std::cout << "wybrany element: " << macierz_sort.number_select(0,0) << std::endl;
	std::cout << "wybrany element: " << macierz_sort.number_select(2,1) << std::endl;
	std::cout << "wybrany element: " << macierz_sort.number_select(1, 2) << std::endl;

	std::cout << "min: " << macierz_sort.min() << std::endl;
	std::cout << "max: " << macierz_sort.max() << std::endl;
	std::vector<int> v = macierz_sort.transform_to_vector();
	std::cout << "sortowanie wierszami" << std::endl;
	macierz_sort.sort_by_row();
	std::cout << macierz_sort;
	std::cout << "sortowanie kolumnami" << std::endl;
	macierz_sort.sort_by_column();
	std::cout << macierz_sort;

	
}