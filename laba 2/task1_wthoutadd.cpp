#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <random>

using namespace std;

// ������� ��� ��������� ���������� ����� ��������
string generateRandomName()
{
    vector<std::string> names = { "�����", "�����", "����", "����", "���", "����", "������", "�������", "������", "���" };

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, names.size() - 1);

    int randomIndex = distribution(generator);

    return names[randomIndex];
}
// ������� ������ ����������� ������� � �������������� Range-based for-loop
void printVectorRange(const vector<string>& vec) {
    for (const auto& name : vec) {
        cout << name << " ";
    }
    cout << endl;
}

// ������� ������ ����������� ������� � �������������� ���������
void printVectorIterator(const vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// ������� ������ ����������� ������� � �������������� ���������� �����
void printVectorIndex(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// ������� ������� �������� �������� ������
double calculateMean(const vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

// ������� ������� ������� ������
double calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());

    if (grades.size() % 2 == 0) {
        int midIndex1 = grades.size() / 2 - 1;
        int midIndex2 = grades.size() / 2;
        return static_cast<double>(sortedGrades[midIndex1] + sortedGrades[midIndex2]) / 2;
    }
    else {
        int midIndex = grades.size() / 2;
        return sortedGrades[midIndex];
    }
}

// ������� ������� ���� ������
vector<int> calculateMode(const vector<int>& grades) {
    map<int, int> counts;
    for (int grade : grades) {
        counts[grade]++;
    }

    int maxCount = 0;
    for (const auto& pair : counts) {
        maxCount = max(maxCount, pair.second);
    }

    vector<int> modeGrades;
    for (const auto& pair : counts) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }

    return modeGrades;
}

// ������� ������� ���� ������ ��� ��������������� ������������� (Multimodal Mode)
vector<int> calculateMultimodalMode(const vector<int>& grades) {
    map<int, int> counts;
    for (int grade : grades) {
        counts[grade]++;
    }

    int maxCount = 0;
    for (const auto& pair : counts) {
        maxCount = max(maxCount, pair.second);
    }

    vector<int> modeGrades;
    for (const auto& pair : counts) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }

    // ���� ������ ������ �������� ��������������, ���������, ���� �� ������, �������
    // ����������� ���� �����. ���� ����� ������ ����, ��������� �� � ������ ���
    for (const auto& pair : counts) {
        if (pair.second == maxCount - 1) {
            modeGrades.push_back(pair.first);
        }
    }

    return modeGrades;
}

int main() {
    vector<string> names;
    vector<int> grades;

    int option;
    cout << "�������� ������� ������������� ��������:" << endl;
    cout << "1. ���������������� ������ �� ��������� ������� ���������" << endl;
    cout << "2. ������ �� ��������� ������� ���������" << endl;
    cout << "3. ������ �� ������� ��������� �� ������������" << endl;
    cout << "�����: ";
    cin >> option;

    if (option == 1) {
        // ������������� �������� � ���������� ����������
        names = { "�����", "�����", "����", "����", "���", "����", "������", "�������", "������", "���" };
        grades = { 95, 80, 75, 90, 85, 92, 88, 79, 87, 93 };
    }
    else if (option == 2) {
        // ������������� �������� �� ���������� ����������
        int n;
        cout << "������� ������ �������: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            names.push_back(generateRandomName());
            grades.push_back(rand() % 101); // ��������� ��������� ������ �� 0 �� 100
        }
    }
    else if (option == 3) {
        // ������������� �������� ����������, ���������� �������������
        int n;
        cout << "������� ���������� ������: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            string name;
            int grade;
            cout << "������� ��� ��� ������ � " << i + 1 << ": ";
            cin >> name;
            cout << "������� ������ ��� " << name << ": ";
            cin >> grade;

            names.push_back(name);
            grades.push_back(grade);
        }
    }
    else {
        cout << "������: ������������ �����." << endl;
        return 0;
    }

    cout << endl << "����� ���������:" << endl;
    printVectorRange(names); // ����� ���� � �������������� Range-based for-loop

    cout << endl << "������ ���������:" << endl;
    printVectorIterator(grades); // ����� ������ � �������������� ���������

    cout << endl << "������� �������� ������: " << calculateMean(grades) << endl;
    cout << "������� ������: " << calculateMedian(grades) << endl;

    cout << "���� ������: ";
    vector<int> modeGrades = calculateMode(grades);
    printVectorIndex(modeGrades); // ����� ���� � �������������� ���������� �����

    cout << endl << "���� ������ (��� ��������������� �������������): ";
    vector<int> multimodalModeGrades = calculateMultimodalMode(grades);
    printVectorIndex(multimodalModeGrades); // ����� ���� ��� ��������������� �������������

    return 0;
}