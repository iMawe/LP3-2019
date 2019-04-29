#include <iostream>

using namespace std;

template <class T>
class Matrix{
private:
	int row, col;
	T A[100][100];
public:
	Matrix(int row1 = 50, int col1 = 50){
		row = row1;
		col = col1;
	}

  Matrix(const Matrix &m) : a(m.row), b(m.col){}

	//~Matrix();

	T& operator ()(const int &r, const int &c){
    	try{
    		if(r > row)
    			throw r;
    		else if (c > col)
    			throw c;
    		return A[r][c];
    	}
    	catch(int e){
    		cout<< "ERROR!!"<< endl;
    		return A[r][c];
    	}
	}

	friend ostream &operator<<(ostream &os, const Matrix &m){
		for (int i = 0; i < m.row; i++) {
          for (int j = 0; j < m.col; j++) {
              os<< m.A[i][j]<< "  ";
          }
        os<< '\n';
      }
      return os;
	}
};


int main(){
	Matrix<int> x(7,5);
	x(4,1) = 10;
  x(4,1) = 2;
  x(8,8) = 15;
	x(1,2) = 45;
	cout<<x;
}
