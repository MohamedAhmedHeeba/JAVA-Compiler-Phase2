#ifndef CFG_H
#define CFG_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include "Rule.h"

using namespace std;

class CFG
{
    public:
        CFG();
        virtual ~CFG();

        ///CFG representation
        static map< string , Rule * > CFG_map;

        void build_parsing_table();

        map<pair<string,string> , string> get_parsing_table();

    protected:

    private:

        ///first
        set<string> first(Rule *);
        ///follow
        set<string> follow(Rule *);

        ///parsign table representation  ///MAY CAUSE ERROR --> suggest new representation
        map<pair<string,string> , string> parsing_table;

};

#endif // CFG_H
