//Insertion Sort Using In-Place Algorithm
#include <bits/stdc++.h>
using namespace std;

//Creating Insertion Sort void function for in place

void insertion_sort_IP(int arr[],int n){
    //Initialising variables i and j
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}

//Insertion Sort Using Out-Place Algorithm
void insertion_sort_OP(int arr[],int si,int ei){
    //si=starting index
    //ei=ending index
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){arr[0]=temp;break;}
        if(arr[si]<=temp){arr[si+1]=temp;break;}
    }
    insertion_sort_OP(arr,si+1,ei);
}
//Function to print array
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}

int main(){
    int n;
    //Taking Input array
    cout<<"ENTER NUMBER OF ELEMENTS IN THE ARRAY: ";
    cin>>n;
    int arr[n],arr2[n];//Two array with same size and elements
    cout<<"ENTER ELEMENTS OF ARRAY SEPERATED BY SPACE: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"ARRAY BEFORE SORTING : ";printarr(arr,n);
    //Calling insertion sort using in-place algorithm.
    insertion_sort_IP(arr,n);
    cout<<endl;
    cout<<"ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    //printing the array
    printarr(arr,n);
    cout<<endl;
    //calling insertiong sort using out-place algorithm.
    insertion_sort_OP(arr2,0,n-1);
    cout<<"ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    //printing the array
    printarr(arr,n);
    cout<<endl;

}