#!/bin/sh

# data file name from arguments
if [ $# -ne 1 ]; then
  echo "error: This program needs one data file.."
  echo "usage:\n\r\t$0 [data file]" 1>&2
  exit 1;
elif [ ! -e $1 ]; then
  echo "error: This file is NOT exist.."
  exit 1;
elif [ ! -f $1 ]; then
  echo "error: This file is NOT normal file.."
  exit 1;
elif [ ! -r $1 ]; then
  echo "error: This file is NOT readable.."
  exit 1;
fi

if type -P gnuplot > /dev/null
then
  echo "  plot [$1]" >&2
else
  echo "error: gnuplot command is NOT found.."
  exit 1;
fi

max=`awk -F "," '{if ($2 > max) max = $2} END{print max}' $1`
max=`echo "scale=0; $max * 1.1"|bc`

gnuplot -p <<EOS
set datafile separator ","
set yrange[0:$max]
set xdata time
set timefmt "%Y/%m/%d %H:%M:%S"
set terminal png size 800,600
set output "$1.png"
plot "$1" using 1:2 with boxes ti "Motion Times"
EOS

echo "output [$1.png]" >&2

