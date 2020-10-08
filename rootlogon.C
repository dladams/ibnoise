{
  string loadfcl = "load.fcl";
  gROOT->ProcessLine("ArtServiceHelper::load(loadfcl)");
  gROOT->ProcessLine("DuneToolManager* ptm = DuneToolManager::instance(loadfcl)");
  gInterpreter->AddIncludePath("/dune/data2/users/dladams/data/protodune/proc/install/dev01/dunenoise");
  gROOT->ProcessLine("#include \"art/Utilities/make_tool.h\"");
  gROOT->ProcessLine("#include \"dunenoise/ApaWirePlot.h\"");
  gROOT->ProcessLine(".L $DUNENOISE_DIR/root/ibPlotWires.C");
  gROOT->ProcessLine(".L $DUNENOISE_DIR/root/ibDrawWireNoise.C");
  gROOT->ProcessLine(".L decorateNoiseVsTime.C");
  gROOT->ProcessLine(".L fixNoiseVsChanPlot.C");
}
