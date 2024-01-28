#include<iostream>
using namespace std;
int main(){
    int n = 3;
//      int space = 2*(n-1);
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=i;j++)
//         cout<<j;

//         for(int j=1; j<=space; j++)
//             cout<<" ";

//         for(int j=i; j>=1; j--)
//             cout<<j;
        
//         cout<<endl;
//         space-=2;
//    }
// for(int i=0; i<n; i++){

//         for(int j=0; j<n-i-1; j++)
//             cout<<" ";
        
//         char ch = 'A';
//         int breakPoint = (2*i + 1)/2;

//         for(int j=1; j<=2*i+1; j++){
//             cout<<ch;
//             if(j<=breakPoint) ch++;
//             else ch--;

//         }
//          for(int j=0; j<n-i-1; j++)
//             cout<<j;
        
//         cout<<endl;
//     }
//  int space = 0;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n-i; j++)
//             cout<<" ";
            
//         for(int j=0; j<space; j++)
//             cout<<"*";

//         for(int j=0; j<n-i; j++)
//             cout<<" "; 
//         space+=2;
//         cout<<endl;           
//     }
//     space = 2*n-2;
//     for(int i=0;i<n;i++){
//         for(int j=0; j<=i; j++)
//             cout<<" ";
//         for(int j=0; j<space; j++)
//             cout<<"*";

//         for(int j=0; j<=i; j++)
//              cout<<" ";
//         space-=2;
//         cout<<endl;
//     }

 int space = 2*n-2;
    // Write your code here.
    for(int i=0; i<2*n-1; i++){
        if(i<n){
            for(int j=0; j<=i; j++)
            cout<<"* ";

            for(int j=0;j<space;j++)
            cout<<" ";

            for(int j=0; j<=i; j++)
            cout<<"* ";

            space-=2;
            cout<<endl;

        }

        // else{

        // }
    }
    return 0;
}