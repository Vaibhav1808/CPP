 #include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=n;
 
        while(j>=i)
        {
            cout<<n-j+1;
            j--;
        }
        j=n;
        int stars=1;
        while(stars<=2*i-2)
        {
            cout<<"*";
            stars++;
        }
        while(j>=i)
        {
            cout<<j-i+1;
            j--;
        }

        cout<<endl;
        i++;
    }
}