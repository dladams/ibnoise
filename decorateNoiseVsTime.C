// decorateNoiseVsTime.C
//
void decorateNoiseVsTime(TPadManipulator& man) {
  cout << "Decorating..." << endl;
  vector<int> runStarts = {6401, 6515, 6548, 6554, 6559, 6564, 6653, 6661, 6670, 6782, 6857,
                           6912, 7264, 7274, 7285, 7295, 7305, 7315, 7325, 7330, 7335,
                           7340, 7345, 7350, 7355};
  
  using GroupMap = map<int, string>;
  GroupMap  grpLabs;
  grpLabs[6401] = "CV";
  grpLabs[6515] = "C0";
  grpLabs[6548] = "P0";
  grpLabs[6554] = "PV";
  grpLabs[6559] = "C0";
  grpLabs[6564] = "CV";
  //grpLabs[6653] = "??";
  grpLabs[6661] = "P0";
  grpLabs[6670] = "CV";
  grpLabs[6782] = "CV";
  grpLabs[6857] = "C0";
  grpLabs[6912] = "XX";
  grpLabs[7264] = "C0";
  grpLabs[7274] = "P0";
  grpLabs[7285] = "PB";
  grpLabs[7295] = "PV";
  grpLabs[7305] = "CB";
  grpLabs[7315] = "CV";
  grpLabs[7325] = "CBd";
  grpLabs[7330] = "C0d";
  grpLabs[7335] = "P0d";
  grpLabs[7340] = "PBD";
  grpLabs[7345] = "PVn";
  grpLabs[7350] = "PVu";
  grpLabs[7355] = "XX";
  grpLabs[7395] = "P0";
  grpLabs[7400] = "PB";
  grpLabs[7407] = "PVa";
  grpLabs[7413] = "PVb";
  grpLabs[7419] = "PVc";
  grpLabs[7425] = "PVd";
  grpLabs[7431] = "PVe";
  grpLabs[7438] = "PVf";
  grpLabs[7445] = "PVg";
  grpLabs[7451] = "PVh";
  grpLabs[7457] = "PVi";
  grpLabs[7463] = "PVj";
  grpLabs[7469] = "PVk";
  grpLabs[7475] = "PVl";
  grpLabs[7481] = "PVm";
  grpLabs[7487] = "PVn";
  grpLabs[7492] = "PBa";
  grpLabs[7499] = "PBb";
  grpLabs[7505] = "P0";
  grpLabs[7515] = "C0a";
  grpLabs[7520] = "C0b";
  grpLabs[7525] = "C0c";
  grpLabs[7530] = "CBa";
  grpLabs[7535] = "CBb";
  grpLabs[7539] = "CV";
  grpLabs[7565] = "";
  grpLabs[7567] = "PB";
  grpLabs[7569] = "PV";
  grpLabs[7581] = "PV";
  grpLabs[7582] = "PB";
  grpLabs[7591] = "PVa";
  grpLabs[7604] = "PVb";
  grpLabs[7615] = "PVc";
  grpLabs[7620] = "PVd";
  grpLabs[7626] = "PB";
  grpLabs[7639] = "PV";
  grpLabs[7669] = "";
  grpLabs[7676] = "CV";
  grpLabs[7833] = "";
  grpLabs[7835] = "PV";
  grpLabs[7914] = "";
  double xmin = man.xmin();
  double xmax = man.xmax();
  double xran = xmax - xmin;
  double ymin = man.ymin();
  double ymax = man.ymax();
  double yran = ymax - ymin;
  double xoff = 0.002*(xmax - xmin);
  double dylab = 0.05*yran;
  double ylab1 = 0.08*yran + ymin;
  double ylab2 = ylab1 + 2.1*dylab;
  double ylab = ylab1;
  for ( GroupMap::const_iterator igrp = grpLabs.begin(); igrp!=grpLabs.end(); ++igrp ) {
    int run = igrp->first;
    if ( run < xmin ) continue;
    if ( run >= xmax ) break;
    string slab = igrp->second;
    double xlin = run - 0.5;
    man.addVerticalLine(xlin);
    double xlab = xlin + xoff;
    //cout << "XXX " << xlab << "  " << ylab << "  " << slab << endl;
    TLatex* ptxt = new TLatex(xlab, ylab, slab.c_str());
    //ptxt->SetNDC();
    ptxt->SetTextFont(42);
    ptxt->SetTextSize(0.04);
    man.add(ptxt);
    ylab += dylab;
    if ( ylab > ylab2 ) ylab = ylab1;
  }
  // Add dates.
  map<unsigned int, string> rundates = IcebergHelper::runDates(xmin, xmax, 2);
  ylab = 0.02*yran + ymin;
  for ( auto irda : rundates ) {
    float x = irda.first;
    string sdat = irda.second;
    TLatex* ptxt = new TLatex(x, ylab, sdat.c_str());
    ptxt->SetTextFont(42);
    ptxt->SetTextSize(0.04);
    man.add(ptxt);
  }
}
