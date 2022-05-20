#include <QtWidgets>
#include "Service.h"

class Gui:public QWidget{
private:
    Service& srv;
    void init();
    void conec();
    void reloadCandidati(vector<Candidat> lst);

    QListWidget* candList = new QListWidget;
    QHBoxLayout* mainL = new QHBoxLayout;

    QWidget* formDreapta = new QWidget;
    QVBoxLayout* formDreaptaLayout = new QVBoxLayout;

    QLineEdit* name = new QLineEdit;
    QLineEdit* job = new QLineEdit;
    QLineEdit* status = new QLineEdit;

    QPushButton* addBtn = new QPushButton("adauga candidat");
    QPushButton* updateBtn = new QPushButton("update");
    QPushButton* filterBtn = new QPushButton("filter");
public:
    Gui(Service& srv) : srv{ srv }{
        init();
        conec();
        reloadCandidati(srv.get_all());
    };
};