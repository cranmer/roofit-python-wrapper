from ROOT import *
import ROOT
ROOT.RooStats
gSystem.Load( 'libRooFitPythonWrapper' )

def myFunction(x):
   #return x*x as an example
   return x*x*x 

x = RooRealVar('x','x',-1,1)
s = RooPyWrapper('s','s',x)
s.RegisterCallBack( myFunction );

c1 = TCanvas('c1')
frame = x.frame()
s.plotOn(frame)
frame.Draw()
c1.SaveAs('RooPyWrapper.png')
