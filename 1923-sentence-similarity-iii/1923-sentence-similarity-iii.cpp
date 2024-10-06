class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1.size() < sentence2.size())
        {
            swap(sentence1, sentence2);
        }

        vector<string>vec1, vec2;
        stringstream ss1(sentence1);
        string token;
        while (ss1 >> token)
        {
            vec1.push_back(token);
        }

        stringstream ss2(sentence2);
        while (ss2 >> token)
        {
            vec2.push_back(token);
        }


        int i=0; int j=vec1.size()-1;
        int k=0; int l=vec2.size()-1;

        while (i<vec1.size() && k<vec2.size() && vec1[i]==vec2[k])
        {
            i++;
            k++;
        }

        while (l>=k && vec1[j]==vec2[l])
        {
            j--;
            l--;
        }

        return l<k;
    }
};