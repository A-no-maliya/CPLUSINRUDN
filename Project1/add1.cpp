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
        std::cout << "Открыт новый счет " << nextAccountNumber << " с начальным депозитом " << initialDeposit << std::endl;
        nextAccountNumber++;
    }
    else {
        std::cout << "Не удалось открыть счет. Превышен лимит количества счетов." << std::endl;
    }
}

void getBalance(int accountNumber) {
    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "Номер счета: " << accountNumber << ", Баланс: " << accounts[accountNumber].balance << std::endl;
    }
    else {
        std::cout << "Счет " << accountNumber << " не существует" << std::endl;
    }
}

void deposit(int accountNumber, double amount) {
    if (accounts.find(accountNumber) != accounts.end()) {
        accounts[accountNumber].balance += amount;
        std::cout << "Номер счета: " << accountNumber << ", Новая сумма: " << accounts[accountNumber].balance << std::endl;
    }
    else {
        std::cout << "Счет " << accountNumber << " не существует. Невозможно выполнить депозит." << std::endl;
    }
}

void withdraw(int accountNumber, double amount) {
    if (accounts.find(accountNumber) != accounts.end()) {
        if (accounts[accountNumber].balance >= amount) {
            accounts[accountNumber].balance -= amount;
            std::cout << "Номер счета: " << accountNumber << ", Новая сумма: " << accounts[accountNumber].balance << std::endl;
        }
        else {
            std::cout << "На счете " << accountNumber << " недостаточно средств для снятия указанной суммы." << std::endl;
        }
    }
    else {
        std::cout << "Счет " << accountNumber << " не существует. Невозможно выполнить операцию снятия." << std::endl;
    }
}

void closeAccount(int accountNumber) {
    if (accounts.find(accountNumber) != accounts.end()) {
        accounts.erase(accountNumber);
        std::cout << "Счет " << accountNumber << " успешно закрыт." << std::endl;
        std::cout << "Осталось открытых счетов: " << accounts.size() << std::endl;
    }
    else {
        std::cout << "Счет " << accountNumber << " не существует. Невозможно выполнить операцию закрытия." << std::endl;
    }
}

void printAllAccounts() {
    std::cout << "Все открытые счета:" << std::endl;
    for (const auto& account : accounts) {
        std::cout << "Номер счета: " << account.second.accountNumber << ", Баланс: " << account.second.balance << std::endl;
    }
}

void calculateInterest(double interestRate) {
    std::cout << "Новые суммы с учетом процентной ставки " << interestRate << ":" << std::endl;
    for (auto& account : accounts) {
        double newBalance = account.second.balance * (1 + interestRate / 100);
        std::cout << "Номер счета: " << account.second.accountNumber << ", Новая сумма: " << newBalance << std::endl;
    }
}

int main() {
    char transactionType;
    double amount;
    int accountNumber;
    double interestRate;

    while (true) {
        std::cout << "Введите тип транзакции (O - открыть счет, B - запросить баланс, D - депозит, W - снять сумму, C - закрыть счет, P - печать всех счетов, I - процентная ставка, Q - выход): ";
        std::cin >> transactionType;

        if (transactionType == 'Q') {
            break;
        }

        switch (transactionType) {
        case 'O':
            std::cout << "Введите начальный депозит: ";
            std::cin >> amount;
            openAccount(amount);
            break;
        case 'B':
            std::cout << "Введите номер счета: ";
            std::cin >> accountNumber;
            getBalance(accountNumber);
            break;
        case 'D':
            std::cout << "Введите номер счета: ";
            std::cin >> accountNumber;
            std::cout << "Введите сумму депозита: ";
            std::cin >> amount;
            deposit(accountNumber, amount);
            break;
        case 'W':
            std::cout << "Введите номер счета: ";
            std::cin >> accountNumber;
            std::cout << "Введите сумму для снятия: ";
            std::cin >> amount;
            withdraw(accountNumber, amount);
            break;
        case 'C':
            std::cout << "Введите номер счета: ";
            std::cin >> accountNumber;
            closeAccount(accountNumber);
            break;
        case 'P':
            printAllAccounts();
            break;
        case 'I':
            std::cout << "Введите процентную ставку по вкладу: ";
            std::cin >> interestRate;
            calculateInterest(interestRate);
            break;
        default:
            std::cout << "Неверный тип транзакции. Попробуйте еще раз." << std::endl;
        }
    }

    return 0;
}



/*думаю, что достаточно сыро.можно ыбло бы доьавить проверку на ошибки, но итак я нашла с прошлой пары в совоем коде очень много ошибок....*/


/*АННОТАЦИЯ:
используем структуру BankAccount, которая содержит
номер счета и баланс. Мы используем std::map для хранения счетов, где
номер счеа является ключом, а объект BankAccount - значением.
Функции openAccount, getBalance, deposit, withdraw и closeAccount реализуют
указанные операции открытия счета, запроса баланса, депозитов, снятий и
закрытия счетов соответственно.
В функциях openAccount, deposit и withdraw мы проверяем, существует ли счет
с указанным номером. Если счет существует, мы выполняем соответствующую
операцию, изменяя баланс счета и выводя результат.
Функция printAllAccounts выводит все открытые счета и их балансы.
Функция calculateInterest расчитывает новый баланс для каждого счета с
учетом указанной процентной ставки.
В основной функции main мы запрашиваем тип транзакции у пользователя и
выполняем соответствующую операцию. При вводе типа транзакции 'Q'
пользователь может выйти из программы.
Программа продолжает принимать ввод от пользователя, пока не будет
введен тип транзакции 'Q'.*/