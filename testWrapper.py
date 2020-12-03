import ROOT
import numpy as np
import time
ROOT.RooStats
ROOT.gSystem.Load( 'libRooFitPythonWrapper' )
from ROOT import RooRealVar,RooArgList,TCanvas

def myFunction(pars):
   x,y,z = pars
   result = x**2 + y**3 + z
   return result

params = RooArgList('list')
pars = {}
for i,(init,bounds) in enumerate([
   (0,(-1,1)),
   (0,(-1,1)),
   (0,(-1,1)),
]):
   name = 'par{i}'.format(i = i)
   pars[name] = RooRealVar(name,name,init,bounds[0],bounds[1])
   params.add(pars[name])

s = ROOT.RooPyWrapper('s','s',params,myFunction)

for k,v in pars.items():
   c1 = TCanvas('c1')
   frame = v.frame()
   s.plotOn(frame)
   frame.Draw()
   c1.SaveAs('RooPyWrapper_{k}.png'.format(k = k))

