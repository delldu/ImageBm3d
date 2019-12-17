
SDR_4K_DIR=/home/dell/ZDisk/DataSet/4K
video_file=$1

echo "$video_file ..."

mkdir /tmp/sdr
video_coder --decode $SDR_4K_DIR/SDR_540p/$video_file /tmp/sdr/%3d.png
list=`ls /tmp/sdr`
for f in $list ;
do
	f1="/tmp/sdr/$f"
	f2="tmp/$f"
	echo "$f2 ..."
	./bm3d $f1 $f2 25 color twostep quiet
done

video_coder --encode tmp/%3d.png /tmp/a.mp4
video_score /tmp/a.mp4 /$SDR_4K_DIR/SDR_540c/$video_file

rm -rf /tmp/sdr
