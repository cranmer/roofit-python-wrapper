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

#ifndef __CINT__
#include "Python.h"
#endif


ClassImp(RooPyWrapper) 

  RooPyWrapper::RooPyWrapper(const char *name, const char *title, 
                       RooAbsReal& _features) :
  RooAbsReal(name,title), 
  features("features","features",this,_features)
 { 
 } 


 RooPyWrapper::RooPyWrapper(const RooPyWrapper& other, const char* name) :  
  RooAbsReal(other,name), 
  features("features",this,other.features) { 
 } 



 Double_t RooPyWrapper::evaluate() const 
 { 
   // ENTER EXPRESSION IN TERMS OF VARIABLE ARGUMENTS HERE 
   std::cout << "Hi from C++!" << std::endl;
   char* blah=NULL;
   #ifndef __CINT__
   PyObject* result = PyObject_CallFunction( m_callback, blah );
   cout << "result as long " << PyInt_AsLong(result) << endl;
   cout << "result as double " << PyFloat_AsDouble(result) << endl; 
   double ret;
   PyArg_Parse((result),"d", &ret);
   cout << "from parse " << ret << endl;

   Py_XDECREF( result );
   #endif
   return 1.0 ; 
 } 

void RooPyWrapper::RegisterCallBack( PyObject* pyobject )
{
	// see http://root.cern.ch/phpBB3/viewtopic.php?t=2606
	Py_INCREF( pyobject );
	m_callback = pyobject;
}


