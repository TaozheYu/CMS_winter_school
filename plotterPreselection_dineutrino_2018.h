void MakeHistos(char CUT[1000],const char *plot,int BIN,float MIN,float MAX,int JETSyst,
		TH1F* &ST_1_func,TH1F* &ST_2_func,TH1F* &ST_3_func,TH1F* &ST_4_func);

int SigSF = 100;
float LUMI  = 59740.0; 
//1% width

float w0700 = SigSF*(0.07804*LUMI/(393949-1051)); //SIG1
float w0800 = SigSF*(0.04154*LUMI/(378870-1130)); //SIG2
float w0900 = SigSF*(0.02334*LUMI/(383586-1414)); //SIG3
float w1000 = SigSF*(0.01362*LUMI/(398466-1534)); //SIG4
float w1100 = SigSF*(0.00823*LUMI/(398143-1857)); //SIG5
float w1200 = SigSF*(0.00511*LUMI/(393990-2010)); //SIG6
float w1300 = SigSF*(0.00325*LUMI/(393784-2216)); //SIG7
float w1400 = SigSF*(0.00212*LUMI/(397573-2427)); //SIG8
float w1500 = SigSF*(0.00141*LUMI/(377721-2579)); //SIG9
float w1600 = SigSF*(0.00094*LUMI/(381193-2807)); //SIG10
float w1700 = SigSF*(0.00064*LUMI/(393789-3211)); //SIG11
float w1800 = SigSF*(0.00044*LUMI/(121289-106)); //SIG12


