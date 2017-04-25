#ifndef CFG_READER_H
#define CFG_READER_H

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class CFG_Reader
{
    public:
        CFG_Reader();
        virtual ~CFG_Reader();

        void run();
        void parseFile();
        void buildRule(string &line);
        string get_start();

    protected:

    private:
    string start = "";
};

#endif // CFG_READER_H
