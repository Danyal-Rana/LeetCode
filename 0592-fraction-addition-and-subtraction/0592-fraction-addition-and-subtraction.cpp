class Solution {
public:
    string fractionAddition(string expression)
    {
        int nume = 0;
        int deno = 1;
        int n = expression.length();

        int i = 0;

        while (i < n)
        {
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expression[i] == '-');

            if ((expression[i]=='+') || (expression[i]=='-'))
            {
                i++;
            }

            // building currNume
            while (i<n && isdigit(expression[i]))
            {
                int val = expression[i]-'0';
                currNume = (currNume*10) + val;
                i++;
            }

            i++; //skipping /

            if (isNeg)
            {
                currNume *= -1;
            }

            // building currDeno
            while (i<n && isdigit(expression[i]))
            {
                int val = expression[i]-'0';
                currDeno = (currDeno*10) + val;
                i++;
            }

            nume = nume*currDeno + deno*currNume;
            deno = deno*currDeno;
        }

        int GCD = abs(__gcd(nume, deno));

        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + "/" + to_string(deno);
    }
};