#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Account {
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
protected:
    double balance;
public:
    Account();
    Account(double balance);
    void deposit(double amount);
    void withdraw(double amount);
    double get_balance() const;
};

Account::Account()
    :Account(0.0) {   //delegarea constructorului
}

Account::Account(double balance)
    :balance(balance) {
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance - amount >= 0)
        balance -= amount;
    else
        std::cout << "Insufficient funds " << std::endl;
}

double Account::get_balance() const {
    return balance;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account balance " << account.balance;
    return os;
}


class Saving_Account : public Account {
    friend std::ostream& operator<<(std::ostream& os, const Saving_Account& account);
protected:
    double int_rate;
public:
    Saving_Account();
    Saving_Account(double balance, double int_rate);
    void deposit(double amount);
};

Saving_Account::Saving_Account(double balance, double int_rate)
    :Account(balance), int_rate(int_rate) {

}

Saving_Account::Saving_Account()
    :Saving_Account(0.0, 0.0) {

}

void Saving_Account::deposit(double amount) {
    amount = amount + amount * (int_rate / 100);
    Account::deposit(amount);                           //Refolosirea metodei din clasa de baza
}


std::ostream& operator<<(std::ostream& os, const Saving_Account& account) {
    os << "Saving account balance " << account.balance << "$ with an Interest rate: " << account.int_rate << "%";
    return os;
}

class Persoane {    
protected:
    string nume;
    string prenume;
    double salariu;
    Account account;
    Saving_Account saving_account;
public:
    Persoane(string nume, string prenume, double salariu, double saving_rate);
    void primeste_salariu();    
    friend std::ostream& operator<<(std::ostream& os, const Persoane& persoana);
};

Persoane::Persoane(string nume, string prenume, double salariu, double saving_rate)
    : nume(nume), prenume(prenume), salariu(salariu), account(0.0), saving_account(0.0, saving_rate) {
}

void Persoane::primeste_salariu() {
    account.deposit(salariu);
    if (account.get_balance() > 1000) {
        double excess = account.get_balance() - 1000;
        saving_account.deposit(excess);
        account.withdraw(excess);
    }
}

std::ostream& operator<<(std::ostream& os, const Persoane& persoana) {
    os << "Nume: " << persoana.nume << " " << persoana.prenume << ", Salariu: " << persoana.salariu << "$, \n" 
       << persoana.account << "$, " << persoana.saving_account << endl;
    return os;
}


class Angajati : public Persoane {
public:
    Angajati(string nume, string prenume, double salariu, double saving_rate)
        : Persoane(nume, prenume, salariu, saving_rate) {}
    
    void primeste_salariu() {
        Persoane::primeste_salariu();
    }
};

class Bugetari : public Persoane {
private:
    double indemnizatie;
public:
    Bugetari(string nume, string prenume, double salariu, double saving_rate, double indemnizatie)
        : Persoane(nume, prenume, salariu, saving_rate), indemnizatie(indemnizatie) {
    }

    void primeste_salariu() {
        salariu += indemnizatie;
        Persoane::primeste_salariu();
    }

    friend std::ostream& operator<<(std::ostream& os, const Bugetari& bugetar);
};

std::ostream& operator<<(std::ostream& os, const Bugetari& bugetar) {
    os << "Nume: " << bugetar.nume << " " << bugetar.prenume << ", Indemnizatie: " << bugetar.salariu << "$, din care Spor de: "
       << bugetar.indemnizatie << "$,\n" << bugetar.account << "$, " << bugetar.saving_account << endl;
    return os;
}


int main() {
    vector<Angajati> angajati;
    vector<Bugetari> bugetari;
        
    ifstream fisier_angajati("angajati.txt");
    
    string nume, prenume;
    double salariu, dobanda;

    while (fisier_angajati >> nume >> prenume >> salariu >> dobanda) {
        Angajati angajat(nume, prenume, salariu, dobanda); 
        angajati.push_back(angajat); 
    }
    fisier_angajati.close();
        
    ifstream fisier_bugetari("hoti.txt");
    
    double indemnizatie;

    while (fisier_bugetari >> nume >> prenume >> salariu >> dobanda >> indemnizatie) {
        Bugetari bugetar(nume, prenume, salariu, dobanda, indemnizatie); 
        bugetari.push_back(bugetar); 
    }
    fisier_bugetari.close();
        
    cout << "===================================== Angajati ====================================\n" << endl;
    
    for (auto& angajat : angajati) {
        angajat.primeste_salariu();
        cout << angajat << endl;
    }

    cout << "\n===================================== Bugetari ====================================\n" << endl;
    
    for (auto& bugetar : bugetari) {
        bugetar.primeste_salariu();
        cout << bugetar << endl;
    }

    return 0;
}  