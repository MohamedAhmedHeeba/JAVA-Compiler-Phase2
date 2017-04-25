#include "CFG.h"

CFG::CFG()
{
    //ctor
}

CFG::~CFG()
{
    //dtor
}


map< string , Rule * > CFG::CFG_map;
map<string , map<string,string> > CFG::parsing_table;

/**
    use the first and follow to build the parsing table
*/
void CFG::build_parsing_table(){
    /// call the fisrt and follow that fill Rules set firsts and follows
    ///for each Rule R is CFG_map{
        ///for each string S in derived_strings{
            ///for each string SYM in set R.firsts[S]{
                ///if(SYM is trminal){ M[R.name][SYM] = "R.name --> S"};
                ///else if(SYM is @ ){
                    ///for each string SYM2 in set R.follows[S]{
                        ///M[R.name][SYM2]="R.name --> S";
                    ///}
                ///}
            ///}
        ///}
    ///}

    /// call the fisrt and follow that fill Rules set firsts and follows
    for(auto const &ent : CFG::CFG_map){
        string name = ent.first;
        Rule * R = ent.second;

        std::set<string>::iterator it;
        for (it = R->get_derived_strings().begin(); it != R->get_derived_strings().end(); ++it){
            string S = *it;
            set<string> first = R->get_firsts()[S];
            std::set<string>::iterator itt;
            for (itt = first.begin(); itt != first.end(); ++itt){
                string SYM = *itt;
                if(this->is_teminal(SYM)){
                    if(this->parsing_table[name][SYM].empty()){
                        this->parsing_table[name][SYM] = S;
                    }else{
                        ///ERROR NOT LL(1)
                    }
                }else if(this->trim(SYM) == "@"){
                    R->set_has_epson(true);
                    set<string> follows = R->get_follows()[S];
                    std::set<string>::iterator ittt;
                    for (ittt = first.begin(); ittt != first.end(); ++ittt){
                        string SYM2 = *ittt;
                        if(this->parsing_table[name][SYM2].empty()){
                            this->parsing_table[name][SYM2] = S;
                        }else{
                            ///ERROR NOT LL(1)
                        }
                    }
                }
            }
            if(!R->has_epson()){
                set<string> follows = R->get_follows()[S];
                std::set<string>::iterator ittt;
                for (ittt = follows.begin(); ittt != follows.end(); ++ittt){
                    string SYM2 = *ittt;
                    if(this->parsing_table[name][SYM2].empty()){
                        this->parsing_table[name][SYM2] = "synch";
                    }else{
                        ///ERROR NOT LL(1)
                    }
                }
            }
        }
    }

}

bool CFG::is_teminal(string s){
    string ss = this->trim(s);
    return (ss[0] == '\'' && ss[ss.size()-1] == '\'') ? true : false ;
}

string CFG::trim(const string& str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

map<string , map<string,string> > CFG::get_parsing_table(){

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
