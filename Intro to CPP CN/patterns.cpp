/* Patterns

first find number of rows
figure out how to print ith row   (no. of coloumns in ith row.)
what to print
*/


#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    while(i <= n){
        int j =1;
        while(j<=n){
        cout << "*" ;
        j++;
        }

        i++;
        cout << endl;
    }

    return 0;
}