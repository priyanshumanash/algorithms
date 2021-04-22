#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int i,value, j,size, q, n,which, index;
    vector <vector<int> > a;
    cin>>n>>q;
    for(i=0; i<n; i++){
        cin>>size;
        vector <int> k;
        for(j=0; j<size; j++){
            cin>>value;
            k.push_back(value);
        }
        a.push_back(k);
    }
    for(i=0; i<q; i++){
        cin>>which>>index;
        cout<<a[which][index]<<endl;
    }
    
    return 0;
}


