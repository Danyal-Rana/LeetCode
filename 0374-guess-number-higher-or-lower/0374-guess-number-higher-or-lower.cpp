/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n)
    {
        int lInd = 0;
        int rInd = n;

        while (lInd <=rInd)
        {
            int mInd = lInd + (rInd-lInd) / 2;
            if (guess(mInd)==0)
            {
                return mInd;
            }

            else if (guess(mInd) == -1)
            {
                rInd = mInd-1;
            }

            else if (guess(mInd)==1)
            {
                lInd = mInd+1;
            }
        }
        return -1;                
    }
};