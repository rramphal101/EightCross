//Rachel Ramphal
//Recursive 8 Cross

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int * q, int c){
   static int helper[8][5] = {
            {-1},              //box 0
            {0,-1},            //box 1
            {1,-1},            //box 2 
            {0,1,2,-1},        //box 3 
            {1,2,3,-1},        //box 4
            {2,4,-1},          //box 5
            {0,3,4,-1},        //box 6
            {3,4,5,6,-1},      //box 7
        };

    for (int i = 0; i < c; i++){
        if (q[c] == q[i]) return false;
    }

    for (int i = 0; i < 5; i++){
        if (helper[c][i] == -1) return true;
        if (abs(q[c] - q[helper[c][i]])== 1) return false;
    }
    return true;
}

void print(int * q){
   static int count = 0;
        cout << "Solution # " << ++count << ":" << endl;
        cout << "  " << q[1]+1 << " " << q[2]+1 << endl;
        cout << q[0]+1 << " " << q[3]+1 << " " << q[4]+1 << " " << q[5]+1 << endl;
        cout << "  " << q[6]+1 << " " << q[7]+1 << endl;
        cout << endl;
        return;
}

void move(int* q, int i){
    if (i == 8){
        print(q);
        return;
    }

    for (int j = 0; j < 8; j++){
        q[i] = j;
        if (ok(q,i)) move(q, i+1);
    }
}

int main(){
    int q[8];
    move(q,0);
}