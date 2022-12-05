#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(int* arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i = 0;i < n1;i++){
        L[i] = arr[l+i];
    }
    for(j = 0;j < n2;j++){
        R[j] = arr[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }

        else{
            arr[k] = R[j];
            j++;
        }

        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int* arr, int l, int r){
    if(l < r){
        int m = l+(r-l)/2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void count_prime(int arr_index, int& count_prime){
    int flag = 0;
    int m = arr_index/2;
    if(arr_index == 1){
        flag = 1;
    }
    for(int i = 2;i <= m ;i++){
        if(arr_index % i == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << arr_index << " ";
        count_prime++;
    }
}



int main(int argc, char** argv){
    int size = 22, count = 0;
    while(size > 20){
    cout << "Enter the size you want: ";
    cin >> size;
    }

    int* d_arr = new int[size];
    int v_size = 0;

    for(int i = 0;i < size;i++){
        d_arr[i] = rand()%50 + 1;
    }

    merge_sort(d_arr, 0, size-1);
    for(int i = 0;i < size;i++){

            cout << d_arr[i] << " ";
            
        
    }

    cout << endl;

    for(int i = 0;i < size;i++){
        
            count_prime(d_arr[i],count);

    }
    cout << endl;
    cout <<"THe number of prime numbers: " << count << endl;
    cout << endl;
    

    delete [] d_arr;
    d_arr = NULL;
return 0;
}