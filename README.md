#This is the README for CMS winter school hand-on

#1.creat CMSSW,  copy the codes and files to your directory

```bash
source /cvmfs/cms.cern.ch/cmsset_default.sh
scram p -n winter_school_CMSSW_8_1_0 CMSSW CMSSW_8_1_0
cd winter_school_CMSSW_8_1_0/src
cmsenv
cp -r /publicfs/cms/user/yutz/CMS_winter_school  ./
cd CMS_winter_school
```
#2.run the Event selection script to produce the Ntuple files

```bash
root -b -q EventSelection_dineutrino_Resolved_2018.cpp
```

Run this script will produce four root files: ST\_t-channel\_antitop.root  ST\_t-channel\_top.root  ST\_tW\_antitop.root  ST\_tW\_top.root in your directory

#3.produce the MC distribution plots
```bash
root -b -q plotterPreselection_dineutrino_2018.cpp  
```
open the files like this: 
```bash
display TopMass.pdf
display TopPt.pdf
display TopEta.pdf
```
Then you can see the top mass,pt,eta distribution

