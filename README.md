To play the game you need to be on Linux environment.
If you are using WSL2, download VcXsrv (https://sourceforge.net/projects/vcxsrv/) and update your .bashrc file with the following lines:
```
export DISPLAY=$(ip route list default | awk '{print $3}'):0
export LIBGL_ALWAYS_INDIRECT=1
```
To access the file type ``nano ~/.bashrc`` and paste the lines above at the end of the file. Then, save and exit.
You will need to launch the VcXsrv application before running the game and have it open while playing.
Then, run the following commands in the terminal:

```
cd game (If you are not in the game folder)
make run
```

Enjoy!