#pragma once
#include <string>
#include <utility>

using std::string;

class Candidat {
private:
    string name;
    string job;
    string status;
public:
    Candidat(string name, string job, string status) : name {std::move( name )}, job{std::move( job )}, status { status }{};
    Candidat() = default;
    string get_name() const{ return name;}
    string get_job() const{return job;}
    string get_status() const{return status;}
    void set_job(string a) {
        this->job = a;
    }
    void set_status(string a) {
        this->status = a;
    }
};
