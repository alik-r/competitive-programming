class Solution1 {
public:
    bool dfs(const vector<vector<string>>& ingredients, unordered_map<string, bool>& available, unordered_map<string, int>& recipeIdx, string recipe) {
        if (available.count(recipe) > 0) 
            return available[recipe];

        if (recipeIdx.count(recipe) < 1) 
            return false;

        available[recipe] = false;
        for (string ingr : ingredients[recipeIdx[recipe]]) {
            if (!dfs(ingredients, available, recipeIdx, ingr)) return false;
        }

        available[recipe] = true;
        return available[recipe];
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> available;
        for (string s : supplies) available[s] = true;

        unordered_map<string, int> recipeIdx;
        for (int i = 0; i < recipes.size(); i++) recipeIdx[recipes[i]] = i;

        vector<string> ans;
        for (string r : recipes) {
            if (dfs(ingredients, available, recipeIdx, r)) {
                ans.push_back(r);
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> available;
        for (string s : supplies) available[s] = true;

        vector<string> ans;
        bool created = true;
        while (created) {
            created = false;
            for (int i = 0; i < recipes.size(); i++) {
                if (available.count(recipes[i]) > 0) continue;

                bool possible = true;
                for (int j = 0; j < ingredients[i].size(); j++) {
                    if (available.count(ingredients[i][j]) < 1) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    available[recipes[i]] = true;
                    ans.push_back(recipes[i]);
                    created = true;
                }
            }
            if (!created) break;
        }
        return ans;
    }
};
