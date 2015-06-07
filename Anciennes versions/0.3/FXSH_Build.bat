@echo off
rem Do not edit! This batch file is created by CASIO fx-9860G SDK.


if exist SYSGNRTR.G1A  del SYSGNRTR.G1A

cd debug
if exist FXADDINror.bin  del FXADDINror.bin
"C:\SDK\OS\SH\Bin\Hmake.exe" Addin.mak
cd ..
if not exist debug\FXADDINror.bin  goto error

"C:\SDK\Tools\MakeAddinHeader363.exe" "C:\Users\Az\From-Far-Casio-Project\Projet en cours"
if not exist SYSGNRTR.G1A  goto error
echo Build has completed.
goto end

:error
echo Build was not successful.

:end

