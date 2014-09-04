roofit-python-wrapper
=====================

author: Kyle Cranmer <kyle.cranmer@nyu.edu>
author: Lukas Heinrich

A clean example of a RooAbsReal from ROOT's RooFit statistical modeling language making a call back to some python code.

*Build*
Requires ROOT installed with --enable-roofit --enable-python
your environment should be set with `source $ROOTSYS/bin/thisroot.sh`
At that point make should work (it is using ROOT's generic Makefile)

*Test*
```
from ROOT import *
gSystem.Load( 'libRooFitPythonWrapper' )

def SayHi():
   print 'Hi from python!'
   return 3.

x = RooRealVar('x','x',0,1)
s = RooPyWrapper('s','s',x)
s.RegisterCallBack( SayHi );
print "\ngetVal"
s.getVal()
```
this returns 3. as expected

