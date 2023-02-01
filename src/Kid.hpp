#pragma once
#include <string>
#include <iostream>
#include <PlushStore.hpp>

class Kid{
    private:
        std::string name;
        int pocket_money;


    public:
        Kid(const std::string new_name, const int new_pocket_money)
            :   name {new_name},
                pocket_money {new_pocket_money}
        {
            // name = new_name;
            // pocket_money = new_pocket_money;
        }

        friend std::ostream& operator<<(std::ostream& stream, const Kid& kid);

        std::string get_name() const
        {
            return name;
        }

        int get_money() const
        {
            return pocket_money;
        }

        void buy_plush(PlushStore& plush_store){
            const auto plush = plush_store.buy(pocket_money);

            if(plush != std::nullopt){
                this->pocket_money -= (*plush).get_cost();
            }
        }


};

std::ostream& operator<<(std::ostream& stream, const Kid& kid){
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}