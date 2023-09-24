#include <iostream>
#include <map>
#include <iomanip>

struct BankAccount {
    int accountNumber;
    double balance;
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
};

int nextAccountNumber = 1001;
std::map<int, BankAccount> accounts;

void openAccount(double initialDeposit) {
    if (nextAccountNumber <= 1100) {
        accounts[nextAccountNumber] = BankAccount(nextAccountNumber, initialDeposit);
        std::cout << "������ ����� ���� " << nextAccountNumber << " � ��������� ��������� " << initialDeposit << std::endl;
        nextAccountNumber++;
    }
    else {
        std::cout << "�� ������� ������� ����. �������� ����� ���������� ������." << std::endl;
    }
}

void getBalance(int accountNumber) {
    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "����� �����: " << accountNumber << ", ������: " << accounts[accountNumber].balance << std::endl;
    }
    else {
        std::cout << "���� " << accountNumber << " �� ����������" << std::endl;
    }
}

void deposit(int accountNumber, double amount) {
    if (accounts.find(accountNumber) != accounts.end()) {
        accounts[accountNumber].balance += amount;
        std::cout << "����� �����: " << accountNumber << ", ����� �����: " << accounts[accountNumber].balance << std::endl;
    }
    else {
        std::cout << "���� " << accountNumber << " �� ����������. ���������� ��������� �������." << std::endl;
    }
}

void withdraw(int accountNumber, double amount) {
    if (accounts.find(accountNumber) != accounts.end()) {
        if (accounts[accountNumber].balance >= amount) {
            accounts[accountNumber].balance -= amount;
            std::cout << "����� �����: " << accountNumber << ", ����� �����: " << accounts[accountNumber].balance << std::endl;
        }
        else {
            std::cout << "�� ����� " << accountNumber << " ������������ ������� ��� ������ ��������� �����." << std::endl;
        }
    }
    else {
        std::cout << "���� " << accountNumber << " �� ����������. ���������� ��������� �������� ������." << std::endl;
    }
}

void closeAccount(int accountNumber) {
    if (accounts.find(accountNumber) != accounts.end()) {
        accounts.erase(accountNumber);
        std::cout << "���� " << accountNumber << " ������� ������." << std::endl;
        std::cout << "�������� �������� ������: " << accounts.size() << std::endl;
    }
    else {
        std::cout << "���� " << accountNumber << " �� ����������. ���������� ��������� �������� ��������." << std::endl;
    }
}

void printAllAccounts() {
    std::cout << "��� �������� �����:" << std::endl;
    for (const auto& account : accounts) {
        std::cout << "����� �����: " << account.second.accountNumber << ", ������: " << account.second.balance << std::endl;
    }
}

void calculateInterest(double interestRate) {
    std::cout << "����� ����� � ������ ���������� ������ " << interestRate << ":" << std::endl;
    for (auto& account : accounts) {
        double newBalance = account.second.balance * (1 + interestRate / 100);
        std::cout << "����� �����: " << account.second.accountNumber << ", ����� �����: " << newBalance << std::endl;
    }
}

int main() {
    char transactionType;
    double amount;
    int accountNumber;
    double interestRate;

    while (true) {
        std::cout << "������� ��� ���������� (O - ������� ����, B - ��������� ������, D - �������, W - ����� �����, C - ������� ����, P - ������ ���� ������, I - ���������� ������, Q - �����): ";
        std::cin >> transactionType;

        if (transactionType == 'Q') {
            break;
        }

        switch (transactionType) {
        case 'O':
            std::cout << "������� ��������� �������: ";
            std::cin >> amount;
            openAccount(amount);
            break;
        case 'B':
            std::cout << "������� ����� �����: ";
            std::cin >> accountNumber;
            getBalance(accountNumber);
            break;
        case 'D':
            std::cout << "������� ����� �����: ";
            std::cin >> accountNumber;
            std::cout << "������� ����� ��������: ";
            std::cin >> amount;
            deposit(accountNumber, amount);
            break;
        case 'W':
            std::cout << "������� ����� �����: ";
            std::cin >> accountNumber;
            std::cout << "������� ����� ��� ������: ";
            std::cin >> amount;
            withdraw(accountNumber, amount);
            break;
        case 'C':
            std::cout << "������� ����� �����: ";
            std::cin >> accountNumber;
            closeAccount(accountNumber);
            break;
        case 'P':
            printAllAccounts();
            break;
        case 'I':
            std::cout << "������� ���������� ������ �� ������: ";
            std::cin >> interestRate;
            calculateInterest(interestRate);
            break;
        default:
            std::cout << "�������� ��� ����������. ���������� ��� ���." << std::endl;
        }
    }

    return 0;
}



/*�����, ��� ���������� ����.����� ���� �� �������� �������� �� ������, �� ���� � ����� � ������� ���� � ������ ���� ����� ����� ������....*/


/*���������:
���������� ��������� BankAccount, ������� ��������
����� ����� � ������. �� ���������� std::map ��� �������� ������, ���
����� ���� �������� ������, � ������ BankAccount - ���������.
������� openAccount, getBalance, deposit, withdraw � closeAccount ���������
��������� �������� �������� �����, ������� �������, ���������, ������ �
�������� ������ ��������������.
� �������� openAccount, deposit � withdraw �� ���������, ���������� �� ����
� ��������� �������. ���� ���� ����������, �� ��������� ���������������
��������, ������� ������ ����� � ������ ���������.
������� printAllAccounts ������� ��� �������� ����� � �� �������.
������� calculateInterest ����������� ����� ������ ��� ������� ����� �
������ ��������� ���������� ������.
� �������� ������� main �� ����������� ��� ���������� � ������������ �
��������� ��������������� ��������. ��� ����� ���� ���������� 'Q'
������������ ����� ����� �� ���������.
��������� ���������� ��������� ���� �� ������������, ���� �� �����
������ ��� ���������� 'Q'.*/