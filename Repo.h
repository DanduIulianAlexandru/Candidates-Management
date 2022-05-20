#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include "Candidat.h"
using std::vector;
using std::string;
class Repo {
private:
    vector<Candidat> all;
    string path;
public:
    Repo(string path):path{ path }{ readFromFile();};
    vector<Candidat>& get_all();
    void readFromFile();
    void saveInFile();
    void add(Candidat& candidat);
};