#include "Repo.h"
#include <sstream>
#include <fstream>

vector<Candidat> &Repo::get_all() {
    return all;
}

void Repo::readFromFile() {
    all.clear();
    std::ifstream fin(path);
    string line;
    while(fin >> line){
        std::stringstream stringstream(line);
        string part;
        vector<string> parts;
        while(std::getline(stringstream, part, ',')){
            parts.push_back(part);
        }
        string name = parts[0];
        string job = parts[1];
        string status = parts[2];
        Candidat cand {name, job, status};
        all.push_back(cand);
    }
    fin.close();
}


void Repo::saveInFile() {
    std::ofstream aff(path);
    for(auto& c : all){
        aff<<c.get_name()<<","<<c.get_job()<<","<<c.get_status()<<",\n";
    }
    aff.close();
}

void Repo::add(Candidat &cand) {
    all.push_back(cand);
    saveInFile();
}
