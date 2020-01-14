@echo off
set TARG=%~dp0proj\%~n1
IF exist %TARG% (
	cd /d %TARG%
) else (
	cd /d %~dp0
)