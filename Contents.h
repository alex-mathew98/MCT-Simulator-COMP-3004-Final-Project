/*
 * File name: Contents.h
 * Description: The header file for the 'Contents' class
 *
*/
#ifndef CONTENTS_H
#define CONTENTS_H

#include "MAIN_MP.h"
#include "Function.h"

/*
 * Declaration of the 'Contents' class
*/
class Contents : public Main_MP {

  public:
      explicit Contents(QObject* parent = nullptr, QString title = "{Contents}", Function* Function = nullptr, Main_MP* prevMain_MP = nullptr, vector<Main_MP*> *options = nullptr);
      ~Contents();
      //Function to get the chosen program
      Function* Get_Prog();
      //Functions to process the button actions
      void Back_Button();
      void Ok_Button();
      void Left_Button();
      void Right_Button();

  private:
      //Pointer object to Function
      Function* function;

};

#endif
