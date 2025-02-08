# include <iostream>
using namespace std;

void print1(int n){
    for(int i =0; i < n; i++){
        for(int j=0; j < n; j++){
            cout << "* ";
        }
        cout << '\n';
    }
/*
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 
*/
}
void print2(int n){
    for(int i = 0; i< n; i++){
        for (int j=0; j <=i; j++){
            cout << "* ";
        }
        cout << '\n';
    }
/* 
* 
* * 
* * * 
* * * * 
* * * * * 
*/
}
void print3(int n){
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j <=i; j++){
            cout << j << ' ';
        }
        cout << '\n';
    }
/*
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5
*/
}
void print4(int n){
    for (int i= 1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cout << i << ' ';
        }
        cout << '\n';
    }
/*
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 
*/
}
void print5(int n){
    for (int i= 0 ; i<n; i++ ){
        for (int j=n-i; j>0;j--){
            cout << "* ";
        }
        cout << '\n';
    }
/*

* * * * * 
* * * * 
* * * 
* * 
* 

*/
}
void print_extra(int n){
    for(int i =0; i < n ;i++){
        for (int j = n - i ; j >0; j--){
            cout << j << ' ';
       }
       cout << '\n';
    }
/*
5 4 3 2 1 
4 3 2 1 
3 2 1 
2 1 
1 
*/
}
void print6(int n){
    for(int i =0; i < n ;i++){
        for (int j = 1; j < n+1-i; j++){
            cout << j << ' ';
       }
       cout << '\n';
    }
/*
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 
*/
}
void print7(int n){
    for(int i =0; i < n; i++){
        for (int j=0; j < n-i-1 ; j++){
            cout << "  ";
        }
        for (int j =0; j < 2*i+1; j++){
            cout << "* ";
        }
        for (int j=0; j < n-i-1 ; j++){
            cout << "  ";
        }
        cout <<'\n';
    }
/*
        *           
      * * *         
    * * * * *       
  * * * * * * *     
* * * * * * * * *   
*/
}
void print8(int n){
    for (int i =0; i<n; i++ ){
        for (int j= 0; j < i ; j++){
            cout << "  ";
        }
        for (int j = 0 ; j < 2*n-1-2*i ; j++){
            cout << "* ";
        }
        for (int j = 0; j < i; j++){
            cout << "  ";
        }
        cout << '\n';
    }
/*
* * * * * * * * * 
  * * * * * * *   
    * * * * *     
      * * *       
        *   
*/
}
void print9(int n){
    // combine print7 and print8
    // symmetry question.
}
void print10(int n){
    for(int i =1; i < 2*n; i++){
        int stars = i;
        if (i > n) stars = 2*n-i;    
        for (int j =1; j <= stars; j++){
            cout << "* ";
        }
        cout << '\n';
    }
/*

* 
* * 
* * * 
* * * * 
* * * 
* * 
* 

*/
}
void print11(int n){
    for(int i =1; i <= n; i++){
        for(int j =1; j <= i; j++){
            if ((i-j) % 2 ==0 ){
                cout << "1 "; 
            } else {
                cout << "0 ";
            }
        }
        cout << '\n';
    }
/*
1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1 
*/
}
void print12(int n){
    for ( int i=1; i <=n; i++){
        for ( int j =1 ; j<=i; j++ ){
            cout << j << ' ';
        }
        for (int j=1; j<=2*(n-i); j++){
            cout << "  ";
        }
        for (int j = i; j>0; j--){
            cout << j << ' ';
        }
        cout << '\n';
    }
/*
1                 1 
1 2             2 1 
1 2 3         3 2 1 
1 2 3 4     4 3 2 1 
1 2 3 4 5 5 4 3 2 1 
*/
}
void print13(int n){
    int num = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0 ; j <= i; j++){
            cout << num++ << ' ';   // num ++ prints num first then in next loop executes num+1.
        }
        cout << '\n';
    }
