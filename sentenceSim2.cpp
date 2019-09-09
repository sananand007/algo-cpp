#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>

using namespace std;


// Start using a map for maintaining a dctionary to try DFS - this solves it, but recurssive dfs is slower
// Use a disjoint set if you need to use UnionFind -- This will be faster


class Solution {
    // This Solution is just similarity and not testing transitive nature
    public:
        bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
            vector<int> res;
            if (words1.size() != words2.size())
                return 0;
            else
            {
                auto it1 = words1.begin();
                auto it2 = words2.begin();

                while (it1 != words1.end()) 
                {
                    cout << *it1 << " "<< *it2 << endl;
                    vector<string> temp1 = {*it1, *it2};
                    vector<string> temp2 = {*it2, *it1};
                    if (*it1 == *it2 || std::find(pairs.begin(), pairs.end(), temp1) != pairs.end() || std::find(pairs.begin(), pairs.end(), temp2) != pairs.end())
                        res.push_back(1);
                    else
                    {
                        res.push_back(0);
                    }
                    ++it1;
                    ++it2;
                }

                // check if all of res is 1 else return 0
                if (std::count(res.begin(), res.end(), 0))
                    return 0;
                else
                    return 1;
            }
            
        }
};

class Solution2 {
    // This Solution is for checking the transitive nature as well
    public:
        void print(vector<string>const &input)
        {
            for (int i = 0; i < input.size(); i++) {
                cout << input.at(i) << ' ';
            }
        }
        void printint(vector<int>const &input)
        {
            for (int i = 0; i < input.size(); i++) {
                cout << input.at(i) << ' ';
            }
        }
        vector<int> dfs(map<string, vector<string>>& g, string& n, string& search, vector<string>& visited, vector<int>& store) {
            // cout << "check1st " << n << " " << search << endl;
            // cout << "visited ";
            if (std::find(visited.begin(), visited.end(), n) == visited.end())
                {
                    visited.push_back(n);
                    //print(visited);
                    if (std::find(g[n].begin(), g[n].end(), search) != g[n].end())
                        {
                            //cout << "enter search " << endl;
                            store.push_back(1);
                            return store;
                        }
                    for (auto it = g[n].begin(); it != g[n].end(); ++it)
                    {
                        dfs(g, *it, search, visited, store);
                    }
                    
                }
            return store;
        }
        bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
            vector<int> res;
            map<string, vector<string>> graphstore; 
            if (words1.size() != words2.size())
                return 0;
            else
            {
                auto it1 = pairs.begin();
                vector<string> temp;

                // fill up the hashmap here
                while (it1 != pairs.end()) {
                    temp = *it1;
                    graphstore[temp[0]].push_back(temp[1]);
                    graphstore[temp[1]].push_back(temp[0]);
                    ++it1;
                }

                // Print out the graph
                /*
                for (auto it = graphstore.begin(); it != graphstore.end(); ++it)
                {
                    cout << "key  "<< it->first << endl;
                    vector<string>temp = it->second;
                    for (auto it = temp.begin(); it != temp.end(); ++it)
                    {
                        cout << *it << endl;
                    }
                    cout << " " << endl;
                }
                */
                
                // call dfs to search
                auto it2 = words1.begin();
                auto it3 = words2.begin();
                while (it2 != words1.end()) {
                    if (*it2 == *it3) 
                        res.push_back(1);
                    else
                    {   
                        vector<string> visit{};
                        vector<int> arr{};
                        vector<int> ret{};
                        ret = dfs(graphstore, *it2, *it3, visit, arr);
                        // cout << "returns = " << endl;
                        // printint(ret);
                        // cout << endl;
                        if (!ret.empty())
                            res.push_back(1);
                        else
                            res.push_back(0);
                    }
                    
                    ++it2;
                    ++it3;
                }
                // check res
                if (std::count(res.begin(), res.end(), 0))
                    return 0;
                else
                    return 1;
                
            }
            
        }
};

class UnionFind{
    public:
        UnionFind(int n) {
            parents = vector<int>(n);
            iota(parents.begin(), parents.end(), 0);
        }
        
