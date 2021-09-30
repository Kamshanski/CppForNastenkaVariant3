#include <ostream>
#include "../everything.h"
#include "Stack.cpp"
using namespace std;
/*
Составить программу, которая содержит текущую информацию о заявках на
авиабилеты. Каждая заявка включает:
 пункт назначения;
 номер рейса;
 фамилию и инициалы пассажира;
 желаемую дату вылета.
Программа должна обеспечивать:
 хранение всех заявок в виде односвязного списка;
 добавление заявок в список;
 удаление заявок;
 вывод заявок по заданному номеру рейса и дате вылета;
 вывод всех заявок.
 */

struct Ticket {
    string destination; // пункт назначения;
    string flightId;    // номер рейса;
    string lastname;    // фамилию пассажира;
    string initials;        // инициалы пассажира;
    int year;           // желаемую дату вылета.
    int month;
    int day;

    Ticket(const string &destination, const string &flightId, const string &lastname, const string &initials, int year,
           int month, int day) : destination(destination), flightId(flightId), lastname(lastname), initials(initials),
                                 year(year), month(month), day(day) {}

    Ticket(istream& is) {
        cout << "Destination: ";
        cin  >> destination;

        cout << "Flight ID: ";
        cin >>  flightId;

        cout << "Lastname: ";
        cin  >> lastname;

        cout << "Initials: ";
        cin  >> initials;

        cout << "Date of flight. Year: ";
        cin >> year;
        cout << "Date of flight. Month: ";
        cin >> month;
        cout << "Date of flight. Day: ";
        cin >> day;
    }

    friend ostream &operator<<(ostream &os, const Ticket &ticket) {
        os << ticket.destination << ", " << ticket.flightId << ", "
           << ticket.lastname << " " << ticket.initials << ", "
           << ticket.year << "." << ticket.month << "." << ticket.day;
        return os;
    }
};


struct TicketsList15 {
private:
    Stack<Ticket> list;
public:
    void printAll() {
        list.forEach([](const Ticket* book, int position) {
            cout << position << ") " << *book << endl;
        });
    }
    
    void addTicket() {
        Ticket* ticket = new Ticket(cin);
        list.push(ticket);
    }
    void addTicket(Ticket* ticket) {
        list.push(ticket);
    }

    void deleteTicket() {
        string ticketId;
        cout << "Enter flight number:\n";
        cin >> ticketId;
        // лябда. возвращает bool. захватывает ticketId по ссылке,
        // принимает аргументом указатель на ticket из списка.
        // const значит, что поля объекта ticket не будет редактироваться
        bool found = list.remove([&ticketId](const Ticket* ticket) -> bool {
            return ticket->flightId == ticketId;
        });
        if (!found) {
            cout << "No ticket was found\n";
        }
    }

    void printByTicketId() {
        string ticketId;
        cout << "Enter flight number:\n";
        cin >> ticketId;
        bool found = false;
        // лябда. возвращает void. захватывает ticketId и флаг по ссылке,
        // принимает аргументом указатель на ticket из списка и его индекс в списке.
        // const значит, что поля объекта ticket не будет редактироваться
        list.forEach([&ticketId, &found](const Ticket* ticket, int position) {
            if (ticket->flightId == ticketId) {
                cout << *ticket << endl;
                found = true;
            }
        });
        if (!found) {
            cout << "No ticket was found\n";
        }
    }

    void printByDate() {
        int year; int month; int day;
        cout << "Enter year month day:\n";
        cin >> year >> month >> day;
        bool found = false;
        // лябда. возвращает bool. захватывает year, month, day по значению и флаг по ссылке,
        // принимает аргументом указатель на ticket из списка и его индекс в списке.
        // const значит, что поля объекта ticket не будет редактироваться
        list.forEach([year, month, day, &found](const Ticket* ticket, int position) {
            if (ticket->year == year
                    && ticket->month == month
                    && ticket->day == day
            ) {
                cout << *ticket << endl;
                found = true;
            }
        });
        if (!found) {
            cout << "No ticket was found\n";
        }
    }
};

void printMenu() {
    ostringstream o;
    o << "\nSelect an action:" << endl
      << "1. Add ticket to the list..." << endl
      << "2. Delete ticket..." << endl
      << "3. Print tickets by flight number..." << endl
      << "4. Print tickets by date..." << endl
      << "5. Print all tickets" << endl
      << "0. Shutdown";
    string infoMsg = o.str();
    string yourChoiceMsg = "\nYour choice: ";
    cout << infoMsg << endl;
    cout << yourChoiceMsg;
}

int main() {
    TicketsList15* peopleList = new TicketsList15();
    peopleList->addTicket(new Ticket("Milano", "TM589", "Voronov", "A.P.", 2021, 10, 16));
    peopleList->addTicket(new Ticket("Moscow", "TMS987A", "Eryomkina", "A.S.", 2020, 7, 6));
    peopleList->addTicket(new Ticket("Anadyr", "A898T", "Konovalov", "R.V.", 2021, 1, 8));
    peopleList->addTicket(new Ticket("Rome", "RQ9QE-B", "Andronova", "P.B.", 2021, 5, 4));


    bool mayExit = false;
    do {
        printMenu();
        char command;
        cin >> command;
        if (command >= '0' && command <= '5') {
            switch (command) {
                case '1': peopleList->addTicket(); break;
                case '2': peopleList->deleteTicket(); break;
                case '3': peopleList->printByTicketId(); break;
                case '4': peopleList->printByDate(); break;
                case '5': peopleList->printAll(); break;
                case '0': mayExit = true; break;
            }
        } else {
            cout << "Unknown command. Try again." << endl;
        }
    } while (!mayExit);

    cout << "\nShutdown program\n";
    return 0;
}