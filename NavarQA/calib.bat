echo off
cd calib
matlab.exe -nodisplay -nosplash -r runme
:loop
tasklist /fi "imagename eq MATLAB.exe" |find ":" > nul
if errorlevel 1 goto loop
exit
cd ..