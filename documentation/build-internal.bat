@echo off
cls

echo expanding library...
msxsl library.xml library.xsl -o _library.xml

echo generating symbol table...
msxsl _library.xml symbol.xsl -o _symbol.xsl

echo initializing registry...
msxsl register.xml register.xsl -o _register.xsl

echo copying support files...
mkdir %1\chaos-pp 2> nul
copy /Y style2.css %1\chaos-pp\style.css > nul
copy /Y background.gif %1\chaos-pp\background.gif > nul

copy /Y x-alpha.gif %1\chaos-pp\x-alpha.gif > nul
copy /Y x-beta.gif %1\chaos-pp\x-beta.gif > nul

echo creating indices...
msxsl _library.xml index.xsl -o %1\chaos-pp\headers.html
msxsl _library.xml index.xsl -m primary -o %1\chaos-pp\macros.html
msxsl _library.xml index.xsl -m secondary -o %1\chaos-pp\master.html

echo generating build script...
msxsl library.xml script.xsl -o _script.bat

echo executing build script...
echo.
call _script.bat %1\chaos-pp

echo.
echo cleaning temporary files...
del _library.xml _symbol.xsl _register.xsl _script.bat
echo done.
