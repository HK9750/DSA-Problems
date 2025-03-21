// Leetcode 2115. Find All Possible Recipes From Given Supplies

// Brute Force Approach

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &rec,
                                  vector<vector<string>> &ing,
                                  vector<string> &sup)
    {
        set<string> s(sup.begin(), sup.end());
        vector<string> ans;
        bool updated = true;

        while (updated)
        {
            updated = false;
            for (int i = 0; i < rec.size(); i++)
            {
                if (s.count(rec[i]))
                    continue;

                bool canMake = true;
                for (const string &ingredient : ing[i])
                {
                    if (!s.count(ingredient))
                    {
                        canMake = false;
                        break;
                    }
                }

                if (canMake)
                {
                    ans.push_back(rec[i]);
                    s.insert(rec[i]);
                    updated = true;
                }
            }
        }

        return ans;
    }
};

// Explaination:

// We will keep a set of all the supplies that we have. We will keep iterating over the recipes and check if we can make the recipe or not.
// If we can make the recipe, we will add it to the answer and add the recipe to the set of supplies that we have.
// We will keep iterating over the recipes until we can't make any more recipes.

// Using Topological Sort (Kahn's Algorithm)

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_set<string> available_supplies(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> ingredient_to_recipes;
        unordered_map<string, int> in_degree;
        unordered_map<string, vector<string>> recipe_to_ingredients;

        for (int i = 0; i < recipes.size(); i++)
        {
            string recipe = recipes[i];
            recipe_to_ingredients[recipe] = ingredients[i];
            in_degree[recipe] = ingredients[i].size();

            for (const string &ingredient : ingredients[i])
            {
                ingredient_to_recipes[ingredient].push_back(recipe);
            }
        }

        queue<string> q;
        for (const string &supply : supplies)
        {
            q.push(supply);
        }

        vector<string> result;

        while (!q.empty())
        {
            string current = q.front();
            q.pop();

            if (recipe_to_ingredients.find(current) != recipe_to_ingredients.end())
            {
                result.push_back(current);
            }

            if (ingredient_to_recipes.find(current) != ingredient_to_recipes.end())
            {
                for (const string &dependent_recipe : ingredient_to_recipes[current])
                {
                    in_degree[dependent_recipe]--;
                    if (in_degree[dependent_recipe] == 0)
                    {
                        q.push(dependent_recipe);
                    }
                }
            }
        }

        return result;
    }
};

// Explaination:
// We will keep a set of all the supplies that we have. We will keep a map of ingredients to recipes and a map of recipes to ingredients.
// We will keep a map of in-degree of each recipe. We will keep a queue of recipes that we can make.
// We will iterate over the recipes and add the recipe to the queue if we can make it.
// We will keep iterating over the queue until it is empty and keep adding the recipes to the answer.
// We will decrement the in-degree of the dependent recipes and add them to the queue if the in-degree becomes 0.
// We will return the answer.
// Time Complexity: O(N + M) where N is the number of recipes and M is the number of ingredients.
// Space Complexity: O(N + M) where N is the number of recipes and M is the number of ingredients.