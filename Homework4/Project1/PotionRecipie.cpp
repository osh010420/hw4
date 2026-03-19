#include <string>
#include <vector>
#include "PotionRecipie.h"

PotionRecipie::PotionRecipie(const std::string& name, const std::vector<std::string>& ingredients){
	PotionRecipie::name_ = name;
	PotionRecipie::ingredients_ = ingredients;
}

const std::string& PotionRecipie::getName() const
{
	return name_;
}

const std::vector<std::string>& PotionRecipie::getIngredients() const
{
	return ingredients_;
}
