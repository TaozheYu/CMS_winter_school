#include "plotterPreselection_dineutrino_2018.h"

void plotterPreselection_dineutrino_2018(){ 
  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.5); //title X location 
  gStyle->SetTitleY(0.96); //title Y location 
  gStyle->SetPaintTextFormat(".2f");
  gErrorIgnoreLevel = kError;
  using namespace std; 

  bool SYST = false;

  vector<TString> name;                vector<int> bin;      vector<float> Min;      vector<float> Max;     vector<TString> axis;
  
  name.push_back("TopMass"); bin.push_back(20);     Min.push_back(100);    Max.push_back(500);    axis.push_back("Top Mass[GeV]");
  name.push_back("TopPt");   bin.push_back(20);     Min.push_back(200);    Max.push_back(550);   axis.push_back("Top pt[GeV] ");
  name.push_back("TopEta");  bin.push_back(20);     Min.push_back(-3);   Max.push_back(3);      axis.push_back("Top #eta");
  //name.push_back("TransverseMassMetTop"); bin.push_back(30);     Min.push_back(500);    Max.push_back(3000);    axis.push_back("TransverseMassMetTop");
  
  
  for(int i=0; i<name.size(); i++){
    const char *plot = name[i];
    char CUT[1000]; char CUTpre[1000]; char CUTpup1[1000]; char CUTpup2[1000]; char CUTbta1[1000]; char CUTbta2[1000];  char CUTfor1[1000]; char CUTfor2[1000]; char CUTwje1[1000]; char CUTwje2[1000]; char CUTzje1[1000];  char CUTzje2[1000];  char CUTttb1[1000];  char CUTttb2[1000];  char CUTfir1[1000];  char CUTfir2[1000];char CUTqcd1[1000]; char CUTqcd2[1000];char CUTpdf1[1000]; char CUTpdf2[1000]; char CUTtri1[1000]; char CUTtri2[1000];
	
        sprintf(CUTpre,"((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>0.6)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(MostForwardJetEta<4&&MostForwardJetEta>-4))");
        sprintf(CUT,    "PUWeight    *w_Btag    *genWeight  *prefiringweight    *w_Trig  *w_HEM*w_ZToNuNu  *w_WToLNu  *w_ttbar *%s",CUTpre);
        
	MakeHistos(CUT,plot,bin[i],Min[i],Max[i],0,ST_1_SR,ST_2_SR,ST_3_SR,ST_4_SR);
       
	
	ST_1_SR->SetLineWidth(2); ST_2_SR->SetLineWidth(2); ST_3_SR->SetLineWidth(2); ST_4_SR->SetLineWidth(2); 
	ST_1_SR->SetLineColor(kGreen+3); ST_2_SR->SetLineColor(kGreen+3); ST_3_SR->SetLineColor(kGreen+3); ST_4_SR->SetLineColor(kGreen+3); 
	ST_1_SR->SetFillColor(kGreen+3); ST_2_SR->SetFillColor(kGreen+3); ST_3_SR->SetFillColor(kGreen+3); ST_4_SR->SetFillColor(kGreen+3); 

	Double_t ST_1Err = 0; Float_t ST_1Yield = ST_1_SR->IntegralAndError(1,ST_1_SR->GetNbinsX(),ST_1Err,"");
	Double_t ST_2Err = 0; Float_t ST_2Yield = ST_2_SR->IntegralAndError(1,ST_1_SR->GetNbinsX(),ST_2Err,"");
	Double_t ST_3Err = 0; Float_t ST_3Yield = ST_3_SR->IntegralAndError(1,ST_1_SR->GetNbinsX(),ST_3Err,"");
	Double_t ST_4Err = 0; Float_t ST_4Yield = ST_4_SR->IntegralAndError(1,ST_1_SR->GetNbinsX(),ST_4Err,"");

    if(i==0){
      cout<<endl;
      //cout<<"Plotting "<<name[i]<<endl;
	  cout<<"single top events number        = "<<ST_1_SR->Integral()+ST_2_SR->Integral()+ST_3_SR->Integral()+ST_4_SR->Integral()<<" +/- "<<sqrt(ST_1Err*ST_1Err+ST_2Err*ST_2Err+ST_3Err*ST_3Err+ST_4Err*ST_4Err)<<endl;
	}

    TCanvas* c1 = new TCanvas("c1","c1",0,0,900,600);


    /*
    TPad *c1_1 = new TPad("c1_1","newpad",0.01,0.01,0.99,0.32);
    c1_1->Draw();
    c1_1->cd();
    c1_1->SetTopMargin(0.045);
    c1_1->SetBottomMargin(0.3);
    c1_1->SetRightMargin(0.035);
    c1_1->SetLeftMargin(0.11);
    
    TGraphAsymmErrors *gDATA = new TGraphAsymmErrors(data_SR);	
    gDATA->SetLineWidth(2); 
    gDATA->SetLineColor(1);
    gDATA->SetMarkerColor(1); 
    gDATA->SetMarkerStyle(20); 
    gDATA->SetMarkerSize(1.3);
    for (int i = 0; i < gDATA->GetN(); ++i) {
      double alpha = 1 - 0.6827;
      int M = gDATA->GetY()[i];
      double L =  (M==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,M,1.));
      double U =  ROOT::Math::gamma_quantile_c(alpha/2,M+1,1);
      //if(M!=0){
      gDATA->SetPointEYlow(i, M-L);
      gDATA->SetPointEYhigh(i, U-M);
      //}
    }
    TH1F *RATIO2 = (TH1F*)background_SR->Clone();
    Double_t x[bin[i]]; Double_t exl[bin[i]]; Double_t exh[bin[i]];
    Double_t y[bin[i]]; Double_t eyl[bin[i]]; Double_t eyh[bin[i]]; 
    for(int m=0; m<background_SR->GetNbinsX(); m++){ 
      x[m]=Min[i]+m*(Max[i]-Min[i])/bin[i]+(Max[i]-Min[i])/(2*bin[i]);
      exl[m]=(Max[i]-Min[i])/(2*bin[i]);
      exh[m]=(Max[i]-Min[i])/(2*bin[i]);
      RATIO2->SetBinContent(m+1,1);
      if(background_SR->GetBinContent(m+1)!=0) {
	y[m]=data_SR->GetBinContent(m+1)/background_SR->GetBinContent(m+1);
	eyl[m]=sqrt(gDATA->GetErrorYlow(m)*gDATA->GetErrorYlow(m))/background_SR->GetBinContent(m+1);
	eyh[m]=sqrt(gDATA->GetErrorYhigh(m)*gDATA->GetErrorYhigh(m))/background_SR->GetBinContent(m+1);
	RATIO2->SetBinError(m+1,background_SR->GetBinError(m+1)/background_SR->GetBinContent(m+1));
      } else {
	y[m]=-1;
	eyl[m]=0;
	eyh[m]=0;
      }
      cout<<eyh[m]<<", ";
    }

    TGraphAsymmErrors *RATIO = new TGraphAsymmErrors(bin[i],x,y,exl,exh,eyl,eyh);
    RATIO->Draw("AE0p");
    RATIO->SetMarkerColor(1); 
    RATIO->SetMarkerStyle(21); 
    RATIO->SetMarkerSize(1.0);
    RATIO->SetMaximum(1.7);
    RATIO->SetMinimum(0.3);
    RATIO->SetLineColor(1);
    RATIO->SetLineWidth(2);
    RATIO->GetXaxis()->SetTitleOffset(0.9);
    RATIO->GetYaxis()->SetTitleOffset(0.5);
    RATIO->SetTitle("");
    RATIO->GetYaxis()->SetTitle("observed/expected");
    RATIO->GetXaxis()->SetTitle(axis[i]);
    RATIO->GetXaxis()->SetLabelSize(0.13);
    RATIO->GetYaxis()->SetLabelSize(0.13);
    RATIO->GetXaxis()->SetTitleSize(0.15);
    RATIO->GetYaxis()->SetTitleSize(0.09);
    RATIO->GetYaxis()->SetNdivisions(505);
    RATIO->GetXaxis()->SetRangeUser(Min[i],Max[i]);
    RATIO2->SetFillStyle(3002);
    RATIO2->SetFillColor(12);
    RATIO2->SetLineColor(12);
    RATIO2->SetMarkerSize(0);
    RATIO2->Draw("E2same");
    RATIO->Draw("E0psame");

    TLine* line = new TLine(Min[i],1,Max[i],1);
    line->SetLineColor(2);
    line->SetLineWidth(2);
    line->Draw("same");	
    c1->cd();
    */
    TPad *c1_2 = new TPad("c1_2", "newpad",0.01,0.01,0.99,0.99);
    c1_2->SetLogy();
    c1_2->Draw();
    c1_2->cd();
    c1_2->SetTopMargin(0.08);
    c1_2->SetBottomMargin(0.15);
    c1_2->SetRightMargin(0.035);
    c1_2->SetLeftMargin(0.11);
     
   
    THStack *hs = new THStack("hs","hs");
    hs->Add(ST_1_SR);
    hs->Add(ST_2_SR);
    hs->Add(ST_3_SR);
    hs->Add(ST_4_SR);
	 
    hs->Draw("histo");
    hs->SetMinimum(1);
    hs->GetYaxis()->SetTitleSize(0.060);
    hs->GetXaxis()->SetTitleSize(0.060);
    hs->GetYaxis()->SetLabelSize(0.060);
    hs->GetXaxis()->SetLabelSize(0.05); 
    hs->SetTitle("");
    hs->GetYaxis()->SetTitle("Events");
    hs->GetXaxis()->SetTitle(axis[i]);
    hs->GetYaxis()->SetTitleOffset(0.80);
    hs->GetXaxis()->SetTitleOffset(0.90);
     

    TPad *pad = new TPad("pad","pad",0.01,0.01,0.99,0.99);
    gPad->RedrawAxis();
    TString channelText = "";
    float channelTextFont   = 42;
    float channelTextSize   = 0.06;
    TString cmsText     = "CMS";
    float cmsTextFont   = 61;  // default is helvetic-bold
    bool writeExtraText = true;
    TString extraText   = "Preliminary";
    //TString extraText   = "";
    float extraTextFont = 52;  // default is helvetica-italics
    // text sizes and text offsets with respect to the top frame in unit of the top margin size
    float lumiTextSize     = 0.6;
    float lumiTextOffset   = 0.2;
    float cmsTextSize      = 0.75;
    float cmsTextOffset    = 0.1;  // only used in outOfFrame version
    float relPosX    = 0.045;
    float relPosY    = 0.035;
    float relExtraDY = 1.2;
    // ratio of "CMS" and extra text size
    float extraOverCmsTextSize  = 0.76;
    TString lumi_13TeV;
    lumi_13TeV = "59.7fb^{-1}";
    TString lumiText;
    lumiText += lumi_13TeV;
    lumiText += " (2018, 13 TeV)";
    float t = pad->GetTopMargin();
    float b = pad->GetBottomMargin();
    float r = pad->GetRightMargin();
    float l = pad->GetLeftMargin();
    TLatex latex;
    latex.SetNDC();
    latex.SetTextAngle(0);
    latex.SetTextColor(kBlack);    
    float extraTextSize = extraOverCmsTextSize*cmsTextSize;
    latex.SetTextFont(42);
    latex.SetTextAlign(31); 
    latex.SetTextSize(lumiTextSize*t);    
    latex.DrawLatex(1-r+0.06,0.94,lumiText);
    latex.SetTextFont(cmsTextFont);
    latex.SetTextAlign(11); 
    latex.SetTextSize(cmsTextSize*t);    
    latex.DrawLatex(l+0.01, 0.94,cmsText);
    latex.SetTextFont(extraTextFont);
    latex.SetTextSize(extraTextSize*t);
    latex.DrawLatex(l+0.12, 0.94, extraText); 
    latex.SetTextFont(channelTextFont);
    latex.SetTextSize(channelTextSize);


    TLegend *pl2 = new TLegend(0.75,0.83,0.95,0.88);
    pl2->SetTextSize(0.045); 
    pl2->SetFillColor(0);
    TLegendEntry *ple2 = pl2->AddEntry(ST_1_SR, "single top",  "F"); 
    //ple2 = pl2->AddEntry(ST_1_SR, "t#bar{t} and single-top",  "F");
    pl2->SetBorderSize(0);
    pl2->Draw();
    
    TString NAME = name[i];
    cout<<"Finished "<<NAME<<endl;
    c1->SaveAs(NAME+".pdf");

  }

}


