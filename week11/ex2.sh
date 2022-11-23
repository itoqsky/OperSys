rm -rf lofsdisk/*
lofs=lofsdisk
sudo mkdir -p $lofs
echo "Ikram" > $lofs/file1
echo "Kamat" > $lofs/file2
sudo chmod 777 $lofs
sudo mkdir -p -v $lofs/usr/{bin,lib,lib64}
sudo cp -v /bin/{bash,cat,echo,ls} $lofs/usr/bin

cmnds="bash cat echo ls"
for i in $cmnds;
do
	libs="$(ldd /bin/"$i" | grep -Eo '/usr/lib.*\.[0-9]')"

	for j in $libs; 
	do 
		sudo cp -v "$j" "${lofs}${j}";
	done
done

ln -sf /usr/lib lofsdisk/lib
ln -sf /usr/bin lofsdisk/bin

sudo gcc ex2.c -o ex2.out
sudo cp -v ./ex2.out $lofs/
sudo chroot $lofs ./ex2.out > ex2.txt
./ex2.out >> ex2.txt