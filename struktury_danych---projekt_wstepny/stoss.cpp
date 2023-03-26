#include "stoss.h"
#include<iostream>

using namespace std;

stoss::stoss()
{
    { i = 0; f = 1; el = NULL; };
}

stoss::~stoss()
{
    {
        while (el != NULL)
        {
            pom = el->poprzedni;
            delete el;
            el = pom;
        }
    }
}

void stoss::push(int x)
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

int stoss::pop()
{
    if (el == NULL) return 0; //gdy stos jest pusty

    pom = el->poprzedni;
    delete el;
    el = pom;
    --i;

    return 1;
}

int stoss::value()
{
    if (!empty())
        return el->element;

    return ERROR;
}

bool stoss::empty()
{
    return i == 0 ? 1 : 0;
}

unsigned int stoss::size()
{
    return i;
}
