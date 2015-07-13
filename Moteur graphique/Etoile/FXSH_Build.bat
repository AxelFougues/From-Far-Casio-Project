@echo off
rem Do not edit! This batch file is created by CASIO fx-9860G SDK.


if exist ETOILE.G1A  del ETOILE.G1A

cd debug
if exist FXADDINror.bin  del FXADDINror.bin
"C:\SDK\OS\SH\Bin\Hmake.exe" Addin.mak
cd ..
if not exist debug\FXADDINror.bin  goto error

"C:\SDK\Tools\MakeAddinHeader363.exe" "C:\Users\Az\From-Far-Casio-Project\Moteur graphique\Etoile"
if not exist ETOILE.G1A  goto error
echo Build has completed.
goto end

:error
echo Build was not successful.

:end

