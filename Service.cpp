#include "Service.h"
using std::vector;

void Service::add(string name, string job, string status) {
    Candidat cand {name, job, status};
    repo.add(cand);
}

void Service::modificare(string name, string job, string status) {
    vector<Candidat>& c = repo.get_all();
    for(auto& candidat : c){
        if(candidat.get_name() == name){
            candidat.set_job(job);
            candidat.set_status(status);
        }
    }
}

vector<Candidat> Service::filter(string name) {
    vector<Candidat> res;
    for(auto c : repo.get_all()){
        if(c.get_name() == name) res.push_back(c);
    }
    return res;
}
