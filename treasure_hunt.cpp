#include<bits/stdc++.h>
#define pb push_back
#define vi vector < int >
#define MAXN 100000

using namespace std ;


int visited[MAXN] ;
vi answer_array ;

int run_bfs(int steps[], int n) {
    queue < int > q;
    q.push ( 0 ) ;
    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        if ( u == n-1 ) {
            return 1 ;
        }
        if (visited[u]) {
            // stuck in an infinite loop
            return -1 ;
        }
        if (steps[u] == 0) {
            // becomes a zombie
            return 0 ;
        }
        visited[u] = 1 ;
        int v = u + steps[u] ;
        if ( v < 0 || v >= n ) {
            // outside the game
            return -1 ;
        }
        q.push ( v ) ;
    }
    // should never reach here
    return -1 ;
}

int solveUtil ( int steps[], int n ) {
    for ( int i = 0 ; i < n ; i++ ) {
        visited[i] = 0 ;
    }
    int ans = run_bfs(steps, n) ;
    if (ans != 1) return ans ;
    assert(ans == 1);
    // answer exists
    answer_array.clear() ;
    int start = 0 ;
    while ( start != n-1 ) {
        answer_array.pb ( start ) ;
        start = start + steps[start] ;
    }
    return 1 ;
}

void run_test_case_1() {
    int n = 7 ;
    int steps[6] = {2,1,2,0,2,-1} ;
    int answer = solveUtil(steps, n);
    assert(answer == 1) ;
    assert(answer_array.size() == 3);
    assert(answer_array[0] == 0);
    assert(answer_array[1] == 2);
    assert(answer_array[2] == 4);
    cout << "Test Case 1: Successful\n";
}

void run_test_case_2() {
    int n = 7 ;
    int steps[6] = {2,4,3,0,-1,-1} ;
    int answer = solveUtil(steps, n);
    assert(answer == 0) ;
    cout << "Test Case 2: Successful\n";
}

void run_test_case_3() {
    int n = 7 ;
    int steps[6] = {2,10,1,-1,1,-2} ;
    int answer = solveUtil(steps, n);
    assert(answer == -1) ;
    cout << "Test Case 3: Successful\n";
}

int test() {
    // If you want to test the program, comment everything in main,
    // and call test()
    run_test_case_1();
    run_test_case_2();
    run_test_case_3();
    return 1;
}

int main () {

    test();
    // Input size of the array (number of steps)
    int n ; scanf ( "%d" , &n ) ;
    int a[n+10];
    // Take n-1 inputs (last is always Treasure
    for ( int i = 0 ; i < n-1 ; i++ ) {
        // Input each step (could be +ve or -ve)
        scanf ( "%d" , &a[i] ) ;
    }
    string treasure ; cin >> treasure ;
    int answer = solveUtil ( a , n ) ;
    if ( answer == 0 ) {
        // Case when princess becomes Zombie
        cout << "0\n" ;
    }
    if ( answer == -1 ) {
        // Case when princess is stuck in infinite loop
        cout << "-1\n" ;
    }
    // If princess doesn't become a zombie or isn't stuck in infinite loop,
    // then she must have gotten the treasure
    assert(answer == 1);
    for ( int i = 0 ; i < answer_array.size() ; i++ ) {
        cout << a[i] << " " ;
    }
    cout << "Treasure" << endl ;
    return 0 ;
}
