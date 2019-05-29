//Rachel Ramphal
//8 Numbers in a Cross

#include <iostream>
#include <cmath>
using namespace std;

    bool test(int cross[], int c) {
        static int neighbors[8][5] = {
            {-1},              //box 0
            {0,-1},            //box 1
            {1,-1},            //box 2 
            {0,1,2,-1},        //box 3 
            {1,2,3,-1},        //box 4
            {2,4,-1},          //box 5
            {0,3,4,-1},        //box 6
            {3,4,5,6,-1},      //box 7
        };

        //check if the # used already
        for (int i = 0; i < c; i++){
            //checks if current box contains a # in any of the previous boxes
            if (cross[c] == cross[i]) return false;
        }

        //check neighboring boxes
        for (int i = 0; i < 5; i++){
            if (neighbors[c][i] == -1) return true; //this means no number has been placed yet if equal to -1 means all the boxes its neighboring 
            //check if neighbor has adjacent #
            if (abs(cross[c] - cross[neighbors[c][i]]) == 1) return false; //means there is an adjacent # present
        }
        return true;
    }

    void print(int cross[]) {
        static int count = 0;
        cout << "Solution # " << ++count << ":" << endl;
        cout << "  " << cross[1] << " " << cross[2] << endl;
        cout << cross[0] << " " << cross[3] << " " << cross[4] << " " << cross[5] << endl;
        cout << "  " << cross[6] << " " << cross[7] << endl;
        cout << endl;
        return;
    }

int main(){
    int cross[8] = {0}, current_num = 0;

    while (current_num >= 0){

        current_num++;
        if (current_num == 8){
            print(cross);
            current_num--;
        }
        else cross[current_num] = -1;

        while (current_num >= 0){

            cross[current_num]++;
            if (cross[current_num] == 8) current_num--;
            else if (test(cross, current_num)) break;
        }
    }
    return 0;
}