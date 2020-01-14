@echo off
set dxdir=%~dp0dxlib
IF /I "%1"=="/dx" (
	cl /I %dxdir% /MT /D_MBCS *.cpp /link /LIBPATH:%dxdir%
) else (
	cl                /D_MBCS *.cpp
)
IF %ERRORLEVEL% NEQ 0 (
	echo ***
	echo Please try with /DX option if using #include"dxlib.h".
	echo ***
) 