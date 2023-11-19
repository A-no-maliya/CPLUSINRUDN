#include <iostream>
#include <cmath>
#include <fstream>

# define PI           3.14159265358979323846 

using namespace std;

// Метод итераций (метод неподвижной точки)
#include <cmath>

/*double fixed_point_iteration(double M, double e, double epsilon = 1e-6)
{
    double E = M;
    double E_next;

    for (int i = 0; i <= 30; i++)       //цикл для поиска кол-ва действий с вводными данными
    {
        E_next = e * sin(E) + M;   // Обновляем значение E
        if (fabs(E_next - E) < epsilon)
            return E_next;
   
        E = E_next; // Вычисляем новое значение E_next
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
    double x = -M; // Любое отрицательное значение
    double y = M;  // Любое положительное значение
    double z = 0;

    for (int i = 0; i <= 30; i++)
    {
        z = (x + y) / 2; // Вычисляем новую середину отрезка
        if (fabs(y - x) <= 2 * epsilon)
            return z;

        if ((x - e * sin(x) - M) * (y - e * sin(y) - M) < 0)
        {
            y = z; // Обновляем правую границу отрезка
        }
        else
        {
            x = z; // Обновляем левую границу отрезка
        }
    }

    return z;
}

double golden_section_method(double M, double e, double epsilon = 1e-6)
{
    double x = -M; // Любое отрицательное значение
    double y = M; // Любое положительное значение
    double z = 0;
    double phi = (sqrt(5) + 1) / 2; // Золотое сечение

    for (int i = 0; i <= 30; i++)
    {
        z = x + (y - x) / phi; // Вычисляем новую середину отрезка
        if (fabs(y - x) <= 2 * epsilon)
        

        if ((x - e * sin(x) - M) * (y - e * sin(y) - M) < 0)
        {
            y = z; // Обновляем правую границу отрезка
        }
        else
        {
            x = z; // Обновляем левую границу отрезка
        }
    }

    return z;
}

double newton_method(double M, double e, double epsilon = 1e-6)
{
    double E = M; // Начальное приближение для E

    for (int i = 0; i < 40; i++)
    {
        double f = E - e*sin(E) - M; // Значение функции
        double f_prime = 1 + e*cos(E); // Значение производной функции

        E -= f / f_prime; // Вычисление следующего приближения для E

        if (abs(f) < epsilon) // Проверка условия сходимости
        {
            break;
        }
    }

    return abs(E);
}

int main()
{   
    double T = 9015;                        // период обращения КА в секундах
    double r_a = 1017000;                   // м радиус апоцентра
    double r_p = 350000;                    // м радиус перицентра 
                       
    double n = 2 * PI / T;                 // средняя угловая скорость
    double a = (r_a + r_p) / 2;              // большая полуось
    double e = ((r_a+r_p)/2*a);            // эсцентриситет орбиты

    //ofstream BUBA;
    //BUBA.open("value_for_graph.txt");

   /* for (int t = 0; t <= T; t++) {         // t - время прохождения от перицентра
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
    for (int t = 0; t <= T; t++) {         // t - время прохождения от перицентра
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