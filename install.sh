sudo mkdir -p /var/X
sudo mkdir -p /var/Y
sudo touch /var/X/messageX.txt
sudo touch /var/Y/messageY.txt
sudo mv server /usr/local/bin/px
sudo aa-genprof /usr/local/bin/px
sudo mv policy.apparmor /etc/apparmor.d/usr.local.bin.px
sudo apparmor_parser -r /etc/apparmor.d/usr.local.bin.px
