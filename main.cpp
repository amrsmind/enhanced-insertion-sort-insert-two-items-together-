#include <iostream>
#include <ctime>
#include <random>
#include <fstream>

using namespace std;

void swap(int *x,int *y){
    int *temp = x;
    x=y;
    y=temp;
}

int insertionsort(int arr[],int size){
int counter =0;
int temp;
for(int i=1;i<size;i++){
    counter++;
    temp = arr[i];
    int j=i-1;
    while(temp<arr[j] && j>=0){
        counter+=2;
        arr[j+1] = arr[j];
        j--;
    }
arr[j+1] = temp;
}
counter+=2;
return counter;
}

int enhancedinsertionsort(int arr[],int size){
int counter=0;
       for(int i=1;i<=(size-2);i+=2){ //1
            counter+=2;
        if(arr[i]>arr[i+1]){ //1
            int maxtemp = arr[i];
            int mintemp = arr[i+1];
            int j=i-1;
            while(maxtemp<arr[j] && j>=0){ //1
                counter+=2;
                    arr[j+2] = arr[j];
                    j--;
            }
            arr[j+2] = maxtemp;
            while(mintemp<arr[j] && j>=0){ //1
                counter+=2;
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = mintemp;
            }
            else{
                int maxtemp = arr[i+1];
                int mintemp = arr[i];
                int j=i-1;
                while(maxtemp<arr[j] && j>=0){
                    counter+=2;
                    arr[j+2] = arr[j];
                    j--;
                }
                arr[j+2] = maxtemp;
                while(mintemp<arr[j] && j>=0){
                    counter+=2;
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = mintemp;
            }
       }
       counter++;
       if(size%2==0){
        int temp = arr[size-1];
        int j=size-2;
        while(temp<arr[j]&&j>=0){ //1
                counter+=2;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
       }
        counter+=5;
return counter;
}

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout <<arr[i]<<"  ";
    }
    cout <<endl;
}

int main()
{
    ofstream plotting;
    plotting.open("plotting.csv",ios::app);
    plotting<<"running_time,"<<"size_of_array"<<endl;
    for(int range=450000;range<=500000;range+=50000){
        int arr[range];
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0,1000);
       for(int i=0;i<range;i++){
            arr[i] = distr(eng);}
            clock_t start, end;
            double msecs;
            start = clock();
            int comparisons = enhancedinsertionsort(arr,range);
            end = clock();
            msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
            cout <<msecs<<"  "<<range<<endl;
            plotting<<msecs<<","<<range<<endl;
            }
//ofstream plotinserstionsort;
//plotinserstionsort.open("insertionsort.csv",ios::app);
//    plotinserstionsort<<"running_time,"<<"size_of_array"<<endl;
//    for(int range=550000;range<=1000000;range+=50000){
//        int arr[range];
//        random_device rd;
//        mt19937 eng(rd());
//        uniform_int_distribution<> distr(0,1000);
//       for(int i=0;i<range;i++){
//            arr[i] = distr(eng);}
//            clock_t start, end;
//            double msecs;
//            start = clock();
//            int comparisons = insertionsort(arr,range);
//            end = clock();
//            msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
//            cout <<msecs<<"  "<<range<<endl;
//            plotinserstionsort<<msecs<<","<<range<<endl;
//            }




    return 0;
}