//5% width
/*float w0700 = SigSF*(0.38772*LUMI/(393949-1051)); //SIG1
float w0800 = SigSF*(0.20453*LUMI/(378870-1130)); //SIG2
float w0900 = SigSF*(0.11376*LUMI/(383586-1414)); //SIG3
float w1000 = SigSF*(0.06591*LUMI/(398466-1534)); //SIG4
float w1100 = SigSF*(0.03970*LUMI/(398143-1857)); //SIG5
float w1200 = SigSF*(0.02459*LUMI/(393990-2010)); //SIG6
float w1300 = SigSF*(0.01562*LUMI/(393784-2216)); //SIG7
float w1400 = SigSF*(0.01013*LUMI/(397573-2427)); //SIG8
float w1500 = SigSF*(0.00671*LUMI/(377721-2579)); //SIG9
float w1600 = SigSF*(0.00451*LUMI/(381193-2807)); //SIG10
float w1700 = SigSF*(0.00308*LUMI/(393789-3211)); //SIG11
float w1800 = SigSF*(0.00213*LUMI/(121289-106)); //SIG12
*/
//Old JEC
/*float w01 = (384.1*LUMI/(17081628-8750));    //ZToNuNu_HT100to200    
float w02 = (118.1*LUMI/(23256510-19836));     //ZToNuNu_HT200to400    
float w03 = (14.7*LUMI/(9498250-12850));  //ZToNuNu_HT400to600  
float w04 = (3.35*LUMI/(5738491-10484));     //ZToNuNu_HT600to800        
float w05 = (1.41*LUMI/(2061580-5218));     //ZToNuNu_HT800to1200
float w06 = (0.316*LUMI/(341750-1448));      //ZToNuNu_HT1200to2500      
float w07 = (0.00722*LUMI/(354986-4653));      //ZToNuNu_HT2500toInf       
float w08 = (1559000*LUMI/(54270554-18888));       //QCD_HT200to300            
float w09 = (315900*LUMI/(54631132-30447));       //QCD_HT300to500           
float w10 = (29070*LUMI/(55104581-48379));     //QCD_HT500to700            
float w11 = (5962*LUMI/(47665246-59458));    //QCD_HT700to1000           
float w12 = (1005*LUMI/(15437011-29214));   //QCD_HT1000to1500      
float w13 = (101.8*LUMI/(10921419-33668));   //QCD_HT1500to2000      
float w14 = (20.54*LUMI/(5445111-30566));  //QCD_HT2000toInf 
float w15 = (1695.*LUMI/(29504734-16424));    //WToLNu_HT100to200
float w16 = (532.4*LUMI/(24232737-21777));    //WToLNu_HT200to400
float w17 = (61.6*LUMI/(5330215-7500));    //WToLNu_HT400to600
float w18 = (12.4*LUMI/(16618853-30146));    //WToLNu_HT600to800
float w19 = (5.77*LUMI/(8382457-20230));    //WToLNu_HT800to1200
float w20 = (1.023*LUMI/(7602766-31183));    //WToLNu_HT1200to2500
float w21 = (0.0248*LUMI/(3232796-41184));    //WToLNu_HT2500toInf
float w22 = (88.290*LUMI/(64050742-259258));     //TTbar1 2L2Nu
float w23 = (365.34*LUMI/(100422333-407667));//TTbar2 semileptonic       
float w24 = (80.95*LUMI/(76032339-2411961));   //ST_t-channel_antitop  
float w25 = (136.02*LUMI/(146615837-5017763));   //ST_t-channel_top      
float w26 = (38.06*LUMI/(7605590-17410));  //ST_tW_antitop.root     
float w27 = (38.06*LUMI/(9575956-22044));     //ST_tW_top     
float w28 = (1.204*LUMI/(6656071-33829)); //ZZTo4L
float w29 = (3.222*LUMI/(22857846-5042623)); //ZZTo2L2Q
float w30 = (0.5644*LUMI/(8377176-5424)); //ZZTo2L2Nu
float w31 = (10.48*LUMI/(7744083-14817)); //WWTo2L2Nu
float w32 = (43.53*LUMI/(19163061-36039)); //WWToLNuQQ
float w33 = (10.73*LUMI/(14132729-3586385)); //WZTo1L1Nu2Q
float w34 = (5.606*LUMI/(22621041-5572607)); //WZTo2L2Q
float w35 = (4.43*LUMI/(9149138-2099180)); //WZTo3LNu  
float w36 = (0.2125*LUMI/(3799018-1112923)); //TTWToLNu
float w37 = (0.2253*LUMI/(9777023-3502977)); //TTZToLLNuNu
float w38 = (0.1655*LUMI/(370492-217508)); //tZq.root
float w39 = (4.072*LUMI/(47090550-10638442)); //ZZTo2Q2Nu
float w40 = (3.05*LUMI/(1305208-384856)); //WZTo1L3Nu
*/
//NEW JEC
float w01 = (384.1*LUMI/(23690838-12056));    //ZToNuNu_HT100to200    
float w02 = (118.1*LUMI/(23256510-19836));     //ZToNuNu_HT200to400    
float w03 = (14.7*LUMI/(9498250-12850));  //ZToNuNu_HT400to600  
float w04 = (3.35*LUMI/(5738491-10484));     //ZToNuNu_HT600to800        
float w05 = (1.41*LUMI/(2061580-5218));     //ZToNuNu_HT800to1200
float w06 = (0.316*LUMI/(341750-1448));      //ZToNuNu_HT1200to2500      
float w07 = (0.00722*LUMI/(354986-4653));      //ZToNuNu_HT2500toInf       
float w08 = (1559000*LUMI/(54270554-18888));       //QCD_HT200to300            
float w09 = (315900*LUMI/(54631132-30447));       //QCD_HT300to500           
float w10 = (29070*LUMI/(55104581-48379));     //QCD_HT500to700            
float w11 = (5962*LUMI/(48098739-59999));    //QCD_HT700to1000           
float w12 = (1005*LUMI/(15437011-29214));   //QCD_HT1000to1500      
float w13 = (101.8*LUMI/(10921419-33668));   //QCD_HT1500to2000      
float w14 = (20.54*LUMI/(5445111-30566));  //QCD_HT2000toInf 
float w15 = (1695.*LUMI/(29504734-16424));    //WToLNu_HT100to200
float w16 = (532.4*LUMI/(25446044-22889));    //WToLNu_HT200to400
float w17 = (61.6*LUMI/(5924335-8366));    //WToLNu_HT400to600
float w18 = (12.4*LUMI/(19735538-35756));    //WToLNu_HT600to800
float w19 = (5.77*LUMI/(8382457-20230));    //WToLNu_HT800to1200
float w20 = (1.023*LUMI/(7602766-31183));    //WToLNu_HT1200to2500
float w21 = (0.0248*LUMI/(3232796-41184));    //WToLNu_HT2500toInf
float w22 = (88.290*LUMI/(64050742-259258));     //TTbar1 2L2Nu
float w23 = (365.34*LUMI/(100402442-407558));//TTbar2 semileptonic       
float w24 = (80.95*LUMI/(76658965-2431835));   //ST_t-channel_antitop  
float w25 = (136.02*LUMI/(149201191-5106409));   //ST_t-channel_top      
float w26 = (38.06*LUMI/(7605590-17410));  //ST_tW_antitop.root     
float w27 = (38.06*LUMI/(9575956-22044));     //ST_tW_top     
float w28 = (1.204*LUMI/(6656071-33829)); //ZZTo4L
float w29 = (3.222*LUMI/(22857846-5042623)); //ZZTo2L2Q
float w30 = (0.5644*LUMI/(8377176-5424)); //ZZTo2L2Nu
float w31 = (10.48*LUMI/(7744083-14817)); //WWTo2L2Nu
float w32 = (43.53*LUMI/(19163061-36039)); //WWToLNuQQ
float w33 = (10.73*LUMI/(15075066-3826403)); //WZTo1L1Nu2Q
float w34 = (5.606*LUMI/(22621041-5572607)); //WZTo2L2Q
float w35 = (4.43*LUMI/(9149138-2099180)); //WZTo3LNu  
float w36 = (0.2125*LUMI/(3799018-1112923)); //TTWToLNu
float w37 = (0.2253*LUMI/(9777023-3502977)); //TTZToLLNuNu
float w38 = (0.1655*LUMI/(630494-369506)); //tZq.root
float w39 = (4.072*LUMI/(47090550-10638442)); //ZZTo2Q2Nu
float w40 = (3.05*LUMI/(1305208-384856)); //WZTo1L3Nu
TFile *file37 = TFile::Open("./ST_t-channel_antitop.root");
TFile *file38 = TFile::Open("./ST_t-channel_top.root");
TFile *file39 = TFile::Open("./ST_tW_antitop.root");
TFile *file40 = TFile::Open("./ST_tW_top.root");
TTree *Tree37 = (TTree*)file37->Get("tree");
TTree *Tree38 = (TTree*)file38->Get("tree");
TTree *Tree39 = (TTree*)file39->Get("tree");
TTree *Tree40 = (TTree*)file40->Get("tree");

TH1F *ST_1_SR; TH1F *ST_2_SR; TH1F *ST_3_SR; TH1F *ST_4_SR; 

