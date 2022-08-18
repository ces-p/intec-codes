#include <iostream>
using namespace std;
#include <math.h>

//function that returns the standard deviation of an array
double standardDeviation(double n[]){
    double sum = 0;
    double mean = 0;
    double std = 0;
    int max_of_arr = sizeof(n)/sizeof(n[0]);
    for(int i = 0; i < max_of_arr; i++){
        sum += n[i];
    }
    mean = sum/max_of_arr;
    for(int i = 0; i < max_of_arr; i++){
        std += pow(n[i] - mean, 2);
    }
    std = sqrt(std/max_of_arr);
    return std;

}
int main()
{
    double n[6] = {1,2,3,4,5,6};
    cout<<standardDeviation(n)<<endl;
    return 0;
}