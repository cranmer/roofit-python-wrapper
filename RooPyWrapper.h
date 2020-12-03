/***************************************************************************** 
 * RooPyWrapper
 * author: Kyle Cranmer <kyle.cranmer@nyu.edu>
 * author: Lukas Heinrich
 *                                                                          * 
 * This is an example RooAbsReal that makes a call back to python code
 *****************************************************************************/ 

#ifndef ROOPYWRAPPER
#define ROOPYWRAPPER

#include "RooAbsReal.h"
#include "RooRealProxy.h"
#include "RooListProxy.h"
#include "RooCategoryProxy.h"
#include "RooRealVar.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

#include "Python.h"

#ifndef PyObject_HEAD
struct _object;
typedef _object PyObject;
#endif


class RooPyWrapper : public RooAbsReal{
public:
  RooPyWrapper() {} ; 
  RooPyWrapper(const char *name, const char *title, RooArgList& _features, PyObject* pyobject );
  RooPyWrapper(const RooPyWrapper& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooPyWrapper(*this,newname); }
  inline virtual ~RooPyWrapper() { }


protected:

  virtual Double_t evaluate() const ;

private:
  RooListProxy features;
  PyObject* m_callback;
  ClassDef(RooPyWrapper,1); // Your description goes here...
};
 
#endif
