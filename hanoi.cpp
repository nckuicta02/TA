#include <iostream>

using namespace std;

const int MAX = 1000;

int haha(int cici) {
    return cici;
}


/* move plates from source(src) to target(tar) */
void move(int* src, int* tar, int &psrc, int &ptar, int &sp) {
    // if source tower has no plates on it
    if (psrc == 0) {
        cout << "\n##ERROR! source tower has no plate on it\n";
        return;
    }
    // legal case
    if (src[psrc - 1] < tar[ptar - 1] || ptar == 0) {
        tar[ptar] = src[psrc - 1]; 
        psrc--;
        ptar++;
        sp++;
    }
    // illegal case
    else {
        cout << "\n##ERROR! Put large plate on small plate\n";
    }
    return;
}

/* show current state on each tower */
void show(int* A, int* B, int* C, int pA, int pB, int pC) {
    cout << "----------\n";
    cout << "[A]: ";
    for (int i = 0; i < pA; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "[B]: ";
    for (int i = 0; i < pB; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    cout << "[C]: ";
    for (int i = 0; i < pC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    cout << "----------\n\n";
}

/* check if user win */
bool check(int* C, int pC, int num) {
    if (pC == num && C[pC-1] == 1) {
        return true; 
    } else {
        return false;
    }
}

/* main function */
int main() {
    // state of each tower: A, B, C
    int A[MAX];
    int B[MAX];
    int C[MAX];
    // point to next element of each tower 
    int pA, pB = 0, pC = 0; 
    
    // calculate step
    int sp = 0;

    // user input: number of total plates
    int num;
    cout << "# of plates: ";
    cin >> num;
    
    // initial state: all plates puts on tower A
    pA = num;
    for (int i = 0; i < num; i++) {
        A[i] = num - i;
    }

    // initial show state
    show(A, B, C, pA, pB, pC);

    // user input: source and destination tower 
    char from, to;
    
    // if win
    bool suc = false;
    while (!suc) {
        cout << "from: ";
        cin >> from;
        cout << "to: ";
        cin >> to;

        // show the answer
        if (from == '#' && to == '#') {
            hanoi(num, '1', '2', '3', sp);
            cout << "WIN!! Total steps is " << sp << endl;
			system("pause");
            return 0;
        }
        
        // each available movement
        if (from == 'A' && to == 'B') {
            move(A, B, pA, pB, sp);
        } else if (from == 'A' && to == 'C') {
            move(A, C, pA, pC, sp);
        } else if (from == 'B' && to == 'A') {
            move(B, A, pB, pA, sp);
        } else if (from == 'B' && to == 'C') {
            move(B, C, pB, pC, sp);
        } else if (from == 'C' && to == 'A') {
            move(C, A, pC, pA, sp);
        } else if (from == 'C' && to == 'B') {
            move(C, B, pC, pB, sp);
        } else {
            cout << "\n##ERROR! error source or destination\n";
        }

        // show the answr
        show(A, B, C, pA, pB, pC);

        // check if win
        suc = check(C, pC, num);
        if (suc) {
            cout << "WIN!! Total steps is " << sp << endl;
			system("pause");
        }
    }
    return 0;
}
