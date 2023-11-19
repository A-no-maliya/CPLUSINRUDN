#include <iostream>
#include <cmath>
#include <fstream>

# define PI           3.14159265358979323846 

using namespace std;

// ����� �������� (����� ����������� �����)
#include <cmath>

/*double fixed_point_iteration(double M, double e, double epsilon = 1e-6)
{
    double E = M;
    double E_next;

    for (int i = 0; i <= 30; i++)       //���� ��� ������ ���-�� �������� � �������� �������
    {
        E_next = e * sin(E) + M;   // ��������� �������� E
        if (fabs(E_next - E) < epsilon)
            return E_next;
   
        E = E_next; // ��������� ����� �������� E_next
    }

    return 0;
}*/
double fixed_point_iteration(double e, double M, double epsilon = 1e-6) {

    double Ek1, Ek = M;

    for (int i{ 0 }; i < 50; i++) {

        Ek1 = e * sin(Ek) + M;

        if (abs(Ek1 - Ek) < epsilon)
            return Ek1;

        Ek = Ek1;
    }

    return 0;
}

double bisection_method(double M, double e, double epsilon = 1e-6)
{
    double x = -M; // ����� ������������� ��������
    double y = M;  // ����� ������������� ��������
    double z = 0;

    for (int i = 0; i <= 30; i++)
    {
        z = (x + y) / 2; // ��������� ����� �������� �������
        if (fabs(y - x) <= 2 * epsilon)
            return z;

        if ((x - e * sin(x) - M) * (y - e * sin(y) - M) < 0)
        {
            y = z; // ��������� ������ ������� �������
        }
        else
        {
            x = z; // ��������� ����� ������� �������
        }
    }

    return z;
}

double golden_section_method(double M, double e, double epsilon = 1e-6)
{
    double x = -M; // ����� ������������� ��������
    double y = M; // ����� ������������� ��������
    double z = 0;
    double phi = (sqrt(5) + 1) / 2; // ������� �������

    for (int i = 0; i <= 30; i++)
    {
        z = x + (y - x) / phi; // ��������� ����� �������� �������
        if (fabs(y - x) <= 2 * epsilon)
        

        if ((x - e * sin(x) - M) * (y - e * sin(y) - M) < 0)
        {
            y = z; // ��������� ������ ������� �������
        }
        else
        {
            x = z; // ��������� ����� ������� �������
        }
    }

    return z;
}

double newton_method(double M, double e, double epsilon = 1e-6)
{
    double E = M; // ��������� ����������� ��� E

    for (int i = 0; i < 40; i++)
    {
        double f = E - e*sin(E) - M; // �������� �������
        double f_prime = 1 + e*cos(E); // �������� ����������� �������

        E -= f / f_prime; // ���������� ���������� ����������� ��� E

        if (abs(f) < epsilon) // �������� ������� ����������
        {
            break;
        }
    }

    return abs(E);
}

int main()
{   
    double T = 9015;                        // ������ ��������� �� � ��������
    double r_a = 1017000;                   // � ������ ���������
    double r_p = 350000;                    // � ������ ���������� 
                       
    double n = 2 * PI / T;                 // ������� ������� ��������
    double a = (r_a + r_p) / 2;              // ������� �������
    double e = ((r_a+r_p)/2*a);            // ������������� ������

    //ofstream BUBA;
    //BUBA.open("value_for_graph.txt");

   /* for (int t = 0; t <= T; t++) {         // t - ����� ����������� �� ����������
        BUBA << "t=" << t << endl;
        double M = n * t;
        double E_fixed_point = fixed_point_iteration(M, e);
        double E_bisection = bisection_method(M, e);
        double E_golden_section = golden_section_method(M, e);
        double E_newton = newton_method(M, e);
        
        BUBA << "E (Fixed Point Iteration): " << E_fixed_point << endl;
        BUBA << "E (Bisection Method): " << E_bisection << endl;
        BUBA << "E (Golden Section Method): " << E_golden_section << endl;
        BUBA << "E (Newton Method): " << E_newton << endl;
    }*/
    for (int t = 0; t <= T; t++) {         // t - ����� ����������� �� ����������
        cout << "t=" << t << endl;
        double M = n * t;
        double E_fixed_point = fixed_point_iteration(M, e);
        double E_bisection = bisection_method(M, e);
        double E_golden_section = golden_section_method(M, e);
        double E_newton = newton_method(M, e);

        cout << "E (Fixed Point Iteration): " << E_fixed_point << endl;
        cout << "E (Bisection Method): " << E_bisection << endl;
        cout << "E (Golden Section Method): " << E_golden_section << endl;
        cout << "E (Newton Method): " << E_newton << endl;
    }
    

    return 0;
}