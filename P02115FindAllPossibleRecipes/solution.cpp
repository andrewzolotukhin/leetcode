class Solution {
private:
  bool canConstruct(string &recipe, set<string> &supplies, set<string> &recipes,
                    map<string, vector<string>> &ingredients, set<string> &top,
                    map<string, bool> &memo) {
    if (memo.count(recipe))
      return memo[recipe];
    if (!ingredients.count(recipe)) {
      memo[recipe] = false;
      return false;
    }

    auto ingredientsArray = ingredients[recipe];

    for (auto ingredient : ingredientsArray) {
      if (recipes.count(ingredient) > 0) {
        // recipe
        if (ingredient == recipe || top.count(ingredient)) {
          memo[recipe] = false;
          return false;
        }
        top.insert(ingredient);
        if (!canConstruct(ingredient, supplies, recipes, ingredients, top,
                          memo)) {
          top.erase(ingredient);
          memo[recipe] = false;
          return false;
        }
        top.erase(ingredient);

      } else {
        if (!supplies.count(ingredient)) {
          memo[recipe] = false;
          return false;
        }
      }
    }

    memo[recipe] = true;
    return true;
  }

public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    vector<string> ans;

    map<string, vector<string>> recipeIngredients;
    set<string> supp;
    set<string> rec;
    set<string> top;
    map<string, bool> memo;

    for (auto r : recipes) {
      rec.insert(r);
    }

    for (int i = 0; i < recipes.size(); i++) {
      for (int j = 0; j < ingredients[i].size(); j++) {
        recipeIngredients[recipes[i]].push_back(ingredients[i][j]);
      }
    }

    for (auto s : supplies) {
      supp.insert(s);
    }

    for (auto recipe : recipes) {
      if (canConstruct(recipe, supp, rec, recipeIngredients, top, memo)) {
        ans.push_back(recipe);
      }
    }

    return ans;
  }
};
