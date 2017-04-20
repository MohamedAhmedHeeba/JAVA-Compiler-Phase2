#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Rule
{
    public:
        Rule();
        virtual ~Rule();

        void set_name(string);
        string get_name();

        void set_rule(string);
        string get_rule();

        void add_to_derived_strings(string);
        set<string> get_derived_strings();

        void set_firsts(set<string>);
        set<string> get_firsts();

        void set_follows(set<string>);
        set<string> get_follows();

    protected:

    private:

        string name;
        string rule;
        set<string> derived_strings;
        set<string> firsts;
        set<string> follows;

};

#endif // RULE_H
