# ibnoise/README.txt
#
# David Adams
# Top level package for Iceberg noise analysis.
#
# Sep 2020: Updated for Iceberg 4.

################ Processing noise vs. channel by run ###############

./makejobs RUN1 [RUN2]
# add these lines to runjobs.txt
# --> duneproc ib4ataiNoiseVsChan iceberg006003
# --> duneproc ib4acnrNoiseVsChan iceberg006003
# The single run can also be replaced with a run range.

# To create single-run noise summary plots and publish those with the
# noise vs. channel plots and noise vs. time for the specified run sequence:
./showNoise RUN1 RUN2
# This adds the plots for any run that is missing and processed in the
# specified range.
# --> drawNoise RUN
# --> drawNoise RUN odd
# --> drawNoise RUN even
# --> ./saveNoise RUN

#################### Processing DFT by run ########################

./makeDftJobs RUN1 RUN2

./saveDft run00RUN

#################### Processing noise or DFT by group ########################

#drawNoiseVsTime 6564 6669 nsgrms 100 true

# To submit group processing jobs for any groups in the indicated range:
./makeGroupJobs RUN1 RUN2 PRCS
# PRCS is one or more of the following:
#   chan for noise vs channel
#   dft for full-range, binned DFT power
#   dft200 for 0-200 kHz, unbinned DFT power

# To create group summary plots after running those jobs.
saveGroups RUN1 RUN2 PRCS
# PRCS is one or more of the following:
#   chan for noise vs channel
#   dft for full-range and 200 kHz DFT power

#################### Processing noise by event ########################

# Run job for each event.
./makejobsByEvent RUN EVT1 EVT2

# Create noise plot for each event.
drawNoise RUN EVT

# Plot noise vs event.
./showNoise RUN RUN NEVT

######################## Other unneeded (?) options #######################

# To create noise vs. channel and summary for a run group
drawNoise 006548-006553
drawNoise 006548-006553 odd
drawNoise 006548-006553 even
./saveNoise 006448-006454

#./saveDft group006448-006454
