#include "Parser_Engine.h"
#include "CFG_Reader.h"
#include "CFG.h"
#include "Rule.h"
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include "Left_Handling.h"

using namespace std;

Parser_Engine::Parser_Engine()
{
    //ctor
}

Parser_Engine::~Parser_Engine()
{
    //dtor
}

bool Parser_Engine::is_teminal(string s)
{
    string ss = this->trim(s);
    return (ss[0] == '\'' && ss[ss.size()-1] == '\'') ? true : false ;
}

string Parser_Engine::trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
void Parser_Engine:: split_and_push(string top)
{
    istringstream buf(top);
    istream_iterator<string> beg(buf), end;

    vector<string> splited(beg, end); // done!

    for(int i = splited.size() - 1 ; i >= 0 ; i--)
    {
        drive_stack.push(splited[i]);
    }
}


void Parser_Engine:: LL_Derivation(string start)
{
    drive_stack.push("$");
    drive_stack.push(start);
    int index = 0;

    while (drive_stack.top() != "$" && index < tokens.size())
    {
        string top = drive_stack.top();

        ///if terminal
        top = trim(top);
        if (is_teminal(top))
        {

            if (top.substr(1, top.size() - 2) == tokens[index])
            {
                index++;
            }
            else
            {
                /// error
                cout << "error111 : stack content = "  << top << "input symbo = " << tokens[index] << endl;
            }
            drive_stack.pop();
        }
        else
        {
            ///non terminal
            string x = tokens[index];
            string entry = CFG::parsing_table[top]['\''+x+'\''];           /// MAY ERROR
            if(entry.empty()) /// empty cell
            {
                ///ERORR
                cout << "error222 : stack content = "  << top << "input symbo = " << tokens[index] << endl;
                index++;
            }
            else if(entry == "\\L")
            {
                drive_stack.pop();
                this->output.push_back(top+"->"+entry);
            }
            else if (entry == "synch")               ///adding synch
            {
                ///Error
                cout << "error333 Synch : stack content = "  << top << "input symbo = " << tokens[index] << endl;
                drive_stack.pop();
            }
            else
            {
                drive_stack.pop();
                this->output.push_back(top+"->"+entry);
                this->split_and_push(entry);
            }
        }
    }
    if(drive_stack.size() == 1 && drive_stack.top() == "$")
    {
        while(index < tokens.size())
        {
            cout << "empty stack Discarded = " << tokens[index++] << endl;
        }
    }
    else if(index == tokens.size())
    {
        while(drive_stack.top() != "$")
        {
            string top = drive_stack.top();
            top = trim(top);
            if (is_teminal(top))
            {
                cout << "stack is not empty and terminal symbol 'Missing' = " << top << endl;
            }
            else if (CFG::CFG_map[top]->has_epson())  ///if this rule has @
            {
                cout << "Has EPS " << top << endl;
                this->output.push_back(top+"-> EPS");
            }
            else
            {
                cout << "stack is not empty and non terminal symbol 'Discarded' = " << top << endl;
            }
            drive_stack.pop();

        }
    }
}

/// print the output rule
void Parser_Engine:: print_output()
{
    cout << "output Rule = \n";
    for (int i = 0 ; i < output.size() ; i++)
    {
        cout << output[i] << endl;
    }
}


void Parser_Engine::run()
{

    ///read CFG file
    CFG_Reader * reader = new CFG_Reader();
    reader->run();
    vector<Rule* > rules = reader->getRules();


    /*
    for(map <string, Rule *> :: iterator it = CFG::CFG_map.begin(); it != CFG::CFG_map.end(); ++it)
    {
        //cout << (it -> second) -> get_rule() << endl;
        cout << "AAAAAAAAAAAAAAAA  " <<it -> first << endl;
        set<string> s = (it -> second) -> get_derived_strings();
        for (set<string>::iterator itr = s.begin(); itr != s.end(); itr++){
            cout << "BBBBBBBBBBB   "<<*itr << "--\n";
        }
        cout << "--------------------------------------------------------\n\n";
    }
    */


    //Left_Handling * lh = new Left_Handling();
    //vector<Rule* > rules = lh->leftRecursion(reader->getRules());

    ///build the parsign table
    CFG * cfg = new CFG();
    cfg->build_parsing_table(rules);

    ///start part 2
    this->fill_tokens();
    this ->LL_Derivation(reader->get_start());
    this -> print_output();

}

void Parser_Engine::fill_tokens()
{
    ifstream inputFile("output.txt");
    string input, s;
    bool flag = false;
    while(getline(inputFile, s))
    {
        this->tokens.push_back(s);
    }
}
