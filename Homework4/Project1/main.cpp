#include<iostream>
#include <string>
#include <vector>
#include <map>

#include "PotionRecipie.h"
#include "RecipeManager.h"
#include "StockManager.h"

void main()
{
    StockManager Stock;
	RecipeManager Recipe(Stock);
    

    Recipe.AddRecipe("Healing Potion", { "Herb", "Water" });
    Recipe.AddRecipe("Mana Potion", { "Magic Water", "Crystal" });
    Recipe.AddRecipe("Stamina Potion", { "Herb", "Berry" });
    Recipe.AddRecipe("Fire Resistance Potion", { "Fire Flower", "Ash" });

    std::cout << "=== 초기 상태 (레시피 추가 + 재고 자동 3개) ===\n";
    Recipe.GetAllRecipes();

    std::cout << "\n[재고 확인] Healing Potion 재고: "
        << Stock.getStock("Healing Potion") << "\n";

    std::cout << "\n=== 이름으로 지급 테스트 (Healing Potion 3회 지급) ===\n";
    std::cout << "1회 지급: " << (Stock.DispensePotion("Healing Potion") ? "성공" : "실패") << "\n";
    std::cout << "2회 지급: " << (Stock.DispensePotion("Healing Potion") ? "성공" : "실패") << "\n";
    std::cout << "3회 지급: " << (Stock.DispensePotion("Healing Potion") ? "성공" : "실패") << "\n";

    std::cout << "현재 재고: " << Stock.getStock("Healing Potion") << "\n";

    std::cout << "4회 지급(재고 없으면 실패): "
        << (Stock.DispensePotion("Healing Potion") ? "성공" : "실패") << "\n";

    std::cout << "\n=== 공병 반환 테스트 (Healing Potion) ===\n";
    Stock.ReturnPotion("Healing Potion");
    Stock.ReturnPotion("Healing Potion");
    Stock.ReturnPotion("Healing Potion"); // 이미 3이면 더 올라가면 안 됨

    std::cout << "반환 후 재고(최대 3 유지): "
        << Stock.getStock("Healing Potion") << "\n";

    std::cout << "\n=== 최종 상태 ===\n";
    Recipe.GetAllRecipes();
}