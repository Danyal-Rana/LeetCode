class Solution {
public:
  int totalMoney(int n)
  {
    int totalValue = 0;

    int totalWeeks = n / 7;
    int days = n % 7;
    int totalWeeksValue = totalWeeks * 28;

    totalValue = totalWeeksValue;

    if (totalWeeks >= 2)
    {
        int temp = 7;
      for (int i=1; i<totalWeeks; i++)
      {
          totalValue += temp;
          temp += 7;
      }
    }

    int weekNumber = totalWeeks + 1;
    for (int i = 1; i <= days; i++) {
      totalValue += weekNumber++;
    }

    return totalValue;
  }
};