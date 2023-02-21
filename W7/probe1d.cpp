#include <iostream>
#include "probelib.h"

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n = probe_init();
    int a = 0, b = n-1, half;
    for(int i = 0; i < n; i++) {
        half = (b+a)/2;
        if (a==b){ 
            probe_answer(a);
        }
        if (probe_check(a, half)){
            b = half;
        }
        else {
            a = half + 1;
        }
    }
    return 0;
}
