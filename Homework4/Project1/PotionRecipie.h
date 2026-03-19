#pragma once
#include <string>
#include <vector>

class PotionRecipie
{
public:
	PotionRecipie(const std::string& name, const std::vector<std::string>& ingredients);
	const std::string& getName() const;
	const std::vector<std::string>& getIngredients() const;
private:
	std::string name_;
	std::vector<std::string> ingredients_;
};

