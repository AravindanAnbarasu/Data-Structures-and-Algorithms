#include <bits/stdc++.h>
using namespace std;

/* Approach: Math
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        // Extract coordinates for readability
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];

        int a1 = rec2[0];
        int b1 = rec2[1];
        int a2 = rec2[2];
        int b2 = rec2[3];

        // MugUp non-overlap conditions
        //        x:a <= 2:1
        //        a:x <= 2:1
        //        y:b <= 2:1
        //        b:y <= 2:1

        // Case 1: If rec1 is to the left of rec2
        if (x2 <= a1) return false;  

        // Case 2: If rec1 is to the right of rec2
        if (a2 <= x1) return false;

        // Case 3: If rec1 is to the bottom of rec2
        if (y2 <= b1) return false;

        // Case 4: If rec1 is to the top of rec2
        if (b2 <= y1) return false;

        // If none of the non-overlap conditions matched, rectangles overlap
        return true;
    }
};

/***************************************************
 * Time Complexity : O(1)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    Refer image in folder for better understanding
*/

/* Question:
    An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of 
    its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges
    are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

    Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles 
    that only touch at the corner or edges do not overlap.

    Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

    Example 1:
    Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
    Output: true

    Example 2:
    Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
    Output: false
*/