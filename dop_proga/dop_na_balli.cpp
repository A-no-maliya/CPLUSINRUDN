#include <iostream>
#include <vector>
#include <random>
#include <fstream>

#define PI 3.14

using namespace std;

class Circle {
private:
    vector<int> color;
    int X;
    int Y;
    int R;
public:
    //getters
    int getX() const {
        return X;
    }
    int getY() const {
        return Y;
    }
    int getR() const {
        return R;
    }
    const vector<int>& getColor() const {
        return color;
    }

    //setters
    void setX(int x) {
        X = x;
    }
    void setY(int y) {
        Y = y;
    }
    void setR(int r) {
        R = r;
    }
    void setColor(const vector<int>& col) {
        color = col;
    }

    //constructors
    Circle() : X(0), Y(0), R(3), color({ 0,0,0 }) {
    }

    Circle(int x, int y, int r) : X(x), Y(y), R(r), color({ 0,0,0 }) {
    }

    Circle(int x, int y, int r, const vector<int>& vec) : X(x), Y(y), R(r), color(3, 0) {
        if (vec.size() >= 3) {
            for (int i = 0; i < 3; i++)
                color[i] = vec[i];
        }
    }

    Circle(const vector<int>& vec) : X(0), Y(0), R(3), color(3, 0) {
        if (vec.size() >= 3) {
            for (int i = 0; i < 3; i++)
                color[i] = vec[i];
        }
    }

    //declaration of external methods
    double getLength() const;
    double getArea() const;
    void ColorRand();
};

//external methods
double Circle::getArea() const {
    double area = PI * R * R;
    return area;
}

double Circle::getLength() const {
    double length = 2 * PI * R;
    return length;
}

void Circle::ColorRand() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 255);
    for (int i = 0; i < 3; i++)
        color[i] = dis(gen);
}

int main() {

    random_device rd;
    mt19937 gen(rd());

    vector<int> new_vec = { 256, 256, 256 };

    //create an object of the Circle class
    Circle krug(4, 5, 10, new_vec);


	//opening the file
	ofstream fout;
	try {
		fout.open("Circle.txt");
	}
    catch (exception& ex) {
        cout << "FILE OPENING ERROR";
        fout.close();
    }

	//writing the initial data in the fillet into it
	fout << "Initial data:" << endl;
	fout << "X = " << krug.getX() << endl;
	fout << "Y = " << krug.getY() << endl;
	fout << "R = " << krug.getR() << endl;
	fout << "R = " << krug.getColor()[0] << "," << " G = " << krug.getColor()[1] << "," << " B = " << krug.getColor()[2] << endl;
	fout << "Square = " << krug.getArea() << endl;
	fout << "Length = " << krug.getLength() << endl;


	//changing the attributes of the class
	krug.setX(13);
	krug.setY(19);
	krug.ColorRand();
	krug.setR(3);

	//we record new data in the fillet
	fout << endl << "Final data:" << endl;
	fout << "X = " << krug.getX() << endl;
	fout << "Y = " << krug.getY() << endl;
	fout << "R = " << krug.getR() << endl;
	fout << "R = " << krug.getColor()[0] << "," << " G = " << krug.getColor()[1] << "," << " B = " << krug.getColor()[2] << endl;
	fout << "Square = " << krug.getArea() << endl;
	fout << "Length = " << krug.getLength() << endl;

	cout << "The data was successfully written in the 'Circle.txt' file.";
	fout.close();

	return 0;
}