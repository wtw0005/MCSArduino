@echo off
set "octetG=0"
ipconfig | findstr /i "IPv4" > ipfinder.txt
set /p firstline=<ipfinder.txt
set /p %firstline%

echo %firstline%

@echo off
for /f "tokens=1-8 delims=. " %%a in ("%firstline%") do (
set octetA=%%a
set octetB=%%b
set octetC=%%c
set octetD=%%d
set octetE=%%e
set octetF=%%f
set octetG=%%g
set octetH=%%h
)
rem G is third octet aka what school we are at

if %octetG% GEQ 0 if %octetG% LSS 8 set schoolvar=BOE
if %octetG% GEQ 8 if %octetG% LSS 16 set schoolvar=BHS
if %octetG% GEQ 16 if %octetG% LSS 24 set schoolvar=CJHS
if %octetG% GEQ 24 if %octetG% LSS 32 set schoolvar=DNES
if %octetG% GEQ 32 if %octetG% LSS 40 set schoolvar=DHS
if %octetG% GEQ 40 if %octetG% LSS 48 set schoolvar=EJHS
if %octetG% GEQ 48 if %octetG% LSS 56 set schoolvar=FHS
if %octetG% GEQ 56 if %octetG% LSS 64 set schoolvar=LSJHS
if %octetG% GEQ 64 if %octetG% LSS 72 set schoolvar=PES
if %octetG% GEQ 72 if %octetG% LSS 80 set schoolvar=PHS
if %octetG% GEQ 80 if %octetG% LSS 88 set schoolvar=PJHS
if %octetG% GEQ 88 if %octetG% LSS 96 set schoolvar=SJHS
if %octetG% GEQ 96 if %octetG% LSS 104 set schoolvar=WMES
if %octetG% GEQ 104 if %octetG% LSS 112 set schoolvar=WMHS


echo %schoolvar% > schooltemp.txt
schooltemp.txt

pause

	


rem del ipfinder.txt




rem type ipprint.txt|find /i "IPv4 Address"
rem echo %myIP%
rem pause