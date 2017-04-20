#include "CFG.h"

CFG::CFG()
{
    //ctor
}

CFG::~CFG()
{
    //dtor
}



/**
    use the first and follow to build the parsing table
*/
void CFG::build_parsing_table(){

}


map<pair<string,string> , string> CFG::get_parsing_table(){

}


/**
    given rule A  loop for it's strings return set of strings
    of the first symbols for all strings in A
*/
set<string> CFG::first(Rule * A){

}


/**
    return set of the terminals which occur immediately after
    (follow) the non-terminal A in the strings derived
    from the starting symbol.
*/
set<string> CFG::follow(Rule * A){

}
