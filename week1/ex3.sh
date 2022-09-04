mkdir root
date
sleep 3
touch root/root.txt
mkdir home
touch home/home.txt
ls -ltr / > root/root.txt
ls -ltr ~ > home/home.txt
cat root/root.txt
cat home/home.txt
ls root
ls home
