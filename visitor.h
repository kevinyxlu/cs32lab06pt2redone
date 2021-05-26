#ifndef VISITOR_H
#define VISITOR_H

//#include "psData.h"
//#include "psCombo.h"
//#include "demogData.h"
#include <memory>

/* a visitor can visit any of my specific data types */
class Visitor {
public:
  //virtual void visit(std::shared_ptr<class psCombo>e) = 0;
  virtual void visit(std::shared_ptr<class demogData>e) = 0;
  virtual void visit(std::shared_ptr<class psData>e) = 0;
};
#endif

