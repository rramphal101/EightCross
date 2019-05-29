# Eight Cross

The objective of this puzzle is to place the numbers 1-8 within the cross such that no two adjacent boxes contain consecutive
integers.  
(In this context, adjacent refers to boxes that are vertically, horizontally, and diagonally next to each other.) 

### 8 Cross: 
This solution solves the puzzle non-recursively.  
I have used two while loops in the main function to fill in the cross.  
The test function contains a "neighbor" array which is used to list the boxes that neighbor that box, 
but only the ones that come before it. For example, box 0 has 3 neighbors, but none are listed in the array because they
will not be given a value before box 0 as it is the first box to be filled.  
The value of -1 is the last column of every row because -1 is used to show that a number has not been assigned to that box yet.  

The test function also checks if it is okay to place a number in the box.  

### 8 Cross Recursive: 
This solution solves the same puzzle with a similar test function (called "ok" in this code) to place the numbers in the 
cross.  
However, instead of using while loops within the main function, the "ok" function is called recursively to fill in the cross.  

The output of both codes is the shape of the cross printed with the numbers showing being the number placed in that box.  
