#ifndef CONTENTS_H
#define CONTENTS_H

#include "MAIN_MP.h"
#include "Function.h"

class Contents : public Main_MP {
public:
    explicit Contents(QObject* parent = nullptr, QString title = "{Contents}", Function* Function = nullptr, Main_MP* prevMain_MP = nullptr, vector<Main_MP*> *options = nullptr);
    ~Contents();
    Function* Get_Prog();

    void Back_Button();
    void Ok_Button();
    void Left_Button();
    void Right_Button();
private:
    Function* function;

};

#endif // Contents_H
