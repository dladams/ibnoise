# setupPlotsIb4b.sh
#
# David Adams
# July 2020
#
# Example configuration file for the drawNoise command in dunenoise.

SDET=iceberg4b
PLOTS="tai-nsgrms:400,tai-nsgrms50:300,cnr-nsgrms:400,cnr-nsgrms50:300,tai-utcran:noplot"
CRVS="zcGood-uvGood"
DIRPAT="ib4%REC%NoiseVsChan/setIceberg4b/iceberg%RUN%/chmet_%VAR%_all_run%RUN%_%REC%.tpad"
EVTPAT="ib4%REC%NoiseVsChan/setIceberg4b/iceberg%RUN%/event%EVT%/chmet_%VAR%_all_run%RUN%_%REC%.tpad"
GRPPAT="ib4%REC%NoiseVsChan/setIceberg4b/ibgroup%RUN%/chmet_%VAR%_all_runRunNotFound_%REC%.tpad"
#SUMNAM="plots-noisesum/noise_%ALLSPEC%_%CURVES%_run%RUN%"
SUMNAM="plots-noisesum/noisesum_run%RUN%"
