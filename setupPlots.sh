SFRUN=$1
if echo $SFRUN | grep - 1>/dev/null 2>/dev/null; then
  RUN=$(echo $SFRUN | sed 's/-.*//g')
else
  RUN=$SFRUN
fi
echo $RUN
PER=$(ibRunPeriod $RUN)
source ./setupPlotsIb$PER.sh
