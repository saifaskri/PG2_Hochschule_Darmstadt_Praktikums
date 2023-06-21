#include "dishdecorator.h"

std::map<std::string, float> Side::namePriceBag = {
    {"Bratkartoffeln", 1.0f},
    {"Nudeln",         0.9f},
    {"Pommes Frites",  1.0f},
    {"Reis",           0.8f},
    {"Salat",          1.7f},
    {"Blumenkohl",     0.8f},
    {"Bohnen",         1.1f},
    {"Erbsen",         0.6f},
    {"Karotten",       0.7f},
    {"Rotkohl",        0.9f},
    {"Wirsing",        0.8f}
};

std::map<std::string, float> Drink::namePriceBag = {
    {"Apfelsaftschorle", 1.9f},
    {"Bier",             2.5f},
    {"Cola",             1.8f},
    {"Limonade",         1.8f},
    {"Mineralwasser",    1.7f},
    {"Stilles Wasser",   1.7f},
    {"Wein",             3.0f}
};
