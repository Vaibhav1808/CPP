#include <iostream>
using namespace std;

int main(){
    char c;
    c = cin.get();
    int count_char = 0;
    int count_digits = 0;
    int count_spaces = 0;
    while(c != '$'){
        if(97 <= int(c) && int(c) <= 122){
            count_char++;
        }
        else if(49 <= int(c) && int(c) <= 57){
            count_digits++;
        }
        else{
            count_spaces++;
        }
        c = cin.get();
    }
    cout << count_char << " " << count_digits << " " << count_spaces;

    return 0;
}