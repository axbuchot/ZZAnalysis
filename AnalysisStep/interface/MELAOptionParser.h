/** \class MELAOptionParser
*
*
*  \author N. Amapane - Torino
*  \author U. Sarica - JHU
*
*
*  Description:
*
*  This container class is implemented to keep the options of the MELA computation in one place.
*  Some of the options (e.g. AddPAux) decides if there should be a separate branch related with the same computation.
*  These options are meant to be used in the main body of the code, the creation of the MELABranches,
*  and the control of the computation or the hypothesis itself.
*
*/
#ifndef MELAOPTIONPARSER_H
#define MELAOPTIONPARSER_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
#include "TString.h"
#include <ZZMatrixElement/MELA/interface/TVar.hh>


class MELAOptionParser{

protected:

  std::vector<std::string> rawOptions;
  std::string couplingsString;
  std::string strName;
  std::string strAlias;
  std::string strCluster;

public:

  std::vector<std::string> addedAliases;
  std::vector<std::string> subtractedAliases;
  std::vector<std::string> multipliedAliases;
  std::vector<std::string> dividedAliases;

  std::vector<std::string> maximizationNumerators;
  std::vector<std::string> maximizationDenominators;

  TVar::Process proc;
  TVar::Production prod;
  TVar::MatrixElement ME;
  TVar::SuperMelaSyst superSyst;

protected:

  Bool_t noBranching;
  Bool_t includePAux;
  Bool_t includePConst;
  Bool_t isPM4L;
  Bool_t isGenProb;
  Float_t defME;

public:

  Float_t hmass;
  Float_t h2mass;
  Float_t hwidth;
  Float_t h2width;

  SpinZeroCouplings coupl_H;
  SpinOneCouplings coupl_Zp;
  SpinTwoCouplings coupl_X;

  MELAOptionParser(std::string stropts);
  ~MELAOptionParser(){}

  void analyze();
  void splitOption(const std::string& rawoption, std::string& wish, std::string& value, char delimiter);
  void splitOptionRecursive(const std::string& rawoption, std::vector<std::string>& splitoptions, char delimiter);
  void interpretOption(std::string wish, std::string value);

  Bool_t usePM4L() const{ return isPM4L; }
  Bool_t isGen() const{ return isGenProb; }
  Bool_t hasPAux() const{ return includePAux; }
  Bool_t hasPConst() const{ return includePConst; }
  Bool_t isAliased() const{ return !strAlias.empty(); }
  Bool_t doBranch() const{ return !noBranching; }
  Float_t getDefaultME() const{ return defME; }
  std::string getName() const{ return strName; }
  std::string getAlias() const{ return strAlias; }
  std::string getCluster() const{ return strCluster; }

protected:

  Bool_t checkListVariable(const std::vector<std::string>& list, const std::string& var) const;

  void setProcess(std::string opt);
  void setProduction(std::string opt);
  void setME(std::string opt);
  void setSuperMelaSyst(std::string opt);
  void extractCoupling(std::string opt);

  void setAddedAliases(std::string opt);
  void setSubtractedAliases(std::string opt);
  void setMultipliedAliases(std::string opt);
  void setDividedAliases(std::string opt);

  void setMaximizationNumAliases(std::string opt);
  void setMaximizationDenomAliases(std::string opt);

};

#endif

