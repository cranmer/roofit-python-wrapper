from ROOT import *
import ROOT
ROOT.RooStats
gSystem.Load( 'libRooFitPythonWrapper' )

def myFunction(x):
   x,y = x
   #return x*x as an example
   return x+y*y

x = RooRealVar('x','x',-1,1)
y = RooRealVar('y','y',-1,1)

lst = RooArgList('list')
lst.add(x)
lst.add(y)

s = RooPyWrapper('s','s',lst)
s.RegisterCallBack( myFunction );

c1 = TCanvas('c1')
frame = x.frame()
s.plotOn(frame)
frame.Draw()
c1.SaveAs('RooPyWrapper_x.png')

c1 = TCanvas('c1')
frame = y.frame()
s.plotOn(frame)
frame.Draw()
c1.SaveAs('RooPyWrapper_y.png')
