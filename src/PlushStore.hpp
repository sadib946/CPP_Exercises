#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <Plush.hpp>
#include <optional>
#include <algorithm>

class PlushStore{
    private:
        std::string name;
        int wealth_amount = 0;
        int stock_size = 0;
        int debt = 0;
        int experiences = 0;

        std::vector<Plush> plushes = {};

        void update_wealth_amount(int amount)
        {
            this->wealth_amount += amount;
        }

        void update_stock_size(int value)
        {
            this->stock_size += value;
        }

        void update_experiences(int value)
        {
            this->experiences += value;
        }
    
    public:
        PlushStore(const std::string& new_name)
            : name {new_name}
        {}

        std::string get_name() const
        {
            return name;
        }

        int get_wealth_amount() const
        {
            return wealth_amount;
        }

        int get_stock_size() const
        {
            return stock_size;
        }

        void loan(int value)
        {
            this->wealth_amount += value;
            this->debt = wealth_amount * 1.10; 
        }

        int get_debt_amount() const
        {
            return debt;
        }

        int make_plush(const int price)
        {   
            if(wealth_amount == 0)
            {
                return 0;
            }
            else if(wealth_amount >= price)
            {
                int final_value = price + std::max(experiences, experiences * price/100);
                update_wealth_amount(-price);
                update_experiences(1);
                update_stock_size(1);
                // return price;
                auto plush = Plush{final_value};
                plushes.push_back(plush);
                return final_value;
            }
            else{
                int final_value = wealth_amount + std::max(experiences, experiences * wealth_amount/100);
                // int value = wealth_amount;
                update_wealth_amount(-wealth_amount);
                update_experiences(1);
                update_stock_size(1);
                // return value;
                auto plush = Plush{final_value};
                plushes.push_back(plush);
                return final_value;
            }
        }

        int get_experience() const
        {
            return experiences;
        }

        Plush find_cheapest(){
            Plush cheapest = plushes[0];
            for(auto i = plushes.begin(); i != plushes.end(); ++i){
                if((*i).get_cost() < cheapest.get_cost()){
                    cheapest = *i;
                }
            }

            return cheapest;
        }

        std::optional<Plush> buy(int money)
        {
            Plush cheapest_plush = find_cheapest();

            if(cheapest_plush.get_cost() <= money){
                update_stock_size(-1);
                update_wealth_amount(cheapest_plush.get_cost());
                
                // delete plush from plushes
                for(auto it = plushes.begin(); it != plushes.end(); ++it){
                    if((*it).get_cost() == cheapest_plush.get_cost()){
                        plushes.erase(it);
                        break;
                    }
                }

                return cheapest_plush;
            }

            return std::nullopt;
        }
};