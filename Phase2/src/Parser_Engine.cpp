#include "Parser_Engine.h"
#include "CFG_Reader.h"
#include "CFG.h"


Parser_Engine::Parser_Engine()
{
    //ctor
}

Parser_Engine::~Parser_Engine()
{
    //dtor
}


void Parser_Engine::run(){

    ///read CFG file
    CFG_Reader * reader = new CFG_Reader();
    reader->run();

    ///build the parsign table
    CFG * cfg = new CFG();
    cfg->build_parsing_table();
    //map<pair<string,string> , string> table = cfg->get_parsing_table();


    ///start part 2

}
