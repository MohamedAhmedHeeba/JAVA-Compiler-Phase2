#ifndef CFG_H
#define CFG_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include "Rule.h"
#include <iostream>
#include <string>

using namespace std;

class CFG
{
    public:
        CFG();
        virtual ~CFG();

        ///CFG representation
        static map< string , Rule * > CFG_map;

        void build_parsing_table();

        map<string , map<string,string> > get_parsing_table();

    protected:

    private:

        ///first
        set<string> first(Rule *);
        ///follow
        set<string> follow(Rule *);

        ///parsign table representation  ///MAY CAUSE ERROR --> suggest new representation
        static map<string , map<string,string> > parsing_table;

        bool is_teminal(string);

        string trim(const string&);


};

#endif // CFG_H
