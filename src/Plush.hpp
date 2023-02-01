#pragma once

class Plush{
    private:
        int cost = 10;
    
    public:
        Plush(const int cost)
            : cost {cost}
        {}

        Plush()
        {}

        int get_cost() const{
            return cost;
        }

        void set_cost(int value){
            this->cost = value;
        }
};