void GetHisto(char CUT[1000], TTree *Tree, TH1F* & histo, const char *plot, int BIN, float MIN, float MAX){
  char input[50]; sprintf(input,"%s>>h(%i,%f,%f)",plot,BIN,MIN,MAX);
  TH1F *temp = new TH1F("", "", BIN,MIN,MAX);
  if(Tree->Draw(input,CUT)){ Tree->Draw(input,CUT); TH1F* h=(TH1F*)gDirectory->Get("h"); histo = (TH1F*)h->Clone(); delete h; } else { histo = (TH1F*)temp->Clone(); }
  histo->SetDirectory(0);
  histo->SetName("histo");
  delete temp;
 }


void MakeHistos(char CUT[1000],const char *plot,int BIN,float MIN,float MAX,int JETSyst,
		TH1F* &ST_1_func,TH1F* &ST_2_func,TH1F* &ST_3_func,TH1F* &ST_4_func){
  TH1F *ST_1; TH1F *ST_2; TH1F *ST_3; TH1F *ST_4; 
  
  if(JETSyst==0){
    GetHisto(CUT, Tree37, ST_1    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree38, ST_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree39, ST_3    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree40, ST_4    ,plot,BIN,MIN,MAX);
  } 
  //TH1F *background = new TH1F("","",data->GetNbinsX(),data->GetXaxis()->GetXmin(),data->GetXaxis()->GetXmax());
  for(int j=1; j<ST_1->GetNbinsX()+1; j++){
    if(ST_1->GetBinContent(j)>0){ST_1->SetBinError(j,sqrt(w24*w24*ST_1->GetBinContent(j)));}else{ST_1->SetBinError(j,0);}//w24);}
    if(ST_2->GetBinContent(j)>0){ST_2->SetBinError(j,sqrt(w25*w25*ST_2->GetBinContent(j)));}else{ST_2->SetBinError(j,0);}//w25);}
    if(ST_3->GetBinContent(j)>0){ST_3->SetBinError(j,sqrt(w26*w26*ST_3->GetBinContent(j)));}else{ST_3->SetBinError(j,0);}//w26);}
    if(ST_4->GetBinContent(j)>0){ST_4->SetBinError(j,sqrt(w27*w27*ST_4->GetBinContent(j)));}else{ST_4->SetBinError(j,0);}//w27);}

    float err05 = ST_1->GetBinError(j)*ST_1->GetBinError(j) + ST_2->GetBinError(j)*ST_2->GetBinError(j)+ ST_3->GetBinError(j)*ST_3->GetBinError(j)+ ST_4->GetBinError(j)*ST_4->GetBinError(j);

    ST_1->SetBinContent(j,w24*ST_1->GetBinContent(j));
    ST_2->SetBinContent(j,w25*ST_2->GetBinContent(j));
    ST_3->SetBinContent(j,w26*ST_3->GetBinContent(j));
    ST_4->SetBinContent(j,w27*ST_4->GetBinContent(j));

    float bkg4 = ST_1 ->GetBinContent(j) + ST_2 ->GetBinContent(j) + ST_3 ->GetBinContent(j) + ST_4 ->GetBinContent(j);

    
  }

  ST_1_func = (TH1F*)ST_1->Clone();    
  ST_2_func = (TH1F*)ST_2->Clone();    
  ST_3_func = (TH1F*)ST_3->Clone();    
  ST_4_func = (TH1F*)ST_4->Clone();    

  delete ST_1; delete ST_2;  delete ST_3; delete ST_4;  
}



