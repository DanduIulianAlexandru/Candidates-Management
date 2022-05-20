#include "Gui.h"
#include <iostream>
#include <sstream>
#include <fstream>
void Gui::init(){
    setLayout(mainL);
    mainL->addWidget(candList);

    mainL->addWidget(formDreapta);

    formDreapta->setLayout(formDreaptaLayout);
    formDreaptaLayout->addWidget(new QLabel{"Nume Candidat: "});
    formDreaptaLayout->addWidget(name);
    formDreaptaLayout->addWidget(new QLabel{"Job Candidat: "});
    formDreaptaLayout->addWidget(job);
    formDreaptaLayout->addWidget(new QLabel{"Status Candidat: "});
    formDreaptaLayout->addWidget(status);
    formDreaptaLayout->addWidget(addBtn);
    formDreaptaLayout->addWidget(updateBtn);
    formDreaptaLayout->addWidget(filterBtn);
}

void Gui::conec(){
    QObject::connect(addBtn, &QPushButton::clicked, [&](){
        if(name->text().isEmpty()||job->text().isEmpty()||status->text().isEmpty()) return;
        string namestr = name->text().toStdString();
        string jobstr = job->text().toStdString();
        string statusstr = status->text().toStdString();
        srv.add(namestr, jobstr, statusstr);
        reloadCandidati(srv.get_all());
    });
    QObject::connect(updateBtn,
                     &QPushButton::clicked,
                     [&](){
                             srv.modificare(name->text().toStdString(),
                                                job->text().toStdString(),
                                                status->text().toStdString()
                             );
                             reloadCandidati(srv.get_all());
                         });
    QObject::connect(candList, &QListWidget::itemSelectionChanged, [&](){
        auto sel = candList->selectedItems();
        if(sel.isEmpty()){
            name->setText("");
            job->setText("");
            status->setText("");
        }else{
            auto selItem = sel.at(0);
            string all = selItem->text().toStdString();
            std::stringstream stringstream(all);
            vector<string> parts;
            while(std::getline(stringstream, all, '-')){
                parts.push_back(all);
            }
            string name1 = parts[0];
            string job1 = parts[1];
            string status1 = parts[2];
            name->setText(QString::fromStdString(name1));
            job->setText(QString::fromStdString(job1));
            status->setText(QString::fromStdString(status1));
        }
    });
    QObject:
    connect(filterBtn, &QPushButton::clicked, [&](){
        if(name->text().isEmpty()) return;
        string nume = name->text().toStdString();
        reloadCandidati(srv.filter(nume));
    });

};

void Gui::reloadCandidati(vector<Candidat> lst) {
    candList->clear();
    for(auto& cand : lst){
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(cand.get_name() + "-" + cand.get_job() + "-" + cand.get_status()));
        item->setData(Qt::UserRole, QString::fromStdString(cand.get_name()));
        if(cand.get_status()== "hired")
            item->setBackground(Qt::green);
        if (cand.get_status() == "pending") {
            item->setBackground(Qt::yellow);
        }
        if (cand.get_status() == "rejected") {
            item->setBackground(Qt::red);
        }candList->addItem(item);
    }
}