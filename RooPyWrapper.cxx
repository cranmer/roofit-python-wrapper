/***************************************************************************** 
 * RooPyWrapper
 * author: Kyle Cranmer <kyle.cranmer@nyu.edu>
 * author: Lukas Heinrich
 *                                                                          * 
 * This is an example RooAbsReal that makes a call back to python code
 *****************************************************************************/ 

#include "Riostream.h" 

#include "RooPyWrapper.h" 
#include <math.h> 
#include <iostream>

#ifndef __CINT__
#include "Python.h"
#endif


ClassImp(RooPyWrapper) 

  RooPyWrapper::RooPyWrapper(const char *name, const char *title, 
                       RooArgList& _features,PyObject* pyobject ) :
  features(RooListProxy("features","features",this)),
  m_callback(pyobject),
  RooAbsReal(name,title)
 { 
    for(int i = 0; i<_features.getSize();++i){
      features.add(_features[i]);
    }
    Py_INCREF( pyobject );
 } 


 RooPyWrapper::RooPyWrapper(const RooPyWrapper& other, const char* name) :  
  RooAbsReal(other,name), 
  features(RooListProxy("features",this,other.features)),
  m_callback(other.m_callback) 
 {
 } 



 Double_t RooPyWrapper::evaluate() const 
 { 
   // ENTER EXPRESSION IN TERMS OF VARIABLE ARGUMENTS HERE 
   #ifndef __CINT__

  if(    m_callback==NULL) {
    std::cout << "no call back set" << std::endl;
    return 0;
  }

  auto f = features;


  PyObject *mylist = PyList_New(f.getSize());
  for(int i=0; i<f.getSize();++i){
    PyObject* arg = PyFloat_FromDouble(((RooRealVar&)f[i]).getVal());
    PyList_SetItem(mylist,i,arg);
  }  

  // callback with argument
  PyObject* result = PyObject_CallFunctionObjArgs( m_callback, mylist , NULL  );


  Py_DECREF(mylist);

  // convert result to double
  double ret;
  PyArg_Parse((result),"d", &ret);

  // other conversion approachs
  //   cout << "result as long " << PyInt_AsLong(result) << endl;
  //   cout << "result as double " << PyFloat_AsDouble(result) << endl; 


  Py_XDECREF( result );
   #endif
   return ret ; 
 } 



