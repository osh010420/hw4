#pragma once
#include<string>
#include<vector>
#include "PotionRecipie.h"
#include "StockManager.h"

class RecipeManager {
public:
    RecipeManager(StockManager& stockManager) : stockManager_(stockManager) {}

    void AddRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    void FindRecipeByName(const std::string& name);
    void FindRecipesByIngredient(const std::string& ingredient) const;
    const std::vector<PotionRecipie>& GetAllRecipes() const;

private:
    std::vector<PotionRecipie> recipes_;
    StockManager& stockManager_;
};

