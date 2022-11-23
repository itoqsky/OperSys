sudo fallocate -l 120M ~/lofs.img
ULOOP=$(sudo losetup -f)
sudo losetup ${ULOOP} ~/lofs.img
sudo mkfs.ext4 ~/lofs.img 
sudo mkdir ~/lofsdisk
sudo mount ${ULOOP} ~/lofsdisk