#include "StockManager.h"



void StockManager::InitializeStock(const std::string& potionName, int initialStock)
{
    if (potionStock_.find(potionName) == potionStock_.end())
    {
        potionStock_[potionName] = initialStock;
        std::cout << ">> '" << potionName << "' 재고가 " << initialStock << "개로 초기화되었습니다." << std::endl;
    }
    else
    {
        std::cout << ">> '" << potionName << "' 재고는 이미 초기화되어 있습니다." << std::endl;
    }
}
void StockManager::ReturnPotion(const std::string& potionName)
{
    auto it = potionStock_.find(potionName);
    if (it != potionStock_.end() && potionStock_[potionName] < MAX_STOCK)
    {
        potionStock_[potionName]++;
        std::cout << ">> '" << potionName << "' 재고가 반환되어 현재 재고: " << potionStock_[potionName] << std::endl;
    }
    else
    {
        std::cout << ">> '" << potionName << "' 재고가 이미 최대치입니다." << std::endl;
	}
}
bool StockManager::DispensePotion(const std::string& potionName)
{
    auto it = potionStock_.find(potionName);
    if (it != potionStock_.end() && potionStock_[potionName] > 0)
    {
        potionStock_[potionName]--;
        std::cout << ">> '" << potionName << "'이(가) 지급되었습니다. 현재 재고: " << potionStock_[potionName] << std::endl;
        return true;
    }
    else
    {
        std::cout << ">> '" << potionName << "' 재고가 부족하여 지급에 실패했습니다." << std::endl;
        return false;
    }
}

int StockManager::getStock(const std::string& potionName) const
{
    const auto it = potionStock_.find(potionName);
    if (it == potionStock_.end())
    {
        return 0;
    }

    return it->second;
}