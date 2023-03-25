#include<iostream>
#include<chrono>

using namespace std;

class stos {
public:
    stos() { i = 0; f = 1; el = NULL; }
    ~stos() //zwolnienie pamięci dla elementów stosu
    {
        while (el != NULL)
        {
            pom = el->poprzedni;
            delete el;
            el = pom;
        }
    }
    unsigned int size() { return i; }//liczba elementów w kolejce
    void push(int x)//dodanie elementu na szczyt stosu
    {
        if (f)//sprawdzamy, czy pierwszy raz dodajemy element
        {
            f = 0;
            el = new wezel;
            el->element = x;
            el->poprzedni = NULL;
        }
        else
        {
            pom = new wezel;
            pom->element = x;
            pom->poprzedni = el;
            el = pom;
        }
        ++i;
    }
    int pop()// usunięcie elementu z wierzchołka
    {
        if (el == NULL) return 0; //gdy stos jest pusty

        pom = el->poprzedni;
        delete el;
        el = pom;
        --i;

        return 1;
    }
    int value() //zwrócenie ostatniego elementu na stosie
    {
        if (!empty())
            return el->element;

        return ERROR;
    }
    bool empty()
    {
        return i == 0 ? 1 : 0;
    }
    const int ERROR = 1000000000; //ta wartosć nie może się pojawić na stosie
private:
    bool f; //flaga okreslająca, czy w kolejce cos już się pojawiło
    struct wezel {
        int element; //wartosć elementu stosu
        wezel* poprzedni;  //wskaźnik na poprzedni element
    };
    unsigned int i; //zmienna przechowuje liczbę elementów na stosie
    wezel* el, //ostatni element na stosie
        * pom; //zmienna pomocnicza
};

int main()
{
    stos stack; //utworzenie stosu

    auto start = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100000; i++)
    {
        stack.push(i);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    cout << "Czas trwania operacji push: " << duration << " microsec" << endl;
   

    cout << "Liczba elementow na stosie: " << stack.size() << endl;
    cout << "Element, ktory mozna usunac: " << stack.value() << endl;
    auto start2 = chrono::high_resolution_clock::now();
    stack.pop(); //usunięcie 99
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count();
    cout << "Czas trwania operacji pop: " << duration2 << " mikrosec" << endl;
    stack.pop(); //usunięcie 43
    cout << "Element, ktory mozna usunac: " << stack.value() << endl;
    stack.pop(); //usunięcie 23
    stack.pop(); //usunięcie 12
    if (stack.empty())
        cout << "Stos jest pusty\n";
    else
        cout << "Na stosie znajduja sie elementy, jest ich " << stack.size() << endl;

    if (!stack.pop())
        cout << "Nie mozna usunac elementu ze stosu, poniewaz jest on pusty\n";

    return 0;
}