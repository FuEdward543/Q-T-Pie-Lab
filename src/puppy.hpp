#include "cutie.hpp"

class Puppy : public Cutie {
public:
    Puppy(string description, int rating) : Cutie(description, rating) {}

    string get_description() override {
        return description;
    }

    int get_cuteness_rating() override {
        return cuteness_rating;
    }
};
