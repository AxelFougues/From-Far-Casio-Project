@echo off
rem Do not edit! This batch file is created by CASIO fx-9860G SDK.


if exist REBORN.G1A  del REBORN.G1A

cd debug
if exist FXADDINror.bin  del FXADDINror.bin
"A:\Programmes\OS\SH\Bin\Hmake.exe" Addin.mak
cd ..
if not exist debug\FXADDINror.bin  goto error

"A:\Programmes\Tools\MakeAddinHeader363.exe" "A:\Dropbox\new procedure"
if not exist REBORN.G1A  goto error
echo Build has completed.
goto end

:error
echo Build was not successful.

:end