        int find(int x) {
            while (x != parents[x])
            {
                parents[x] = parents[parents[x]];
                x = parents[x];
            }
            return x;
        }

        void union_(int x, int y)
        {
            if (find(x) != find(y))
                parents[find(x)] = find(y);
        }
    private:
        vector<int> parents;
};

class Solution3{
    // This Solution is for solving with Using the Union Find Algorithm
    public:
        bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
            if (words1.size() != words2.size())
                return false;
            map<string, int> mp;
            for (vector<string>& p : pairs)
            {
                if (mp.find(p[0]) == mp.end())
                    mp[p[0]] = mp.size();

                if (mp.find(p[1]) == mp.end())
                    mp[p[1]] = mp.size();
            }
            
            UnionFind uf(mp.size());
            for (vector<string>& p : pairs)
            {
                int x = mp[p[0]], y = mp[p[1]];
                uf.union_(x, y);
            }

            for (int i = 0; i < words1.size(); i++)
            {
                if (words1[i] != words2[i] && (mp.find(words1[i]) == mp.end() || mp.find(words2[i]) == mp.end() || uf.find(mp[words1[i]] != uf.find(mp[words2[i]])) ))
                    return false;
            }

            return true;
        }
};

int main()
{
    Solution3 obj;
    
    /*
    vector<string> words1 = {"this","summer","thomas","get","really","very","rich","and","have","any","actually","wonderful","and","good","truck","every","morning","he","drives","an","extraordinary","truck","around","the","nice","city","to","eat","some","extremely","extraordinary","food","as","his","meal","but","he","only","entertain","an","few","well","fruits","as","single","lunch","he","wants","to","eat","single","single","and","really","healthy","life"};
    vector<string> words2 = {"this","summer","thomas","get","very","extremely","rich","and","possess","the","actually","great","and","wonderful","vehicle","every","morning","he","drives","unique","extraordinary","automobile","around","unique","fine","city","to","drink","single","extremely","nice","meal","as","his","super","but","he","only","entertain","a","few","extraordinary","food","as","some","brunch","he","wants","to","take","any","some","and","really","healthy","life"};
    vector<vector<string>> pairs = {{"good","nice"},{"good","excellent"},{"good","well"},{"good","great"},{"fine","nice"},{"fine","excellent"},{"fine","well"},{"fine","great"},{"wonderful","nice"},{"wonderful","excellent"},{"wonderful","well"},{"wonderful","great"},{"extraordinary","nice"},{"extraordinary","excellent"},{"extraordinary","well"},{"extraordinary","great"},{"one","a"},{"one","an"},{"one","unique"},{"one","any"},{"single","a"},{"single","an"},{"single","unique"},{"single","any"},{"the","a"},{"the","an"},{"the","unique"},{"the","any"},{"some","a"},{"some","an"},{"some","unique"},{"some","any"},{"car","vehicle"},{"car","automobile"},{"car","truck"},{"auto","vehicle"},{"auto","automobile"},{"auto","truck"},{"wagon","vehicle"},{"wagon","automobile"},{"wagon","truck"},{"have","take"},{"have","drink"},{"eat","take"},{"eat","drink"},{"entertain","take"},{"entertain","drink"},{"meal","lunch"},{"meal","dinner"},{"meal","breakfast"},{"meal","fruits"},{"super","lunch"},{"super","dinner"},{"super","breakfast"},{"super","fruits"},{"food","lunch"},{"food","dinner"},{"food","breakfast"},{"food","fruits"},{"brunch","lunch"},{"brunch","dinner"},{"brunch","breakfast"},{"brunch","fruits"},{"own","have"},{"own","possess"},{"keep","have"},{"keep","possess"},{"very","super"},{"very","actually"},{"really","super"},{"really","actually"},{"extremely","super"},{"extremely","actually"}};
    */
    vector<string> words1 = {"great", "acting", "skills"};
    vector<string> words2 = {"great", "acting", "skills"};
    vector<vector<string>> pairs = {};

    cout << obj.areSentencesSimilar(words1, words2, pairs)<< endl;

    
}