#pragma once
#include "Repo.h"

class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo):repo { repo }{};
    vector<Candidat>& get_all(){
        return repo.get_all();
    }
    void add(string name, string job, string status);
    void modificare(string name, string job, string status);
    vector<Candidat> filter(string name);
};
