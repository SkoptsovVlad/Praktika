#include <iostream>
#include <random>
using namespace std;
int main()
{
    int N = 600;
    int Arr1[N], Arr2[N] = {};
    for (int& x: Arr1)
        x = 0;
        //x = rand()%2;
    Arr1[N/2] = 1; 
    for (int i=0; i<N; i++) 
        {if (Arr1[i]) cout << '#'; else cout << '_';}
    cout << endl;
    int iteration = 300;
    for (int i=0; i<iteration; i++){
        for (int j=1; j<N-1; j++) 
            Arr2[j] = (Arr1[j-1] + Arr1[j] + Arr1[j+1]+ Arr1[j]*Arr1[j+1]) % 2;
        for (int i=0; i<N; i++) 
            {if (Arr2[i]) cout << '#'; else cout << '_';}
        cout << endl;
        for (int c=0; c<N; c++) {Arr1[c] = Arr2[c]; Arr2[c] = 0;}
    }
    return 0;
}