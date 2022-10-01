#include <bits/stdc++.h>
using namespace std;

// 2 halves ko sorted array mai merge kar rha
// void merge(int input[], int s, int e, int mid)
// {
//     int i = s;
//     int j = mid + 1;
    //     int k = 0;
    //     int temp[e-s+1];

    // // dono parts ko temp mai merge kr rha
    // 	while (i <= mid && j <= e){
    //         if(input[i] < input[j]){
    //             temp[k] = input[i];
    //             k++;
    //             i++;
    //         }
    //         else{
    //             temp[k] = input[j];
    //             k++;
    //             j++;
    //         }
    //     }

    //     // s se mid walo ko temp wale m daal rha
    //     while (i <= mid){
    //         temp[k] = input[i];
    //         k++;
    //         i++;
    //     }
    //     // mid+1 se end tak temp m daal rha
    //     while(j <= e){
    //         temp[k] = input[j];
    //         k++;
    //         j++;
    //     }

    // // fir sorted data vapis input mai daal rha
    //     for(i = s; i <= e; i++){
    //         input[i] = temp[i-s];
    //     }
//}

// ye array ko do parts m tod rha
void mergeSort(int input[], int length)
{
    int s = 0;
    int e = length - 1;
    int mid = (e + s)/2;

    // base case
    if (length < 2)
    {
        return;
    }

    // if (s <= e)
    // {
        
        // data ko halves m divide kr rha
        mergeSort(input, mid + 1);
        mergeSort(input + mid + 1, mid);
        // sorted data ek saath daal rha
        // merge(input, s, e, mid);
        int k = 0;
        int temp[length];
        int d = mid + 1;
        // dono parts ko temp mai merge kr rha
        while (s <= mid && d < length)
        {
            if (input[s] < input[d])
            {
                temp[k] = input[s];
                k++;
                s++;
            }
            else
            {
                temp[k] = input[d];
                k++;
                d++;
            }
        }

        // s se mid walo ko temp wale m daal rha
        while (s <= mid)
        {
            temp[k] = input[s];
            k++;
            s++;
        }
        // mid+1 se end tak temp m daal rha
        while (d < length)
        {
            temp[k] = input[d];
            k++;
            d++;
        }

        // fir sorted data vapis input mai daal rha
        for (int i = 0; i < length; i++)
        {
            input[i] = temp[i];
        }
    //}
}

int main()
{

    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}