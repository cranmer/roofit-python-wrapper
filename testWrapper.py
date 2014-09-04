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