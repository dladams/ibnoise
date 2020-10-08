# setupPlotsIb4.sh
#
# David Adams
# May 2019
#
# Example configuration file for the drawNoise command in dunenoise.

SDET=iceberg4a
PLOTS="tai-nsgrms:300,tai-nsgrms50:200,cnr-nsgrms:300,cnr-nsgrms50:200,tai-utcran:noplot"
CRVS="zcGood-uvGood"
DIRPAT="ib4%REC%NoiseVsChan/setIceberg4a/iceberg%RUN%/chmet_%VAR%_all_run%RUN%_%REC%.tpad"
GRPPAT="ib4%REC%NoiseVsChan/setIceberg4a/ibgroup%RUN%/chmet_%VAR%_all_runRunNotFound.tpad"
#SUMNAM="plots-noisesum/noise_%ALLSPEC%_%CURVES%_run%RUN%"
SUMNAM="plots-noisesum/noisesum_run%RUN%"
