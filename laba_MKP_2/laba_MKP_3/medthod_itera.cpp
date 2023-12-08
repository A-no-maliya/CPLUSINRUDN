#include <iostream>
#include <cmath>
#include <fstream>


#define PI           3.14159265358979323846 
//#de//fine mu           4902     // m*c**2

using namespace std;

double newton_method(double M, double e, double epsilon = 1e-6)
{
    double E = M; // Начальное приближение для E

    for (int i = 0; i < 40; i++)
    {
        double f = E - e * sin(E) - M; // Значение функции
        double f_prime = 1 + e * cos(E); // Значение производной функции

        E -= f / f_prime; // Вычисление следующего приближения для E

        if (abs(f) < epsilon) // Проверка условия сходимости
        {
            break;
        }
    }

    return abs(E);
}

int main() {
    // Параметры орбиты 
    double r_a = 1017 + 1737;                   // км радиус апоцентра (h+r)
    double r_p = 350 + 1737;                    // км радиус перицентра 
    double epsilon = 1e-6;

    double GM_m = 4902.80003; //в км
    double a = (r_a + r_p) / 2;            // большая полуось
    double n = sqrt(GM_m / pow(a, 3));// средняя угловая скорость
    double T = 2 * PI / n;                  

    double e = ((r_a - r_p) / (2 * a));            // эсцентриситет орбиты 0,48793

    // Создание файла
    ofstream fout1;
    fout1.open("data_for_graphs.txt");

    // Проверка успешного открытия файла
    if (!fout1) {
        cout << "Error opening file.";
        return 0;
    }

    fout1 << "t, c\t";
    fout1 << "M(t), рад\t";
    fout1 << "E(t), рад\t";
    fout1 << "Theta(t), рад\t" << endl;
    fout1 << "r(t), км\t" << endl;
    fout1 << "V_r(t), м/с\t" << endl;
    fout1 << "V_n(t), м/с\t" << endl;
    fout1 << "V(t), м/с\t" << endl;

    // Вычисление и запись значений аномалий в файл
    for (int t = 0; t <= T; t++) {
        fout1 << t << "\t";

        double M = n * t; // Средняя аномалия
        double E = newton_method(M, e, epsilon); // Эксцентрическая аномалия

        double true_anomaly = atan(sqrt((1 + e) / (1 - e)) * (tan(E / 2))) * 2; // Истинная аномалия
        if (true_anomaly < 0)
            true_anomaly += 2 * PI;

        double p = a * (1 - e * e);                                       // фокальное расстояние
        double r = (p / (1 + (e * cos(true_anomaly))));
        double V_n = (sqrt(GM_m / p)) * (1 + e * cos(true_anomaly));
        double V_r = (sqrt(GM_m / p)) * (e * sin(true_anomaly));
        double V = pow(((V_r * V_r) + (V_n * V_n)) , 0.5);

        fout1 << M << "\t";
        fout1 << E << "\t";
        fout1 << true_anomaly << "\t";
        fout1 << r << "\t";
        fout1 << V_r << "\t";
        fout1 << V_n << "\t";
        fout1 << V << endl;
    }
    fout1.close();
    cout << "The data was successfully written to the 'data_for_graphs.txt' file.";

    return 0;
}