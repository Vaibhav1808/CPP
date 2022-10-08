#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int i = 10;  // initialise saath saath krna pdta

    int j = 12;
    const int & k = j; // path ko constant krdiya
    // k ke through bs read kr skte j se change bhi kr skte
    // changes k mai bhi reflect honge
    // sirf j++ kr skte
    // agar k aur j dono ke aage const lga diya toh na j++ na k++
    return 0;
}