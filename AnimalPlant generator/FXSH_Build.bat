@echo off
rem Do not edit! This batch file is created by CASIO fx-9860G SDK.


if exist LIFEGENE.G1A  del LIFEGENE.G1A

cd debug
if exist FXADDINror.bin  del FXADDINror.bin
"A:\Programmes\OS\SH\Bin\Hmake.exe" Addin.mak
cd ..
if not exist debug\FXADDINror.bin  goto error

"A:\Programmes\Tools\MakeAddinHeader363.exe" "A:\Desktop\From-Far-Casio-Project\AnimalPlant generator"
if not exist LIFEGENE.G1A  goto error
echo Build has completed.
goto end

:error
echo Build was not successful.

:end

