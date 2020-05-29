// FPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>
using namespace std;
struct nod
{
    char inf;
    nod* s, * d;
};
nod* expresie(char*& p); /// declarare de fct (ca sa nu dea eroare) -rec indirecta
nod* frunza(char*& p)
{
    nod* vf;
    if(*p == '(') //valoarea pointerului
    {
        p++; // trece de '('
        vf = expresie(p);
        p++; //trece de ')'
    }
    else
    {
        vf = new nod;
        vf->inf = *p;
        p ++; // trece de car prel
        vf->s = vf->d = NULL;
    }
    return vf;
}
nod* factor(char*& p)
{
    nod* vf = frunza(p);///construieste o frunza ca subarbore stang al nodului cu inf ^;
    nod* aux = vf;
    while (*p == '^') {
        vf = new nod;
        vf->inf = *p;
        p++; ///folosesc inf lui p si avansez
        vf->s = aux;
        aux = vf; // se retine radacina arb. crt. daca el va deveni sub stang pt alt arb
        vf->d = frunza(p);
    }
    return vf;
}
nod* termen(char*& p)
{
    nod* vf = factor(p);
    nod* aux = vf;
    while (*p == '*' || *p == '/') {
        vf = new nod;
        vf->inf = *p;
        p++; ///folosesc inf lui p si avansez
        vf->s = aux;
        aux = vf; // se retine radacina arb. crt. daca el va deveni sub stang pt alt arb
        vf->d = factor(p);
    }
    return vf;

}
nod* expresie(char*& p) ///referinta deoarece maimulte fct il vor act pe p
{
    nod* vf = termen(p);
    nod* aux = vf;
    while (*p == '+' || *p == '-') {
        vf = new nod;
        vf->inf = *p;
        p++; ///folosesc inf lui p si avansez
        vf->s = aux;
        aux = vf; // se retine radacina arb. crt. daca el va deveni sub stang pt alt arb
        vf->d = termen(p);
    }
    return vf;
}
void preordine(nod* rad)
{
    cout << rad->inf;
    if (rad->s)
        preordine(rad->s);
    if (rad->d)
        preordine(rad->d);
}
int main()
{
    int n;
    cin >> n;
    char* p = new char[22];
    cin >> p;
    nod* rad = expresie(p);
    preordine(rad);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
