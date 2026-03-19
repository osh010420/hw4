#include <string>
#include <vector>
#include <iostream>

#include "PotionRecipie.h"
#include "RecipeManager.h"

void RecipeManager::AddRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    recipes_.emplace_back(name, ingredients);
    stockManager_.InitializeStock(name, 3);
    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

void RecipeManager::FindRecipeByName(const std::string& name)
{
    bool found = false;
    for (const auto& recipe : recipes_)
    {
        if (recipe.getName() == name)
        {
            found = true;
            std::cout << ">> 레시피 '" << name << "'이(가) 발견되었습니다." << std::endl;
            std::cout << " 재료: ";
            for (const auto& ingredient : recipe.getIngredients())
            {
                std::cout << ingredient << " ";
            }
        }
    }
    if (!found)
    {
        std::cout << ">> 레시피 '" << name << "'이(가) 발견되지 않았습니다." << std::endl;
    }
}

void RecipeManager::FindRecipesByIngredient(const std::string& ingredient) const {
    bool found = false;
    for (const auto& recipes : recipes_) {
        for (const auto& in : recipes.getIngredients()) {
            if (in == ingredient) {
                found = true;
                std::cout << ">> 재료 '" << ingredient << "'이(가) 포함된 레시피: " <<
                    recipes.getName() << std::endl;
            }
        }
    }
    if (!found) {
        std::cout << ">>재료 '" << ingredient << "'이(가) 포함된 레시피가 없습니다." << std::endl;
    }
}

const std::vector<PotionRecipie>& RecipeManager::GetAllRecipes() const
{
    std::cout << ">> 모든 레시피 목록:" << std::endl;
    for (const auto& recipe : recipes_)
    {
        std::cout << recipe.getName() << ": ";
        for (const auto& ingredient : recipe.getIngredients())
        {
            std::cout << ingredient << " ";
        }
        std::cout << std::endl;
    }
    return recipes_;
}