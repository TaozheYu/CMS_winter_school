This is the README for CMS winter school hand-on
## 1.Set the environment
Before to do the hand-on, we should first set the environment
```bash
source /cvmfs/cms.cern.ch/cmsset_default.sh
SCRAM_ARCH=slc7_amd64_gcc700
export PATH=/cvmfs/container.ihep.ac.cn/bin:$PATH
hep_container shell CentOS7
```

## 2.Creat CMSSW 
Then we can setup the CMS software, our script will run in it
```bash
cd ~
scram p -n winter_school_CMSSW_8_1_0 CMSSW CMSSW_8_1_0
cd winter_school_CMSSW_8_1_0/src
cmsenv
```
## 3.Copy the hand-on documents
You can use git to copy our hand-on documents

```bash
git clone git@github.com:TaozheYu/CMS_winter_school.git 
```
If you can't use git, copy them from here:

```bash
cp -r /publicfs/cms/user/yutz/CMS_winter_school  ./
``` 

## 4.Produce the Ntuple files
We run the event selection script to produce the ntuple files

```bash
cd CMS_winter_school
root -b -q EventSelection_dineutrino_Resolved_2018.cpp
```

Run this script will produce four root files: ST\_t-channel\_antitop.root  ST\_t-channel\_top.root  ST\_tW\_antitop.root  ST\_tW\_top.root in your directory

## 5.Produce the MC distribution plots
Finally, we will use the ntuple root files as input to make plots

```bash
root -b -q plotterPreselection_dineutrino_2018.cpp  
```
We can open the plots: 

```bash
display TopMass.pdf
display TopPt.pdf
display TopEta.pdf
```
Then you can see the top mass,pt,eta distribution

After doing this exercise you can exit current environment:

```bash
exit
```
