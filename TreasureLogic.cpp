#include <iostream>
#include <vector>
#include <string>

class TreasureLogic {
private:
    std::vector<std::string> treasureItems;
    int totalValue;

public:
    TreasureLogic() : totalValue(0) {}

    void addTreasure(const std::string& item, int value) {
        treasureItems.push_back(item);
        totalValue += value;
    }

    void removeTreasure(const std::string& item, int value) {
        for (auto it = treasureItems.begin(); it != treasureItems.end(); ++it) {
            if (*it == item) {
                treasureItems.erase(it);
                totalValue -= value;
                break;
            }
        }
    }

    int getTotalValue() const {
        return totalValue;
    }

    const std::vector<std::string>& getTreasureItems() const {
        return treasureItems;
    }
};