/*
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
*/
}
void print14(int n){
    for (int i =0 ; i < n; i++){
        for (char j = 'A'; j <= 'A'+i; j++){
            cout << j << ' ';
        }
        cout << '\n';
    }
/*
A 
A B 
A B C 
A B C D 
A B C D E 
*/
}
void print15(int n){
    for (int i =0; i < n ; i ++) {
        for (char j ='A'; j < 'A' + (n -i); j++){
            cout << j << ' ';
        }
        cout << '\n';
    }
/*
A B C D E 
A B C D 
A B C 
A B 
A 
*/
}
void print16(int n ){
    for (int i =0; i <n; i++){
        char c = 'A'+i;
        for(int j =0; j <=i; j++ ){
            cout << c << ' ';
        }
        cout << '\n';
    }
/* 
A 
B B 
C C C 
D D D D 
E E E E E 
*/
}
void print17(int n){
    for(int i= 0; i <n ; i++){
        for (int j=1; j <n-i; j++){
            cout << "  ";
        }
        char c = 'A';
        for (int j = 0; j < (2*i +1); j++){
            if(j>=i) {
                cout << c-- << ' ';
            } else {
                cout << c++ << ' ';
            }
        }
        for (int j=1; j <n-i; j++){
            cout << "  ";
        }
        cout << '\n';
    }
/*
        A         
      A B A       
    A B C B A     
  A B C D C B A   
A B C D E D C B A 
*/
}
void print18(int n){
    for (int i =0; i< n; i++){
        char c = 'A' + (n-1);
        for (int j =0; j<=i ; j++){
            cout << char(c -i +j) << ' ';
        }

        // for (char ch = c-i; ch <= c; ch++){
        //     cout << ch;
        // }
        cout << '\n';
    }
/*
E 
D E 
C D E 
B C D E 
A B C D E 
*/
}
void print19(int n ){
    for (int i = 1; i <= n ; i ++){
        for ( int j= 0 ; j<= n-i; j ++){
            cout << "* "; 
        }
        for (int j = 0 ; j < 2*(i-1) ;j ++){
            cout << "  ";
        }
        for (int j = 0 ; j <= n-i; j++){
            cout << "* ";
        }
        cout << '\n';
    }
    for (int i = 1; i <= n ; i ++){
        for ( int j= 0 ; j<i; j ++){
            cout << "* "; 
        }
        for (int j = 0 ; j < 2*(n-i) ;j ++){
            cout << "  ";
        }
        for (int j = 0 ; j <i; j++){
            cout << "* ";
        }
        cout << '\n';
    }
/*
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 * 
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
 */
}
void print20(int n){
    for (int i = 1; i < 2*n; i++){
        int cond = i;
        if (i>n) cond = 2*n -i;
        for (int j = 0; j < cond; j++){
            cout << "* "; 
        }
        for (int j = 0; j< abs(2*(n-i)); j++ ){
            cout << "  ";
        }
        for (int j = 0; j < cond; j++){
            cout << "* "; 
        }
        cout << '\n';
    }
/*
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 * 
*/
}
void print21(int n){
    for (int i = 0; i < n ; i ++){
        for (int j =0 ; j < n; j ++){
            if (i ==0 || j == 0 || i == n-1 || j == n-1) cout << "* ";
            else cout << "  ";
        }
        cout << '\n';
    }
/*
* * * * * * 
*         * 
*         * 
*         * 
*         * 
* * * * * * 
*/
}
void print22(int n){
    for (int i = 0; i < 2*n-1 ; i ++){
        for (int j = 0; j < 2*n-1 ; j ++){
            int top = i;
            int bottom  = 2*n -2 -i ;
            int left =j;
            int right = 2*n-2 -j;
            cout << (n - min(min (top, bottom), min (left, right))) << ' ';
        }
        cout << '\n';
    }
/*
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5 
*/
}
int main (){
    int n ;
    cin >> n;
    print22(n);
    return 0;
}