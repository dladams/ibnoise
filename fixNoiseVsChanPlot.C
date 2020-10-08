void fixNoiseVsChanPlot(string sfbas) {
  string sfin = sfbas + ".tpad";
  string sfout = sfbas + "Fixed.png";
  // Find the run number.
  string::size_type ipos = sfbas.find("ibgroup");
  string srun1 = sfbas.substr(ipos+7, 6);
  string srun2 = sfbas.substr(ipos+14, 6);
  string srune;
  if ( sfbas[ipos+20] == '-' ) {
    string::size_type jpos = sfbas.find("/", ipos+21);
    srune = sfbas.substr(ipos+21, jpos-ipos-21);
  }
  while ( srun1.size() > 1 && srun1[0] == '0' ) srun1 = srun1.substr(1);
  while ( srun2.size() > 1 && srun2[0] == '0' ) srun2 = srun2.substr(1);
  string srun = srun1 + "-" + srun2;
  if ( srune.size() ) {
    srun += " (" + srune + ")";
  }
  cout << "Base is " << sfbas << endl;
  cout << "Run is " << srun << endl;
  string srep1 = "run RunNotFound All";
  string srep2 = "runs " + srun;
  TPadManipulator* pman = TPadManipulator::read(sfin);
  if ( pman == nullptr ) return;
  string sttl = pman->getTitle();
  ipos = sttl.find(srep1);
  if ( ipos == string::npos ) {
    cout << "Unable to find \"" << srep1 << "\" in title:" << endl;
    cout << sttl << endl;
    return;
  }
  sttl.replace(ipos, srep1.size(), srep2);
  cout << "Title is " << sttl << endl;
  pman->setTitle(sttl);
  pman->print(sfout);
  cout << "Printed " << sfout << endl;
}
