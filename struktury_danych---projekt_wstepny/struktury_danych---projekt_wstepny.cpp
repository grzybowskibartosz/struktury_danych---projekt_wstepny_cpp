#include<iostream>
#include<chrono>
#include<fstream>
#include"stoss.h"

using namespace std;

int main()
{
    ofstream zapis("czasy_dzialania.txt", ios_base::app);
    stoss stack; //utworzenie stosu

    for (int l_ele = 10; l_ele < 10000000; l_ele = l_ele * 10) {
        auto start = chrono::high_resolution_clock::now();
        for (int i = 1; i <= l_ele; i++) {
            stack.push(i);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        cout << "Czas trwania operacji push: " << duration << " microsec" << endl;
        zapis << l_ele << "," << duration << ",";


        auto start2 = chrono::high_resolution_clock::now();
        for (int i = 1; i <= l_ele; i++) {
            stack.pop();
        }
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count();

        cout << "Czas trwania operacji pop: " << duration2 << " mikrosec" << endl;
        zapis << duration2 << endl;
    }
    return 0;
}