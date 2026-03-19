#pragma once
#include <iostream>
#include <string>
#include <map>

class StockManager {
public:
    static const int MAX_STOCK = 3;

    void InitializeStock(const std::string& potionName, int initialStock = MAX_STOCK);
    int getStock(const std::string& potionName) const;
    bool DispensePotion(const std::string& potionName);
    void ReturnPotion(const std::string& potionName);

private:
    std::map<std::string, int> potionStock_;
};