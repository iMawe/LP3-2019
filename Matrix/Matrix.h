#include <iostream>

using namespace std;

template <class T>
class Matrix{
private:
	int f, c;
	T dato;
	T A[100][100];
public:
	Matrix(int a1 = 50, int b1 = 50){
		a = a1;
		b = b1;
	}
	~Matrix();

	T& operator()(const int &f, const int &c){
    	return A[ff][cc];
	}

	friend ostream &operator<<(ostream &os, const Matrix &m){
		for (int i=0; i < m.f; i++) {
          for (int j=0; j < m.c; j++) {
              os << m.A[i][j] << "  " ;
          }
          os << '\n';
      }
      return os;
	}
};


int main() {
  Matrix<int> x(10,6);
  x(4,4)=5;
  x(3,2)=3;
  cout<<x;
}
