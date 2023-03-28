#include<iostream>
using namespace std;
int b[5];
const double eps=1e-8;
int search(int low, int high, int target) {
    if (low > high || target > b[high]) {
        return -1;
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (b[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}//>=
int main(){
    return 0;
}