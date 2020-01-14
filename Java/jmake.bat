@echo off
set TARG=%~dp0proj\%~1
IF "%1"=="" (
	echo You need file name
) else (
	echo making %TARG%
	md %TARG%
	type nul >%TARG%\%~1.java
	cd %TARG%
)