#for ipconfig from windows powershell
ipconfig.exe | grep "IPv4" | sed -n '2p' | tail -c13
#export DISPLAY=(192.168.1.4:0.0)
#make sure that $LIBGL_ALWAYS_INDIRECT = 1
