#include "Rule.h"

Rule::Rule()
{
    //ctor
}

Rule::~Rule()
{
    //dtor
}


void Rule::set_name(string name){
    this->name = name;
}

string Rule::get_name(){
    return this->name;
}

void Rule::set_rule(string rule){
    this->rule = rule;
}

string Rule::get_rule(){
    return this->rule;
}

void Rule::add_to_derived_strings(string derived){
    this->derived_strings.insert(derived);
}

set<string> Rule::get_derived_strings(){
    return this->derived_strings;
}

void Rule::set_firsts(set<string> firsts){
    this->firsts = firsts;
}

set<string> Rule::get_firsts(){
    return this->firsts;
}

void Rule::set_follows(set<string> follows){
    this->follows = follows;
}
set<string> Rule::get_follows(){
    return this->follows;
}
